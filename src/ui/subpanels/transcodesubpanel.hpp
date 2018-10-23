#ifndef TRANSCODESUBPANEL_HPP
#define TRANSCODESUBPANEL_HPP

#include <QGroupBox>

class QVBoxLayout;
class VideoSubpanel;
class AudioSubpanel;

class TranscodeSubpanel : public QGroupBox
{
    Q_OBJECT

public:
    explicit TranscodeSubpanel(QWidget *parent = nullptr);

public slots:
    void setParameters();

private:
    QVBoxLayout *m_layout;

    VideoSubpanel *m_videoSubpanel;
    AudioSubpanel *m_audioSubpanel;

};

#endif // TRANSCODESUBPANEL_HPP
