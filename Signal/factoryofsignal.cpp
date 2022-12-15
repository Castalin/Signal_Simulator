#include "factoryofsignal.h"

FactoryOfSignal::FactoryOfSignal(SignalVariables *const signalVariables, ModSignalVariables *const modSignalVariables, NoiseVariables * const noiseVariables)
    : m_noSignal{signalVariables}, m_cos{signalVariables}, m_rectangle{signalVariables}, m_modCos{modSignalVariables},
      m_modRect{modSignalVariables}, m_cosModCos{signalVariables, &m_modCos}, m_cosModRect{&m_cos, &m_modRect},
      m_rectModCos{&m_rectangle, &m_modCos}, m_rectModRect{&m_rectangle, &m_modRect}, m_cosHFM{signalVariables, &m_modCos},
      m_cosHPM{signalVariables, &m_modCos}, m_modRIP{modSignalVariables}, m_cosModRIP{signalVariables, &m_modRIP}, m_RectModRip{&m_rectangle, &m_modRIP},
      m_noise{noiseVariables}
{

    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: NO_SIGNAL, SIGNALS_MOD :: NO_SIGNAL)]           = QPair<I_getSignal*, I_getSignalIm*>(&m_noSignal, &m_noSignal);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: NO_SIGNAL)]           = QPair<I_getSignal*, I_getSignalIm*>(&m_cos, &m_cos);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: RECTANGLE, SIGNALS_MOD :: NO_SIGNAL)]           = QPair<I_getSignal*, I_getSignalIm*>(&m_rectangle, &m_rectangle);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: NO_SIGNAL, SIGNALS_MOD :: COS_HAM)]             = QPair<I_getSignal*, I_getSignalIm*>(&m_modCos, &m_modCos);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: NO_SIGNAL, SIGNALS_MOD :: RECTANGLE)]           = QPair<I_getSignal*, I_getSignalIm*>(&m_modRect, &m_modRect);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: NO_SIGNAL, SIGNALS_MOD :: COS_HAM_RNDPHASE)]    = QPair<I_getSignal*, I_getSignalIm*>(&m_modRIP, &m_modRIP);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: COS_HAM)]             = QPair<I_getSignal*, I_getSignalIm*>(&m_cosModCos, &m_cosModCos);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: RECTANGLE)]           = QPair<I_getSignal*, I_getSignalIm*>(&m_cosModRect, &m_cosModRect);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: COS_HAM_RNDPHASE)]    = QPair<I_getSignal*, I_getSignalIm*>(&m_cosModRIP, &m_cosModRIP);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: RECTANGLE, SIGNALS_MOD :: COS_HAM)]             = QPair<I_getSignal*, I_getSignalIm*>(&m_rectModCos, &m_rectModCos);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: RECTANGLE, SIGNALS_MOD :: RECTANGLE)]           = QPair<I_getSignal*, I_getSignalIm*>(&m_rectModRect, &m_rectModRect);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: RECTANGLE, SIGNALS_MOD :: COS_HAM_RNDPHASE)]    = QPair<I_getSignal*, I_getSignalIm*>(&m_RectModRip, &m_RectModRip);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: HFM)]                 = QPair<I_getSignal*, I_getSignalIm*>(&m_cosHFM, &m_cosHFM);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: HPM)]                 = QPair<I_getSignal*, I_getSignalIm*>(&m_cosHPM, &m_cosHPM);


    m_ptrToSignalRe = &m_noSignal;
    m_ptrToSignalIm = &m_noSignal;
    ptrToSignalRe = &FactoryOfSignal :: getSignalNoiseRe;
    ptrToSignalIm = &FactoryOfSignal :: getSignalNoiseIm;
    i = 0;

}

void FactoryOfSignal::setSignalType(const QPair<int, int> &signalType)
{
    (signalType.second == COS_HAM_RNDPHASE) ? m_modRIP.startTimer() : m_modRIP.stopTimer();

    QPair<I_getSignal*, I_getSignalIm*> pair = m_mapSignal.at(signalType);
    m_ptrToSignalRe = pair.first;
    m_ptrToSignalIm = pair.second;
}

void FactoryOfSignal::setNoiseState(const int &state)
{
    if (state == Qt :: Checked)
    {
        ptrToSignalRe = &FactoryOfSignal :: getSignalNoiseRe;
        ptrToSignalIm = &FactoryOfSignal :: getSignalNoiseIm;
    }
    else
    {
        ptrToSignalRe = &FactoryOfSignal :: getSignalRe;
        ptrToSignalIm = &FactoryOfSignal :: getSignalIm;
    }

}

double FactoryOfSignal::getSignalRe()
{
    return m_ptrToSignalRe->getSignal(i);
}

double FactoryOfSignal::getSignalIm()
{
    return m_ptrToSignalIm->getSignalIm(i++);
}

double FactoryOfSignal::getSignalNoiseRe()
{
    return m_ptrToSignalRe->getSignal(i) + m_noise.getSignal(i);
}

double FactoryOfSignal::getSignalNoiseIm()
{
    return m_ptrToSignalIm->getSignalIm(i++) + m_noise.getSignalIm(i);
}

void FactoryOfSignal::resetI()
{
    i = 0;
}

