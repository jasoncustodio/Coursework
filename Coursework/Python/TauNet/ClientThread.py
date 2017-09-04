#Copyright (c) Jason Custodio 2015

import socket
import RC4
import csv

def client(conn):
    while True:
        reply = input("\nSEND: ")
        if reply == "exit":
            break
        reply = "\nversion: 0.2" + "\r\nfrom: Jason" + "\r\nto: Friend" + "\r\n" + "\r\n" + reply
        reply = RC4.secret(reply)
        conn.send(reply)
    print("[DISCONNECTED]")
    conn.close()

print("\n[USERNAME]        [HOST ADDRESS]        [PORT]")
with open('TauNet User and Hostnames - User and Hostnames.csv') as csvfile:
    readCSV = csv.reader(csvfile, delimiter=',')
    for row in readCSV:
        print(row)

print("\nINPUT BY HOST ADDRESS(1) OR IP(2)?")
choice = input("\nINPUT: ")
if choice == 1:
    host = socket.gethostbyname(input("\nINPUT HOST ADDRESS: "))
else:
    host = input("\nINPUT IP: ")

port = 6283

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    s.connect((host, port))
except socket.error as e:
    print(str(e))


print("CONNECTED TO: " + host + " " + str(port))

client(s)
