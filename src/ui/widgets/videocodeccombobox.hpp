#ifndef VIDEOCODECCOMBOBOX_HPP
#define VIDEOCODECCOMBOBOX_HPP

#include <QComboBox>

#include <VLCQtCore/Enums.h>

class VideoCodecComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit VideoCodecComboBox(QWidget *parent = nullptr);

    Vlc::VideoCodec getCurrentCodec() const;

private:

};

#endif // VIDEOCODECCOMBOBOX_HPP
