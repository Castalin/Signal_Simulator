#include "rectmodrect.h"

RectModRect::RectModRect()
{

}

double RectModRect::getSignal(const int &i)
{
    return rect.getSignal(i) * modRect.getSignal(i);
}
