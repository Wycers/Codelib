from rdt import socket
import time
server = socket()
server.bind(('127.0.0.1', 2333))

# conn, client = server.accept()
data = server.recv(2048)
print(data)
data = server.recv(2048)
print(data)

with open('alice~.txt', 'w') as f:
    f.write(server.recv(2048).decode('utf-8'))

