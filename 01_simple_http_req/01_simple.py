import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(("172.217.31.142", 80)) #// ping google.com

test_msg = "GET /\n"
sock.send(test_msg.encode())
sock.send(bytes(0))

data = sock.recv(1024*10)
print(data.decode('utf-8'))

sock.close()
