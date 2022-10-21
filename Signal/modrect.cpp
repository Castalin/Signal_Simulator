#include "modrect.h"

ModRect::ModRect()
{

}

double ModRect::getSignal(const int &i)
{
    if (s_frequencyMod == 0)
    {
        if (i == 0 || i == 255)
        {
            return 0.0;
        }
        else if (i <= s_durationMod * s_decimation)
        {
            return s_amplitudeMod;
        }
        else
        {
            return 0.0;
        }
    }

    else
    {
        if (i % (static_cast<int>(s_decimation / s_frequencyMod) - 1) == 0) // 13
        {
            return 0.0;
        }
        else if (i % (static_cast<int>(s_decimation / s_frequencyMod)- 1) <= static_cast<int>(s_durationMod * s_decimation))
        {
            return s_amplitudeMod;
        }
        else
        {
            return 0.0;
        }
    }
}
