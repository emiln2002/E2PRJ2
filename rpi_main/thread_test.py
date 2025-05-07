import threading
import time
state = True

def loop():
    i = 0
    while state:
        print(i)
        i += 1
        time.sleep(1)



t1 = threading.Thread(target=loop, args=())
t1.start()

x = input()
if x == '1':
    state = False
