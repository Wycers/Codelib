from udp import UDPsocket  # import provided class
from enum import Enum, unique


@unique
class datagram_type(Enum):
    SYN = 0b0100
    FIN = 0b0010
    ACK = 0b0001

class datagram(object):
    def _set(self, offset, value):
        for index, byte in enumerate(value):
            self._header[offset + index] = byte

    # For datagram type
    @property
    def dtype(self):
        return self._dtype

    @dtype.setter
    def dtype(self, dtype):
        if type(dtype) == datagram_type:
            self._dtype = dtype
        else:
            self._dtype = datagram_type(dtype)
        self._set(0, self.type.value.to_bytes(1, 'big'))

    # For Seq
    @property
    def seq(self):
        return self._seq

    @seq.setter
    def seq(self, seq):
        if type(seq) == int:
            self._seq = seq
            self._set(1, self.seq.to_bytes(4, 'big'))
        else:
            raise ValueError("Seq number must be an integer")

    # For SEQ_ACK
    @property
    def sqe_ack(self):
        return self._sqe_ack

    @sqe_ack.setter
    def sqe_ack(self, sqe_ack):
        if type(sqe_ack) == int:
            self._sqe_ack = sqe_ack
            self._set(1, self.seq_ack.to_bytes(4, 'big'))
        else:
            raise ValueError("SEQ_ACK number must be an integer")

   # For LEN
    @property
    def length(self):
        return self._length

    @length.setter
    def length(self, length):
        raise NotImplementedError("Length cannot be set.")

   # For CHECKSUM
    @property
    def checksum(self):
        tmp = _header + _payload
        sum = 0
        for byte in tmp:
            sum += byte
            sum = -(sum % 256)
        return (sum & 0xFF)

    @checksum.setter
    def checksum(self, checksum):
        raise NotImplementedError("Checksum cannot be set.")


    def __init__(self, type=None):
        self._header = bytes(15)
        self._payload = b''

    @classmethod
    def decode(cls, raw_data):
        print(raw_data)

    def encode(self):
        pass

    def checksum(self, payload):

class socket(UDPsocket):
    def __init__(self):
        super().__init__()

    def connect(self, sock):
        print('connect')
        # send syn;
        data = datagram(datagram_type.SYN)
        self.sendto(data.encode(), sock)

        # receive syn, ack;
        data, addr = super().recvfrom(2048)
        print(data)

        # send ack
        # your code here

    def accept(self):
        while True:
            try:
                data, addr = super().recvfrom(2048)
            except Exception as e:
                continue

            dg = datagram.decode(data)


    def close(self):
        # send fin; receive ack; receive fin; send ack
        # your code here
        pass

    def recv(self):
        # your code here
        pass

    def send(self):
        # your code here
        pass

