#include "factoryofsignal.h"
#include "qnamespace.h"

FactoryOfSignal::FactoryOfSignal(SignalVariables *const signalVariables, ModSignalVariables *const modSignalVariables,
                                 NoiseVariables * const noiseVariables, const int &refreshNum, QObject *parent)
    : QObject{parent}, m_noSignal{signalVariables}, m_cos{signalVariables}, m_rectangle{signalVariables}, m_modCos{modSignalVariables},
      m_modRect{modSignalVariables}, m_cosModCos{signalVariables, &m_modCos}, m_cosModRect{&m_cos, &m_modRect},
      m_rectModCos{&m_rectangle, &m_modCos}, m_rectModRect{&m_rectangle, &m_modRect}, m_cosHFM{signalVariables, &m_modCos},
      m_cosHPM{signalVariables, &m_modCos}, m_modRIP{modSignalVariables, refreshNum}, m_cosModRIP{signalVariables, &m_modRIP}, m_rectModRip{&m_rectangle, &m_modRIP},
      m_cosRIP{signalVariables, refreshNum}, m_cosRIPModCos{signalVariables, &m_modCos, refreshNum}, m_cosRIPModCosRIP{signalVariables, &m_modRIP, refreshNum},
      m_cosRIPModCosHFM{signalVariables, &m_modCos, refreshNum}, m_cosRIPModCosHPM{signalVariables, &m_modCos, refreshNum}, m_cosRIPModRect{&m_cosRIP, &m_modRect},
      m_noiseChannel_1{noiseVariables}, m_noiseChannel_2{noiseVariables}
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
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: RECTANGLE, SIGNALS_MOD :: COS_HAM_RNDPHASE)]    = QPair<I_getSignal*, I_getSignalIm*>(&m_rectModRip, &m_rectModRip);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: HFM)]                 = QPair<I_getSignal*, I_getSignalIm*>(&m_cosHFM, &m_cosHFM);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: HPM)]                 = QPair<I_getSignal*, I_getSignalIm*>(&m_cosHPM, &m_cosHPM);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: COS_RIP,   SIGNALS_MOD :: NO_SIGNAL)]           = QPair<I_getSignal*, I_getSignalIm*>(&m_cosRIP, &m_cosRIP);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: COS_RIP,   SIGNALS_MOD :: COS_HAM)]             = QPair<I_getSignal*, I_getSignalIm*>(&m_cosRIPModCos, &m_cosRIPModCos);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: COS_RIP,   SIGNALS_MOD :: COS_HAM_RNDPHASE)]    = QPair<I_getSignal*, I_getSignalIm*>(&m_cosRIPModCosRIP, &m_cosRIPModCosRIP);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: COS_RIP,   SIGNALS_MOD :: RECTANGLE)]           = QPair<I_getSignal*, I_getSignalIm*>(&m_cosRIPModRect, &m_cosRIPModRect);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: COS_RIP,   SIGNALS_MOD :: HPM)]                 = QPair<I_getSignal*, I_getSignalIm*>(&m_cosRIPModCosHPM, &m_cosRIPModCosHPM);
    m_mapSignal[QPair<int, int>(SIGNALS_MAIN :: COS_RIP,   SIGNALS_MOD :: HFM)]                 = QPair<I_getSignal*, I_getSignalIm*>(&m_cosRIPModCosHFM, &m_cosRIPModCosHFM);



    m_ptrToSignalRe = &m_noSignal;
    m_ptrToSignalIm = &m_noSignal;
    ptrToSignalReChannel_1 = &FactoryOfSignal :: getSignalRe;
    ptrToSignalImChannel_1 = &FactoryOfSignal :: getSignalIm;

    ptrToSignalReChannel_2 = &FactoryOfSignal :: getSignalRe;
    ptrToSignalImChannel_2 = &FactoryOfSignal :: getSignalIm;
    i = 0;

}

double FactoryOfSignal::getSignalNoiseReChannel_1()
{
    return m_ptrToSignalRe->getSignal(i) + m_noiseChannel_1.getSignal(i);
}

double FactoryOfSignal::getSignalNoiseImChannel_1()
{
    return m_ptrToSignalIm->getSignalIm(i++) + m_noiseChannel_1.getSignalIm(i);
}

void FactoryOfSignal::slot_setSignalType(const QPair<int, int> &signalType)
{
    QPair<I_getSignal*, I_getSignalIm*> pair = m_mapSignal.at(signalType);
    m_ptrToSignalRe = pair.first;
    m_ptrToSignalIm = pair.second;
}

void FactoryOfSignal::slot_setNoiseState(const QPair<int, int> &state)
{
    if (state.second == Qt :: Checked)
    {
        ptrToSignalReChannel_2 = &FactoryOfSignal :: getSignalNoiseReChannel_2;
        ptrToSignalImChannel_2 = &FactoryOfSignal :: getSignalNoiseImChannel_2;
    }
    else
    {
        ptrToSignalReChannel_2 = &FactoryOfSignal :: getSignalRe;
        ptrToSignalImChannel_2 = &FactoryOfSignal :: getSignalIm;
    }

    if (state.first == Qt :: Checked)
    {
        ptrToSignalReChannel_1 = &FactoryOfSignal :: getSignalNoiseReChannel_1;
        ptrToSignalImChannel_1 = &FactoryOfSignal :: getSignalNoiseImChannel_1;
    }
    else
    {
        ptrToSignalReChannel_1 = &FactoryOfSignal :: getSignalRe;
        ptrToSignalImChannel_1 = &FactoryOfSignal :: getSignalIm;
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

double FactoryOfSignal::getSignalNoiseReChannel_2()
{
    return m_ptrToSignalRe->getSignal(i) + m_noiseChannel_2.getSignal(i);
}

double FactoryOfSignal::getSignalNoiseImChannel_2()
{
    return m_ptrToSignalIm->getSignalIm(i++) + m_noiseChannel_2.getSignalIm(i);
}

void FactoryOfSignal::resetI()
{
    i = 0;
}

