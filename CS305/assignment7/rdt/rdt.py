from udp import UDPsocket  # import provided class
from enum import Enum, unique

SYN = 0b0100
FIN = 0b0010
ACK = 0b0001

class FSM(object):
    def __init__(self):
        pass


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
            self._seq_ack = seq_ack
            self._set_header(5, self._seq_ack.to_bytes(4, 'big'))
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
        tmp = self._header + self._payload
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
        pass

    # For PAYLOAD
    @property
    def payload(self):
        return self._payload

    @payload.setter
    def payload(self, payload):
        if type(payload) == bytes:
            self._length = len(payload)
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
        return self._header + self._payload

    def __call__(self):
        return self._encode()

    def __repr__(self):
        try:
            res = "Type:\t{}\nSeq:\t{}\nSEQ_ACK:\t{}\nLENGTH:\t{}\nChecksum:\t{}".format(
                self.dtype, self.seq, self.seq_ack, self.length, self.checksum)
            return res
        except Exception as e:
            print(e)
            return "Invalid"


class socket(UDPsocket):
    def __init__(self, ):
        super().__init__()

    def connect(self, sock):
        print('connect')
        # send syn;
        req = datagram()
        req.dtype = SYN
        self.sendto(req(), sock)

        # receive syn, ack;
        data, addr = super().recvfrom(2048)
        res = datagram(data)
        if res.dtype == SYN + ACK and res.seq == 1:
            # send ack
            req = datagram()
            req.dtype = ACK
            self.sendto(req(), sock)

            self.server = sock
        else:
            raise Exception("Failed to connect to server")

    def accept(self):
        while True:
            try:
                # Recieve data
                data, addr = self.recvfrom(2048)
                # Data is SYN, response SYN + ACK
                res = datagram(data)
                if res.dtype & SYN:
                    req = datagram()
                    req.dtype = SYN + ACK
                    req.seq = res.seq + 1
                    self.sendto(req(), addr)
                else:
                    continue

                # Data is ACK
                data, addr = self.recvfrom(2048)
                res = datagram(data)
                if res.dtype & ACK:
                    print('Success!')
                    return socket(), addr
                else:
                    continue

            except Exception as e:
                continue


    def close(self):
        # send fin; receive ack; receive fin; send ack
        # your code here
        pass

    def recv(self, bufsize: int):
        print('?')
        while True:
            print('wait data')
            try:
                data, addr = self.recvfrom(bufsize)
                print(data)
                # data = datagram()
                # data.dtype = ACK
                # self.sendto(data(), addr)
                # return data
            except Exception as e:
                print(e)
                continue

    def send(self, content: bytes):
        data = datagram()
        data.payload = content
        while True:
            print(self.server)
            self.sendto(data(), self.server)
            print('sending', data())
            try:
                data, addr = self.recvfrom(2048)
                print(data)
                return
            except Exception as e:
                print(e)
                continue
