#!/usr/bin/python

import os
from tucsecrets import FLAG

class XOR:
    def __init__(self):
        self.key = os.urandom(4)

    def encrypt(self, data):
        xored_data = ""

        for i in range(len(data)):
            xored_data += (data[i] ^ self.key[i % len(self.key)]).to_bytes().hex()

        return xored_data


def main():
    xor = XOR()

    with open("enc_flag.txt", "w") as f:
        f.write(f"flag: {xor.encrypt(FLAG)}")


if __name__ == '__main__':
    main()
