#include "videocodeccombobox.hpp"

VideoCodecComboBox::VideoCodecComboBox(QWidget *parent)
    : QComboBox(parent)
{
    addItem("MPEG1V", Vlc::MPEG1Video);
    addItem("MPEG2V", Vlc::MPEG2Video);
    addItem("MPEG4V", Vlc::MPEG4Video);
    addItem("H.264" , Vlc::H264      );
    addItem("JPEG"  , Vlc::JPEG      );
}

VideoCodecComboBox::~VideoCodecComboBox()
{
}

Vlc::VideoCodec VideoCodecComboBox::getCurrentCodec() const
{
    static_cast<Vlc::AudioCodec>(currentData().toInt());
}
