#include "rectangle.h"

Rectangle::Rectangle()
{

}

double Rectangle::getSignal(int &i)
{
    if (s_frequency == 0)
    {
        if (i == 0 || i == 511)
        {
            return 0.0;
        }
        else if (i <= s_duration * s_decimation)
        {
            return s_amplitude * 1.0;
        }
        else
        {
            return 0.0;
        }
    }

    else
    {
        if (i % (static_cast<int>(s_decimation / s_frequency) - 1) == 0) // 13
        {
            return 0.0;
        }
        else if (i % (static_cast<int>(s_decimation / s_frequency)- 1) <= static_cast<int>(s_duration * s_decimation))
        {
            return s_amplitude * 1.0;
        }
        else
        {
            return 0.0;
        }
    }
}

