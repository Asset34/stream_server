#ifndef TRANSCODESUBPANEL_HPP
#define TRANSCODESUBPANEL_HPP

#include <QGroupBox>

#include "vlcmanager.hpp"

class QVBoxLayout;
class VideoSubpanel;
class AudioSubpanel;

class TranscodeSubpanel : public QGroupBox
{
    Q_OBJECT

public:
    explicit TranscodeSubpanel(VlcManager *vlcManager,
                               QWidget *parent = nullptr);
    virtual ~TranscodeSubpanel();

public slots:
    void setParameters();

private:
    QVBoxLayout *m_layout;

    VideoSubpanel *m_videoSubpanel;
    AudioSubpanel *m_audioSubpanel;

    VlcManager *m_vlcManager;

};

#endif // TRANSCODESUBPANEL_HPP
