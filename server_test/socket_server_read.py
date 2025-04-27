import socket
import time

# Set up the server socket
serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
serv.bind(('0.0.0.0', 8080))
serv.listen(5)
print("Server running on port 8080")

while True:
    conn, addr = serv.accept()
    data = conn.recv(1024)
    msg = data.decode('utf-8').strip()
    print(f"From client: {msg}")
    conn.close()
    conn, addr = serv.accept()
