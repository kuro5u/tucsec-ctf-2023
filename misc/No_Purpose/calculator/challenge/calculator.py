import socket

# TODO: Make accessible only by the bot

def handle_connection(conn):
    env = {'__builtins__': {}, 'subprocess': __import__('subprocess')}

    conn.send(b"> ")

    try:
        expr = conn.recv(1024).decode()
        result = f"Result: ```{eval(expr, env)}```"
        conn.send(result.encode())

    except Exception as e:
        error_message = f"Error: {e}"
        conn.send(error_message.encode())

    conn.close()


server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('0.0.0.0', 1338))
server_socket.listen(1)

while True:
    conn, addr = server_socket.accept()
    handle_connection(conn)
