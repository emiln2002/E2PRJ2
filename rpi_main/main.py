from UI_package import Menu
from server_package import Server
import os


menu = Menu()



os.system('clear')
menu.main_menu()

while True:
    x = input("Indtast valg: ")


    if x == "x":
        os.system('clear')
        menu.main_menu()
    if x == "1":
        menu.toggle_mode()
        os.system('clear')
        menu.main_menu()
    if x == "2":
        os.system('clear')
        menu.manuelt_menu()
    if x == "3":
        os.system('clear')
        menu.auto_menu()



