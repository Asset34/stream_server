#include "streampanel.hpp"

class QVBoxLayout;
class QHBoxLayout;
class QToggleButton;
class QPushButton;
class TranscodeSubpanel;
class AddressSubpanel;
class StreamInfoSubpanel;

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include <ui/subpanels/transcodesubpanel.hpp>
#include <ui/subpanels/addresssubpanel.hpp>
#include <ui/subpanels/streaminfosubpanel.hpp>

StreamPanel::StreamPanel(VlcManager *vlcManager,
                         QWidget *parent)
    : QWidget(parent),
      m_vlcManager(vlcManager)
{
    // Create transcode subpanel
    m_transcodeSubpanel = new TranscodeSubpanel(vlcManager);

    // Create address subpanel
    m_addressSubpanel = new AddressSubpanel(vlcManager);

    // Create info subpanel
    m_infoSubpanel = new StreamInfoSubpanel(vlcManager);

    // Create play button
    m_playButton = new QPushButton("Play");
    m_playButton->setEnabled(true);

    // Create pause button
    m_pauseButton = new QPushButton("Pause");
    m_pauseButton->setCheckable(true);
    m_pauseButton->setChecked(false);
    m_pauseButton->setEnabled(false);

    // Create stop button
    m_stopButton = new QPushButton("Stop");
    m_stopButton->setEnabled(false);

    // Create right layout
    m_rightLayout = new QVBoxLayout;
    m_rightLayout->setContentsMargins(0, 0, 0, 0);
    m_rightLayout->addWidget(m_addressSubpanel);
    m_rightLayout->addWidget(m_infoSubpanel);
    m_rightLayout->addWidget(m_playButton);
    m_rightLayout->addWidget(m_pauseButton);
    m_rightLayout->addWidget(m_stopButton);

    // Create main layout
    m_mainLayout = new QHBoxLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addWidget(m_transcodeSubpanel);
    m_mainLayout->addLayout(m_rightLayout);

    // Create widget
    setLayout(m_mainLayout);
    setEnabled(false);

    // Create connections
    connect(m_vlcManager, &VlcManager::mediaSetted, this, &StreamPanel::setEnabled);
    connect(m_playButton, &QPushButton::clicked,
            [this](){
        m_transcodeSubpanel->setParameters();
        m_addressSubpanel->setParameters();
        m_vlcManager->playStream();

        m_playButton->setEnabled(false);
        m_pauseButton->setEnabled(true);
        m_stopButton->setEnabled(true);
    });
    connect(m_pauseButton, &QPushButton::clicked,
            [this](bool checked){
        if (checked) {
            m_vlcManager->pauseStream();
            m_pauseButton->setText("Resume");
        }
        else {
            m_vlcManager->resumeStream();
            m_pauseButton->setText("Pause");
        }
    });
    connect(m_stopButton, &QPushButton::clicked,
            [this](){
        m_vlcManager->stopStream();

        m_playButton->setEnabled(true);
        m_pauseButton->setEnabled(false);
        m_stopButton->setEnabled(false);
    });
}

StreamPanel::~StreamPanel()
{
}
