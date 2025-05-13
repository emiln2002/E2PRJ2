from UI_package import Menu
from server_package import Server
from Database_package import Database
import os
import threading
import time

menu = Menu()


db_path = os.path.join(os.path.dirname(__file__), "logs.db")
log_database = Database(db_path)
lys_server = Server(8081)
gardin_server = Server(8082)
sensor_server = Server(8083)
show_state = False


def run_data():
    while True:
        while show_state:
            gr = []
            os.system('clear')
            menu.data_menu(gardin_server.receive, sensor_server.receive, lys_server.message, gardin_server.message)
            logs = log_database.get_logs("DESC", 100)
            for row in logs:
                if (row[3] =="OUTSIDE"):
                    gr.append(row[4])
            menu.graph(gr, "UDELYS")
            time.sleep(2)

threading.Thread(target=lys_server.run, args=()).start()
threading.Thread(target=gardin_server.run, args=()).start()
threading.Thread(target=sensor_server.run, args=()).start()
threading.Thread(target=run_data, args=()).start()

def run_auto():
    while True:
        while menu.get_mode() == "Auto":
            # print("Auto mode running")
            lys_server.set_message(sensor_server.receive)
            log_database.save_log("INFO","OUTSIDE",gardin_server.receive)
            log_database.save_log("INFO","INSIDE",lys_server.receive)
            if int(gardin_server.receive) > 50:
                gardin_server.set_message("1")
            else: gardin_server.set_message("0")
        log_database.save_log("INFO","OUTSIDE",gardin_server.receive)
        log_database.save_log("INFO","INSIDE",lys_server.receive)
        time.sleep(2)
        
threading.Thread(target=run_auto, args=()).start()

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
                if lys_server.message == ("100"):
                    lys_server.set_message("0")
                else: lys_server.set_message("100")
            elif x == "2":
                os.system('clear')
                menu.manuelt_menu(lys_server.message, gardin_server.message)
                while True:
                    try:
                        i = int(input("Indtast værdi for lys fra 0-100: "))
                        if 0 <= i <= 100:
                            lys_server.set_message(str(i))
                            break
                        else:
                            os.system('clear')
                            menu.manuelt_menu(lys_server.message, gardin_server.message)
                            print("Ugyldig værdi, indtast ny")
                                           
                    except ValueError:
                        os.system('clear')
                        menu.manuelt_menu(lys_server.message, gardin_server.message)
                        print("Ugyldig værdi, indtast ny")
            elif x == "3": 
                if gardin_server.message == ("1"):
                    gardin_server.set_message("0")
                else: gardin_server.set_message("1")
            

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
            show_state = True
            x = input("Indtast valg: ")
            if x == "x": 
                show_state = False
                break
            
            
    



