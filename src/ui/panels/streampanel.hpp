#ifndef STREAMPANEL_HPP
#define STREAMPANEL_HPP

#include <QWidget>

#include <vlcmanager.hpp>

class QVBoxLayout;
class QHBoxLayout;
class QPushButton;
class TranscodeSubpanel;
class AddressSubpanel;
class StreamInfoSubpanel;

class StreamPanel : public QWidget
{
public:
    StreamPanel(VlcManager *vlcManager,
                   QWidget *parent = nullptr);
    virtual ~StreamPanel();

private:
    QHBoxLayout *m_mainLayout;
    QVBoxLayout *m_rightLayout;

    TranscodeSubpanel *m_transcodeSubpanel;
    AddressSubpanel *m_addressSubpanel;
    StreamInfoSubpanel *m_infoSubpanel;

    QPushButton *m_playButton;
    QPushButton *m_pauseButton;
    QPushButton *m_stopButton;

    VlcManager *m_vlcManager;

};

#endif // STREAMDSTPANEL_HPP
