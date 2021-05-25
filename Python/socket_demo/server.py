import zmq

context = zmq.Context()
socket = context.socket(zmq.STREAM)

socket.bind("tcp://*:50000")

id = socket.recv()
print('id1 {}'.format(id))
message = socket.recv()  # empty data here
print("received:" + str(message))

for i in range(100):
    id = socket.recv()
    print('id2 {}'.format(id))
    message = socket.recv()
    print("received:" + str(message))
    socket.send(id, zmq.SNDMORE)
    socket.send(bytes("Yes {}".format(i), 'utf-8'))
