#Copyright (c) Jason Custodio 2015

import socket
import RC4
from _thread import *

def threaded_client(conn):
    while True:
        data = conn.recv(1024)
        if not data:
            break
        x = RC4.decrypt(data)
        m = RC4.getMessage(x)
        print("\nRECEIVED: ", m)
        if not data:
            break
    conn.close()

host = ''
port = 6283

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    s.bind((host, port))
except socket.error as e:
    print(str(e))

s.listen(1)
print("\n***SERVER***\n[AWAITING CONNECTION]")

while True:
    conn, addr = s.accept()
    print("CONNECTION FROM: ", addr)

    try:
        start_new_thread(threaded_client, (conn, ))
    except Exception as e:
        print(str(e))
