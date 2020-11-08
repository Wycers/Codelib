import socket

server_address = ('httpbin.org', 80)
message  = b'GET / HTTP/1.1\r\n'
message += b'Host: httpbin.org:80\r\n'
message += b'Connection: close\r\n'
message += b'\r\n'

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(server_address)
sock.sendall(message)

data = b''
while True:
    buf = sock.recv(1024)
    if not buf:
        break
    data += buf

sock.close()
print(data.decode())
