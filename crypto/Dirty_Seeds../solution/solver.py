from pwn import *
import random
import time

context.encoding = 'ascii'

IP = "127.0.0.1"
PORT = 1337

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


def main():

    while True:
        io = remote(IP, PORT, level='error')

        current_time = int(time.time())

        seed = current_time + randint(1, 5)
        random.seed(seed)

        key = generate_key()

        try:
            io.sendafter("> ", key)
            log.success(io.recvline_contains(b"TUC{").decode())
            io.close()
            break
        except:
            io.close()


if __name__ == "__main__":
    main()
