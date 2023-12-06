#!/usr/bin/env python3

import random
import time
import socketserver

class MyTCPRequestHandler(socketserver.BaseRequestHandler):
    def handle(self):
        global req
        req = self.request
        challenge(req)


class ThreadingTCPServer(socketserver.ThreadingMixIn, socketserver.TCPServer):
    pass


def get_flag() -> str:
    with open("flag.txt", "r") as f:
        flag = f.readline()
        f.close()

    return flag


def generate_key() -> str:
    key = []
    for _ in range(20):
        c = 0

        while c <= 32:
            r = random.randint(1, 1000)
            c = (r % 127)
        key += chr(c)

    key = ''.join(key)

    return key


def challenge(conn):
    seed = int(time.time()) + random.randint(1, 5)
    random.seed(seed)

    key = generate_key()

    conn.send(b"Can you guess my secret key?\n")
    conn.send(b"> ")
    try:
        guess = conn.recv(1024).decode()
    except:
        conn.close()
        return

    if guess == key:
        conn.send(b"\nI can't believe how lucky you are:\n")
        conn.send(get_flag().encode() + b"\n")
    else:
        conn.send(b"\nThat was sad.\n")

    conn.close()


def main():
    socketserver.TCPServer.allow_reuse_address = True
    server = ThreadingTCPServer(("0.0.0.0", 1337), MyTCPRequestHandler)
    server.serve_forever()


if __name__ == "__main__":
    main()
