from rdt import socket
import time

text1 = 'wdnmdwsma'

text2 = 'abcdefsgasdasd'

if __name__ == '__main__':
    client = socket()
    client.send(text1.encode('utf-8'), ('127.0.0.1', 2333))
    client.send(text2.encode('utf-8'), ('127.0.0.1', 2333))
    with open('alice.txt') as f:
        client.send(f.read().encode('utf-8'), ('127.0.0.1', 2333))
    # data = client.recv(2048)
    # print(data)
    # assert data == text.encode('utf-8')
    # client.close()
