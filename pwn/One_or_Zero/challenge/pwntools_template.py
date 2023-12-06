#!/usr/bin/python
from pwn import *

elf = context.binary = ELF("./main", checksec=False)
context.encoding = 'ascii'

gs = \
'''
'''

IP = ""
PORT = -1


def start(logging='notset'):
    if args.GDB:
        return gdb.debug(elf.path, gdbscript=gs)
    elif args.REMOTE:
        return remote(IP, PORT, level=logging)
    else:
        return process(elf.path, level=logging)


def pwn():
    io = start()
    
    # ----------------- #
    # EXPLOIT GOES HERE #
    # ----------------- #

    # Receive data: 
    # io.recv(8)
    # io.recvline()
    # io.recvuntil("> ")

    # Send data:
    # io.sendlineafter("> ", data)

    io.interactive()
    pause()


if __name__ == "__main__":
    pwn()
