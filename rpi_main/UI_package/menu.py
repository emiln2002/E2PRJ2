class Menu:


    def __init__(self):
        self.mode = "Auto"
        print("initialised")

    def toggle_mode(self):
        if self.mode == "Auto":
            self.mode = "Manuel"
        else: self.mode = "Auto"

    def main_menu(self):  # Note the 'self' parameter
        ascii_title = r"""
       _____                      __     __              
      / ___/____ ___  ____ ______/ /_   / /   __  _______
      \__ \/ __ `__ \/ __ `/ ___/ __/  / /   / / / / ___/
     ___/ / / / / / / /_/ / /  / /_   / /___/ /_/ (__  ) 
    /____/_/ /_/ /_/\__,_/_/   \__/  /_____/\__, /____/  
                                           /____/        
        """
        menu_options = (
            "1. Skift mode",
            "2. Styr lys manuelt",
            "3. Styr lys autonomt",
            "4. Vis data"
        )

        print(ascii_title)
        print(f"Mode: {self.mode}".center(50, "-"))
        for option in menu_options:
            print(option)
        print("-" * 50)


# ----------------------styr lys auto----------------------

    def auto_menu(self):
        
        ascii_title = r""" 
  ___ _              _               _       _                     _   
 / __| |_ _  _ _ _  | |  _  _ ___   /_\ _  _| |_ ___ _ _  ___ _ __| |_ 
 \__ \  _| || | '_| | |_| || (_-<  / _ \ || |  _/ _ \ ' \/ _ \ '  \  _|
 |___/\__|\_, |_|   |____\_, /__/ /_/ \_\_,_|\__\___/_||_\___/_|_|_\__|
          |__/           |__/                                          
      
                                               
        """

        menu_options = (
            "1. menu",
            "2. menu",
            "3. menu",
            "4. menu"
        )

        print(ascii_title)
        for option in menu_options:
            print(f"{option}")
        print("-" * 50)


# ----------------------styr lys manuelt----------------------

    def manuelt_menu(self):
        
        ascii_title = r""" 
  ___ _              _             __  __                   _ _   
 / __| |_ _  _ _ _  | |  _  _ ___ |  \/  |__ _ _ _ _  _ ___| | |_ 
 \__ \  _| || | '_| | |_| || (_-< | |\/| / _` | ' \ || / -_) |  _|
 |___/\__|\_, |_|   |____\_, /__/ |_|  |_\__,_|_||_\_,_\___|_|\__|
          |__/           |__/                                     
                                       
                                         
        """

        menu_options = (
            "1. Tænd/sluk lys",
            "2. Åben/luk gardin",
        )

        print(ascii_title)
        for option in menu_options:
            print(f"{option}")
        print("-" * 50)
    