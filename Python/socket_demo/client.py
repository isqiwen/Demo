import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('localhost', 50000))
for i in range(100):
    s.send(bytes('Hello, world {}'.format(i), 'utf-8'))
    data1 = s.recv(1024)
    print('Received', repr(data1))

s.close()
