#include "rectmodsine.h"

RectModSine::RectModSine()
{

}

double RectModSine::getSignal(int &i)
{
    return rect.getSignal(i) * modSine.getSignal(i);
}
