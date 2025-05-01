import socket
import time

class Server:
    def __init__(self):
        self.message = ""

        print("server initialiseret")
        self.serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.serv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.serv.bind(('0.0.0.0', 8080))
        self.serv.listen(5)

        print("Server running on port 8080")

    def update_massega(self, message:str):
        self.message = message
    
    def send(self):
        while True:
            print("Waiting for client...")
            conn, addr = self.serv.accept()
            print(f"Client connected from {addr}")

            while True:
                try:
                    data = conn.recv(1024)
                    if not data:
                        print("Client disconnected unexpectedly.")

                    msg = data.decode('utf-8').strip()
                    print(f"From client: {msg}")

                    if msg == "101":
                        # Send current message
                        conn.sendall((self.message + '\n').encode())
                        print(f"Sent message: {self.message}")
                        time.sleep(0.1)  # Small delay to give client time to read the response

                    elif msg == "102":
                        print("Received 102, closing connection.")
                        break

                    else:
                        print("Unknown message. Ignoring.")

                except Exception as e:
                    print(f"Error: {e}")
                    conn.close()
                    conn, addr = self.serv.accept()

            conn.close()
            print("Connection closed.\n")

