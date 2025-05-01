class Menu:

    def __init__(self):
        self.mode = "Auto"
        print("initialised")
        self.ascii_title = r"""
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

# ----------------------hovedmenu----------------------
    def main_menu(self):  # Note the 'self' parameter
        
        menu_options = (
            "HOVEDMENU:",
            "  1. Skift mode",
            "  2. Styr lys manuelt",
            "  3. Styr lys autonomt",
            "  4. Vis data"
        )

        print(self.ascii_title)
        print(f"MODE: {self.mode}".center(54, "-"))
        for option in menu_options:
            print(option)
        print("-" * 54)


# ----------------------styr lys auto----------------------

    def auto_menu(self):

        menu_options = (
            "  1. menu",
            "  2. menu",
            "  3. menu",
            "",
            "  x. Hovedmenu"
        )

        print(self.ascii_title)
        print("STYR LYS AUTO".center(54, "-"))
        for option in menu_options:
            print(f"{option}")
        print("-" * 54)


# ----------------------styr lys manuelt----------------------

    def manuelt_menu(self):

        menu_options = (
            "  1. Tænd/sluk lys",
            "  2. Åben/luk gardin",
            "",
            "  x. Hovedmenu"
        )
        print(self.ascii_title)
        print("STYR LYS MANUELT".center(54, "-"))
        for option in menu_options:
            print(f"{option}")
        print("-" * 54)
    