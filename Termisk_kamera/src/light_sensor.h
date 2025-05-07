#pragma once


class light_sensor
{
    private:
    int light_level_;
    int threshold_;
    public:
    light_sensor(int light_level, int threshold);
    int adjust_light();
};
