#include "rectmodsine.h"

RectModSine::RectModSine()
{

}

double RectModSine::getSignal(const int &i)
{
    return rect.getSignal(i) * modSine.getSignal(i);
}
