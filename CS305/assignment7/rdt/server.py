from rdt import socket
import time
server = socket()
server.bind(('127.0.0.1', 2333))

conn, client = server.accept()
data = server.recv(2048)
print(data)
data = server.recv(2048)
print(data)
if data:
    server.send(data)
    server.close()
