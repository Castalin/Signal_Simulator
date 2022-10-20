#include "rectmodrect.h"

RectModRect::RectModRect()
{

}

double RectModRect::getSignal(int &i)
{
    return rect.getSignal(i) * modRect.getSignal(i);
}
