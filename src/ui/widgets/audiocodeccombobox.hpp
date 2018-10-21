#ifndef AUDIOCODECCOMBOBOX_HPP
#define AUDIOCODECCOMBOBOX_HPP

#include <QComboBox>

#include <VLCQtCore/Enums.h>

class AudioCodecComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit AudioCodecComboBox(QWidget *parent = nullptr);
    virtual ~AudioCodecComboBox();

    Vlc::AudioCodec getCurrentCodec() const;

private:

};

#endif // AUDIOCODECCOMBOBOX_HPP
