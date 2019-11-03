from udp import UDPsocket  # import provided class
from enum import Enum, unique


@unique
class datagram_type(Enum):
    SYN = 0b100
    FIN = 0b010
    ACK = 0b001

class datagram(object):
    def __init__(self):
        self.type = datagram_type




class socket(UDPsocket):
    def __init__(self):
        super(socket, self).__init__()

    def connect(self):
        print('connect')
        # send syn; receive syn, ack; send ack
        # your code here
        pass

    def accept(self):
        pass
        # while True:
        #     if
        # conn =
        # # receive syn; send syn, ack; receive ack
        # # your code here
        # return conn, client

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

    def calc_checksum(self, payload):
        sum = 0
        for byte in payload:
            sum += byte
            sum = -(sum % 256)
        return (sum & 0xFF)
