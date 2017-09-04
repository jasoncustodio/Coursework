#Copyright (c) Jason Custodio 2015

import random

def IV():
    array = [random.randint(0, 255) for i in range(10)]     #Create random int array
    return array

def rc4(nLength, round = 20, password = "password"):
    keyLength = len(password)                               #Length of key
    S = bytearray(range(256))                               #Zero based array of 256 bytes

    for j in range(round):                                  #20 rounds key generation
        for i in range(256):
            j = (j + S[i] + password[i % keyLength]) % 256
            S[i], S[j] = S[j], S[i]                         #Swap bytes

    j = 0
    stream = [b'0']*nLength                                 #Zero byte array of message length
    for i in range(nLength):
        m = (i+1) % 256
        j = (j+S[m]) % 256
        S[m], S[j] = S[j], S[m]                             #Swap bytes
        stream[i] = S[(S[m] + S[j]) % 256]

    return bytearray(stream)

def encrypt(message, round = 20, password = "password"):
    nLength = len(message)                                #Message length
    iv = IV()                                             #10 byte IV
    combine = [ord(password[i]) for i in range(len(password)-1)] #Convert to int array
    key = []
    key[:10], key[10:] = combine, iv                      #Concatenate message with IV
    stream = rc4(nLength, round, key)

    cipher = [b'0']*(nLength+10)                          #Zero based byte array
    for i in range(10):
        cipher[i] = iv[i]

    for i in range(nLength):
        cipher[i+10] = message[i] ^ stream[i]             #XOR Bytes

    return cipher

def decrypt(message, round = 20, password = "password"):
    nLength = len(message)                                #Message length
    iv = message[0:10]                                    #Hold first 10 bytes
    message = message[10:]                                #Hold everything after 10 bytes
    combine = [ord(password[i]) for i in range(len(password)-1)] #Convert to int array
    key = []
    key[:10], key[10:] = combine, iv                      #Concatanate message with IV
    stream = rc4(nLength-10, round, key)

    output = [b'0']*(nLength-10)                          #Zero based byte array
    for i in range(nLength-10):
        output[i] = message[i] ^ stream[i]                #XOR Bytes

    return output

def secret(message):
    return bytes(encrypt([ord(message[i]) for i in range(len(message))]))

def getMessage(x):
    m = ''
    x = [chr(x[i]) for i in range(len(x))]
    for i in range (len(x)):
        m += x[i]
    return m

def test():
    m = ''
    message = input("Input: ")
    x = secret(message)
    y = decrypt(x)
    m = getMessage(y)

    print("Received:", m)

if __name__ == '__main__':
    test()
