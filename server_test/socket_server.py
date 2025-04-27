import socket
import time

# Set up the server socket
serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
serv.bind(('0.0.0.0', 8080))
serv.listen(5)

print("Server running on port 8080")
state = input("Initial state to send (e.g., on/off): ").strip()


while True:
  print("Waiting for client...")
  conn, addr = serv.accept()
  print(f"Client connected from {addr}")

  while True:
    try:
      data = conn.recv(1024)
      if not data:
        print("Client disconnected unexpectedly.")

      msg = data.decode('utf-8').strip()
      print(f"From client: {msg}")

      if msg == "101":
        # Send current state
        conn.sendall((state + '\n').encode())
        print(f"Sent state: {state}")
        time.sleep(0.1)  # Small delay to give client time to read the response

      elif msg == "102":
        print("Received 102, closing connection.")
        break

      else:
        print("Unknown message. Ignoring.")

    except Exception as e:
      print(f"Error: {e}")
      conn.close()
      conn, addr = serv.accept()

  # finally:
  conn.close()
  print("Connection closed.\n")

  # Optional: allow changing state between clients
  new_state = input("Update state to send (or press enter to keep): ").strip()
  if new_state:
      state = new_state



