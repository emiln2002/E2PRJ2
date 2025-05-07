from UI_package import Menu
from server_package import Server
import os
import threading

menu = Menu()

lys_server = Server(8084)
gardin_server = Server(8085)
sensor_server = Server(8086)


threading.Thread(target=lys_server.run, args=()).start()
threading.Thread(target=gardin_server.run, args=()).start()
threading.Thread(target=sensor_server.run, args=()).start()


def run_mode():
    while menu.mode == "Auto":
        lys_server.set_massege(sensor_server.recieve)
        if gardin_server.recieve > 50:
            gardin_server.set_massege("1")
        else: gardin_server.set_massege("0")
        print("running")
        
threading.Thread(target=run_mode, args=()).start()

while True:
    os.system('clear')
    menu.main_menu()
    x = input("Indtast valg: ")
    if x == "x":
        lys_server.setLog(False)
        gardin_server.setLog(False)
        sensor_server.setLog(False)
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
            menu.manuelt_menu(lys_server.message, gardin_server.message)
            x = input("Indtast valg: ")
            if x == "x": break
            elif x == "1": 
                if lys_server.message == ("0"):
                    lys_server.set_massege("100")
                else: lys_server.set_massege("0")
            elif x == "2":
                os.system('clear')
                menu.manuelt_menu(lys_server.message, gardin_server.message)
                i = input("Indtast værdi for lys fra 0-100: ")
                lys_server.set_massege(i)
            elif x == "3": 
                if gardin_server.message == ("1"):
                    gardin_server.set_massege("0")
                else: gardin_server.set_massege("1")
            

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
            menu.data_menu(gardin_server.recieve, sensor_server.recieve)
            x = input("Indtast valg: ")
            if x == "x": break
            

# ----------------------Server log----------------------------
    elif x == "5":
        os.system('clear')
        lys_server.setLog(True)
        gardin_server.setLog(True)
        sensor_server.setLog(True)
    
    
    



