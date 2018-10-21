#include "audiocodeccombobox.hpp"

AudioCodecComboBox::AudioCodecComboBox(QWidget *parent)
    : QComboBox(parent)
{
    addItem("MPEG2A", Vlc::MPEG2Audio);
    addItem("MP3"   , Vlc::MP3       );
    addItem("MPEG4A", Vlc::MPEG4Audio);
    addItem("A52"   , Vlc::A52       );
}

AudioCodecComboBox::~AudioCodecComboBox()
{
}

Vlc::AudioCodec AudioCodecComboBox::getCurrentCodec() const
{
    return static_cast<Vlc::AudioCodec>(currentData().toInt());
}
