import random
import time
import socketserver
import select
from math import floor

FLAG = b"TUC{d4_t1ng_g03s_5krrrRR4T!}"


def banner(conn):
    conn.send(b"Yo, welcome to Quick Maffs fam!\n\n")
    conn.send(b"[ Rules ]\n")
    conn.send(b"1. Man's rounding down them decimal results, you get me?\n")
    conn.send(b"2. You got 3 seconds to drop them answers (Ya ya, we're being kinda lenient, ya know?)\n")
    conn.send(b"3. You gotta get them right 100 times in a row to claim your prize, innit?\n")
    conn.send(b"4. Just have some fun, you know how it is! Boom.\n")

    time.sleep(5)
    conn.send(b"\nOkay, ready fam?\n")
    time.sleep(1)
    conn.send(b"Skrrat! Peng! Let's go. Boom.\n")
    time.sleep(1)

def generate_equation():
    operators = ['+', '-', '*', '/', '%']

    num1 = random.randint(10**9, 10**14)
    num2 = random.randint(10**9, 10**14)
    num3 = random.randint(10**9, 10**14)

    op1 = random.choice(operators)
    op2 = random.choice(operators)

    equation = f"{num1} {op1} {num2} {op2} {num3}"

    return equation


def challenge(conn):

    banner(conn)

    correct = [b"Mad skills, fam!", b"Correct, you're peng!", b"You're on fire!", b"Skrrat, nailed it!", b"Big up, genius!"]
    wrong = [b"Nah, bruv, focus!", b"Oops, try again!", b"Not quite, mate!", b"Close, not there!", b"Skrra, pay attention!"]
    user_input = 0

    for _ in range(100):
        equation = generate_equation()
        conn.send(b'\nEquation: ' + equation.encode() + b' = ?\n')

        result = floor(eval(equation))
        # print(result)

        try:
            conn.send(b"> ")
            conn.setblocking(0)
            ready = select.select([conn], [], [], 3)
            if ready[0]:
                user_input = int(conn.recv(1024).decode())
            else:
                conn.send(b"Nahh, too slow bruv!\n")
                conn.close()
                return
        except:
            # conn.send(random.choice(wrong) + b'\n')
            conn.close()
            return

        if user_input != result:
            conn.send(random.choice(wrong) + b'\n')
            conn.close()
            return
        else:
            conn.send(random.choice(correct) + b'\n')
            continue

    conn.send(b"\nBoom! Mad respect, fam! You're scripting Python like a true genius. Skrrat, skidi-kat-kat, code master in the building! You know da ting!\n\n")
    conn.send(FLAG)
    conn.close()
    return


def main():
    socketserver.TCPServer.allow_reuse_address = True
    server = ThreadingTCPServer(("0.0.0.0", 1337), MyTCPRequestHandler)
    server.serve_forever()


class MyTCPRequestHandler(socketserver.BaseRequestHandler):
    def handle(self):
        global req
        req = self.request
        challenge(req)


class ThreadingTCPServer(socketserver.ThreadingMixIn, socketserver.TCPServer):
    pass


if __name__ == "__main__":
    main()
