#!/usr/bin/python

from pwn import *
from math import floor

context.encoding = 'ascii'

IP = "127.0.0.1"
PORT = 1337


def pwn():
    io = remote(IP, PORT)

    for _ in range(100):
        io.recvuntil("Equation: ")
        equation = io.recvline()[:-5]
        result = floor(eval(equation))
        io.sendlineafter("> ", str(result))

    io.interactive()
    pause()


if __name__ == "__main__":
    pwn()
