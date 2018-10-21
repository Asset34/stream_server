#include "sampleratecombobox.hpp"

SampleRateComboBox::SampleRateComboBox(QWidget *parent)
    : QComboBox(parent)
{
    addItem("16 kHz"   , 16000);
    addItem("22.05 kHz", 22050);
    addItem("24 kHz"   , 24000);
    addItem("32 kHz"   , 32000);
    addItem("44.1 kHz" , 44100);
    addItem("48 kHz"   , 48000);
}

SampleRateComboBox::~SampleRateComboBox()
{
}

int SampleRateComboBox::getCurrentSampleRate() const
{
    return currentData().toInt();
}
