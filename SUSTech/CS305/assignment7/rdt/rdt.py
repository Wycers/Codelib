from udp import UDPsocket, timeout  # import provided class
from enum import Enum, unique
import logging

logging.basicConfig(level=logging.INFO,
                    format='%(asctime)s - %(filename)s[line:%(lineno)d] - %(levelname)s: %(message)s')

WINDOWS_SIZE = 8
MAX_LENGTH = 1024
MAX_TIMEOUT_RETRY = 5

SYN = 0b0100
FIN = 0b0010
ACK = 0b0001


@unique
class STATE(Enum):
    OPENED = 0
    LISTENING = 1
    CONNECTING = 2
    CONNECTED = 3
    CLOSING = 4
    CLOSED = 5


@unique
class EVENT(Enum):
    bind = 0
    listen = 1
    accept = 2
    connect_requested = 3
    connect = 4
    close_requested = 5
    close = 6


class FSM(object):
    """
    FSM, but it is useless for connectionless rdt
    """
    def __init__(self, state=None):
        self._current = None
        if type(state) == STATE:
            self._current = state
        elif type(state) == int:
            self._current = STATE(state)
        elif state is None:
            self._current = STATE.OPENED
        else:
            raise ValueError("Invalid state")

    @property
    def current(self):
        return self._current

    @current.setter
    def current(self, current: STATE):
        self._current = current
        logging.info('Change From %s to %s', self._current, current)

    def dispatch(self, event: str):
        if self._current == STATE.OPENED:
            if event == EVENT.bind:
                self._current = STATE.LISTENING
            elif event == EVENT.listen:
                self._current = STATE.LISTENING
            elif event == EVENT.connect:
                self._current = STATE.CONNECTED
            else:
                raise ValueError("Invalid event")
        elif self._current == STATE.LISTENING:
            if event == EVENT.connect_requested:
                self._current = STATE.CONNECTING
            else:
                raise ValueError("Invalid event")
        elif self._current == STATE.CONNECTING:
            if event == EVENT.accept:
                self._current = STATE.CONNECTED
            else:
                raise ValueError("Invalid event")
        elif self._current == STATE.CONNECTED:
            if event == EVENT.close_requested:
                self._current = STATE.CLOSING
            elif event == EVENT.close:
                self._current = STATE.CLOSED
            else:
                raise ValueError("Invalid event")
        elif self._current == STATE.CLOSING:
            if event == EVENT.close:
                self._current = STATE.CLOSED
            else:
                raise ValueError("Invalid event")
        else:
            logging.warning("Nothing to do")


class datagram(object):
    def _set_header(self, offset, value):
        tmp = list(self._header)
        for index, byte in enumerate(value):
            tmp[offset + index] = byte
        self._header = bytes(tmp)

    # For datagram type
    @property
    def dtype(self) -> int:
        return self._dtype

    @dtype.setter
    def dtype(self, dtype: int):
        self._dtype = dtype
        self._set_header(0, self._dtype.to_bytes(1, 'big'))

    # For Seq
    @property
    def seq(self):
        return int.from_bytes(self._seq, 'big')

    @seq.setter
    def seq(self, seq):
        if type(seq) == int:
            self._seq = seq.to_bytes(4, 'big')
            self._set_header(1, self._seq)
        else:
            raise ValueError("Seq number must be an integer")

    # For SEQ_ACK
    @property
    def seq_ack(self):
        return int.from_bytes(self._seq_ack, 'big')

    @seq_ack.setter
    def seq_ack(self, seq_ack):
        if type(seq_ack) == int:
            self._seq_ack = seq_ack.to_bytes(4, 'big')
            self._set_header(5, self._seq_ack)
        else:
            raise ValueError("SEQ_ACK number must be an integer")

   # For LEN
    @property
    def length(self):
        return int.from_bytes(self._length, 'big')

    @length.setter
    def length(self, length):
        raise NotImplementedError("Length cannot be set.")

    # For CHECKSUM
    @property
    def checksum(self):
        tmp = self._header[0:13] + b'\x00\x00' + self._payload
        sum = 0
        for byte in tmp:
            sum += byte
            sum = -(sum % 256)
        return (sum & 0xFF)

    @checksum.setter
    def checksum(self, checksum):
        raise NotImplementedError("Checksum cannot be set.")

    @property
    def valid(self):
        return self.checksum == int.from_bytes(self._checksum, 'big')

    # For PAYLOAD
    @property
    def payload(self):
        return self._payload

    @payload.setter
    def payload(self, payload):
        if type(payload) == bytes:
            self._length = len(payload).to_bytes(4, 'big')
            self._set_header(9, self._length)
            self._payload = payload
        else:
            raise TypeError("a bytes-like object is expected")

    def __init__(self, raw_data=None):
        if type(raw_data) == bytes:
            self._decode(raw_data)
        else:
            self._header = bytes(15)
            self._dtype = 0
            self._seq = bytes(4)
            self._seq_ack = bytes(4)
            self._length = bytes(4)
            self._checksum = bytes(2)
            self._payload = b''

    def _decode(self, raw_data: bytes):
        if len(raw_data) < 15:
            raise ValueError("Invalid data!")
        self._header = raw_data[0:15]
        self._dtype = self._header[0]
        self._seq = self._header[1: 5]
        self._seq_ack = self._header[5: 9]
        self._length = self._header[9: 13]
        self._checksum = self._header[13: 15]

        self._payload = raw_data[15:]

    def _encode(self):
        self._set_header(13, self.checksum.to_bytes(2, 'big'))
        return self._header + self._payload

    def __call__(self):
        return self._encode()

    def __str__(self):
        return self.__repr__()

    def __repr__(self):
        try:
            res = "Type:\t{}\nSeq:\t{}\nSEQ_ACK:\t{}\nLENGTH:\t{}\nChecksum:\t{}\nPayload:\t{}".format(
                self.dtype, self.seq, self.seq_ack, self.length, self.checksum, self.payload)
            return res
        except Exception:
            return "Invalid"


class socket(UDPsocket):
    def __init__(self, ):
        super().__init__()
        self.state = FSM(STATE.OPENED)

        self.seq = 0
        self.seq_ack = 0

    def bind(self, addr):
        self.state.dispatch(EVENT.bind)
        super().bind(addr)

    def accept(self):
        print("Accept is not implemented for connectionless rdt")
        raise NotImplementedError

    def connect(self, addr):
        self.to = addr

    def close(self):
        print("Close is not implemented for connectionless ")
        raise NotImplementedError

    def recvfrom(self, bufsize=2048):
        QvQ = super().recvfrom(bufsize)
        if QvQ is None:
            raise timeout

        data, addr = QvQ
        data = datagram(data)
        if data.valid:
            return data, addr
        raise Exception("Invalid packet")

    def recv(self, bufsize: int):
        rcvd_data = b''
        timeout_count = -1
        expected = self.seq_ack

        ack = datagram()

        logging.info('ready to receive...')
        while True:
            try:
                data, addr = self.recvfrom(bufsize)

                logging.debug('received raw segment')
                timeout_count = 0  # no timeout, reset

                logging.info('expected: #%d, received: #%d', expected, data.seq)
                if data.seq == expected:
                    if data.dtype & FIN:
                        logging.info('FIN Recieved')
                        break
                    else:
                        rcvd_data += data.payload
                    expected += data.length
                ack.seq = self.seq
                ack.seq_ack = expected
                super().sendto(ack(), addr)
            except timeout:
                if timeout_count < 0:
                    continue
                timeout_count += 1
                logging.info('timed out, count=%d', timeout_count)
                if timeout_count > MAX_TIMEOUT_RETRY:
                    raise ConnectionAbortedError('timed out')
            except ValueError:
                ack.seq = self.seq
                ack.seq_ack = expected
                super().sendto(ack(), addr)
            except Exception as e:
                logging.warning(e)

        self.seq += 1
        self.seq_ack = expected + 1

        fin_ack = datagram()
        fin_ack.dtype |= FIN
        fin_ack.dtype |= ACK
        fin_ack.seq = self.seq
        fin_ack.seq_ack = self.seq_ack
        fin_err_count = 0
        self.sendto(fin_ack(), addr)

        # self.seq_ack = expected + 1

        logging.info('----------- receipt finished -----------')
        return rcvd_data

    def send(self, content: bytes, reciver_addr):
        # So grass...
        base = self.seq

        timeout_count = 0
        l, r = 0, 0
        while l < len(content):
            r = min(len(content), l + WINDOWS_SIZE * MAX_LENGTH)

            # Calculate all the bytes need to send
            buffer = list(range(l, r, MAX_LENGTH))
            for i in buffer:
                chunk_len = min(MAX_LENGTH, len(content) - i)
                data = datagram()
                data.payload = content[i:i+chunk_len]
                data.seq = base + i
                data.seq_ack = self.seq_ack
                self.sendto(data(), reciver_addr)
            logging.info('Send packet from [%d, %d]' % (buffer[0], buffer[-1]))

            while True:
                try:
                    # assumption: no truncated packets
                    data, addr = self.recvfrom(2048)

                    timeout_count = 0  # no error, reset counter

                    logging.info('#%d acked', data.seq_ack)

                    # cumulative ack, it should be in the window
                    assert buffer[0] <= data.seq_ack - base <= buffer[-1] + MAX_LENGTH + 1

                    l = max(l, data.seq_ack - base)

                    # all acked
                    if r - l == 0:
                        logging.info('Finish sending')
                        break
                except ValueError:
                    logging.info('corrupted ack, ignored')
                except AssertionError:
                    logging.info(
                        'duplicate ack or unexpected segment received')
                except timeout:
                    timeout_count += 1
                    logging.info('timed out, count=%d', timeout_count)
                    if timeout_count > MAX_TIMEOUT_RETRY:
                        raise ConnectionError('timed out')
                    break
                except Exception as e:
                    logging.warning(e)

        # Finish, send FIN
        fin = datagram()
        fin.dtype |= FIN
        fin.seq = base + len(content)
        fin.seq_ack = self.seq_ack
        fin_err_count = 0
        while True:
            try:
                self.sendto(fin(), reciver_addr)
                data, addr = self.recvfrom(2048)

                if data.dtype & ACK and data.dtype & FIN and data.seq_ack == base + len(content) + 1:
                    break
            except (timeout, ValueError):
                fin_err_count += 1
                if fin_err_count > MAX_TIMEOUT_RETRY:
                    break
            except Exception as e:
                logging.warning(e)

        self.seq = base + len(content) + 1
        logging.info('----------- all sent -----------')
