import socket
serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv.bind(('0.0.0.0', 8080))
print("Server running")
serv.listen(5)
while True:
  conn, addr = serv.accept()
  from_client = ''
  while True:
    data = conn.recv(4096)
    if not data: break
    from_client += data.decode('utf8')
    print (f'From client: {from_client}')
    conn.send("5".encode())
    
  conn.close()
print ('client disconnected and shutdown')
