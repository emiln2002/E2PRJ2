from UI_package import Menu
from server_package import Server
import os
import threading


menu = Menu()

myserver = Server()

myserver.set_massege("on")

t1 = threading.Thread(target=myserver.send, args=())
t1.start()

while True:
    os.system('clear')
    menu.main_menu()
    x = input("Indtast valg: ")
    if x == "x":
        myserver.setLog(False)
        os.system('clear')
        menu.main_menu()
    elif x == "1":
        menu.toggle_mode()
        os.system('clear')
        menu.main_menu()

# ----------------------styr lys manuelt----------------------
    elif x == "2":
        while True:
            os.system('clear')
            menu.manuelt_menu()
            x = input("Indtast valg: ")
            if x == "x": break
            elif x == "1": myserver.set_massege("on")
            elif x == "2": myserver.set_massege("off")

# ----------------------styr lys auto-------------------------
    elif x == "3":
        while True:
            os.system('clear')
            menu.auto_menu()
            x = input("Indtast valg: ")
            if x == "x": break
   
# ----------------------Vis data -----------------------------
    elif x == "4":
        while True:
            os.system('clear')
            menu.data_menu()
            x = input("Indtast valg: ")
            if x == "x": break
            

# ----------------------Server log----------------------------
    elif x == "5":
        os.system('clear')
        myserver.setLog(True)
    
    
    



