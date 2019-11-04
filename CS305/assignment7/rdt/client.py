from rdt import socket
import time

text = 'wdnmd'

if __name__ == '__main__':
    client = socket()
    client.connect(('127.0.0.1', 2333))
    time.sleep(0.5)
    client.send(text.encode('utf-8'))
    data = client.recv(2048)
    assert data == text.encode('utf-8')
    client.close()
