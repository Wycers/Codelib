from rdt import socket
import time
server = socket()
server.bind(('127.0.0.1', 2333))
while True:
    conn, client = server.accept()
    while True:
        data = conn.recv(2048)
        if not data:
            break
        conn.send(data)
        conn.close()
