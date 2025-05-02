import socket
import time

class Server:
    def __init__(self):
        self.message = ""
        self.log = False

        if self.log: print("server initialiseret")
        self.serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.serv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.serv.bind(('0.0.0.0', 8081))
        self.serv.listen(5)

        if self.log: print("Server running on port 8080")

    def set_massege(self, message:str):
        self.message = message
    
    def setLog(self, bo:bool):
        self.log = bo
    
    def send(self):
        while True:
            if self.log: print("Waiting for client...")
            conn, addr = self.serv.accept()
            if self.log: print(f"Client connected from {addr}")

            while True:
                try:
                    data = conn.recv(1024)
                    if not data:
                        if self.log: print("Client disconnected unexpectedly.")

                    msg = data.decode('utf-8').strip()
                    if self.log: print(f"From client: {msg}")

                    if msg == "101":
                        # Send current message
                        conn.sendall((self.message + '\n').encode())
                        if self.log: print(f"Sent message: {self.message}")
                        time.sleep(0.1)  # Small delay to give client time to read the response

                    elif msg == "102":
                        if self.log: print("Received 102, closing connection.")
                        break

                    else:
                        if self.log: print("Unknown message. Ignoring.")

                except Exception as e:
                    if self.log: print(f"Error: {e}")
                    conn.close()
                    conn, addr = self.serv.accept()

            conn.close()
            if self.log: print("Connection closed.\n")

