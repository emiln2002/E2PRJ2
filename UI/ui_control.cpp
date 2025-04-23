#include "ui_control.h"

char ui_control::key_input()
{
    char key;
    std::cin >> key;
    
    return key;
}

void ui_control::mode_selection(int mode)
{
}

void ui_control::show_data(int indoor_light_level, int outdoor_light_level, bool person_detected, bool lamp_on, bool shades_down, int lamp_level)
{
}

void ui_control::show_message(std::string message)
{
}
