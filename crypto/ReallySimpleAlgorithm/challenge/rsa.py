#!/usr/bin/python

from Crypto.Util.number import bytes_to_long, getPrime
from tucsecrets import FLAG

m = bytes_to_long(FLAG)

e = 65537

p = getPrime(1024)
q = getPrime(1024)
r = getPrime(1024)

n1 = p * q
n2 = (n1 // p) * r

c = pow(m, e, n2)

with open('ciphertext.txt', 'w') as file:
    file.write(f'n1: {n1}\n')
    file.write(f'n2: {n2}\n')
    file.write(f'c: {c}\n')
