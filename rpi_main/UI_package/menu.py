import os


class Menu:

    def __init__(self):
        self.mode = "Manuel"
        print("initialised")
        self.title = r"""
      _____                      __     __              
     / ___/____ ___  ____ ______/ /_   / /   __  _______
     \__ \/ __ `__ \/ __ `/ ___/ __/  / /   / / / / ___/
    ___/ / / / / / / /_/ / /  / /_   / /___/ /_/ (__  ) 
   /____/_/ /_/ /_/\__,_/_/   \__/  /_____/\__, /____/  
                                          /____/        
        """


    def toggle_mode(self):
        if self.mode == "Auto":
            self.mode = "Manuel"
        else: self.mode = "Auto"
    
    def get_mode(self): 
        return self.mode
        

# ----------------------hovedmenu----------------------
    def main_menu(self):
        
        menu_options = (
            "HOVEDMENU:",
            "  1. Skift mode",
            "  2. Styr lys manuelt",
            "  3. Styr lys autonomt",
            "  4. Vis data"
        )

        print(self.title)
        print(f"MODE: {self.mode}".center(60, "-"))
        for option in menu_options:
            print(option)
        print("-" * 60)


# ----------------------styr lys auto----------------------

    def auto_menu(self):

        menu_options = (
            "  1. menu",
            "  2. menu",
            "  3. menu",
            "",
            "  x. Hovedmenu"
        )

        print(self.title)
        print("STYR LYS AUTO".center(60, "-"))
        for option in menu_options:
            print(f"{option}")
        print("-" * 60)


# ----------------------styr lys manuelt----------------------

    def manuelt_menu(self, lys_state, gardin_state):

        menu_options = (
            "  1. Tænd/Sluk lys                                ",
            f"  2. Juster lys niveau                            state: {lys_state}",
            f"  3. Åben/luk gardin                              state: {gardin_state}",
            "",
            "  x. Hovedmenu"
        )
        print(self.title)
        print("STYR LYS MANUELT".center(60, "-"))
        for option in menu_options:
            print(f"{option}")
        print("-" * 60)
        
        
# ----------------------vis data----------------------

    def data_menu(self, udelys, indelys, lys, gardin):
        os.system('clear')
        title = r"""
    _____ __                      __   ____        __       
   / ___// /_____  ________  ____/ /  / __ \____ _/ /_____ _
   \__ \/ __/ __ \/ ___/ _ \/ __  /  / / / / __ `/ __/ __ `/
  ___/ / /_/ /_/ / /  /  __/ /_/ /  / /_/ / /_/ / /_/ /_/ / 
 /____/\__/\____/_/   \___/\__,_/  /_____/\__,_/\__/\__,_/                    
        """

        print(title)
        print("DEVICES".center(60, "-"))
        print(f"  Udelys:     {udelys}")
        print(f"  Indelys:    {indelys}")
        print(f"  Lys niveau: {lys}")
        print(f"  Gardin:     {gardin}")
        
        #gr = [5,5,4,4,5,4,3,2,2,1,2,3,4,5,6,7,8,9,10,10,10,9,9,8,8,7,7,6,6,5,5,6,5,4,4,3,2,3,4,5,6,6,6,5,5]
        #self.graph(gr,"OUTSIDE LIGHT")
        
        print("-" * 60)
        
        
        
# ----------------------graph----------------------
    def graph(self,lis:list,name):
        li = lis
        while len(li) < 50:
            li.append(0)
        while len(li) > 50:
            li.pop(0)
        for x in lis:
            x = x/10
        
        print(("┌─" + "─" * len(name) + "─┐").center(60, " "))
        print("┌", end="")
        print(f"┤ {name} ├".center(58, "─"), end="")
        print("┐")
        print("│", end="")
        print(("└─" + "─" * len(name) + "─┘").center(58, " "), end="")
        print("│")
        
        for x in reversed(range(1,11)):
            if x == 10: print(f"│ {x}", end="│")
            else: print(f"│  {x}", end="│")
            for i in li:
                if i==x: print("—", end="")
                else: print(" ", end="")
            print("    │")
        print("│   └", end="")
        print("─" * 50 + "    │")
        print("└" + "─" * 58 + "┘")