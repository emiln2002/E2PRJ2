#include <string>

struct ui_control{
    
    char key_input();
    void mode_selection(int mode);
    void show_data(int indoor_light_level, int outdoor_light_level, bool person_detected, bool lamp_on, bool shades_down, int lamp_level);
    void show_message(std::string message);
};