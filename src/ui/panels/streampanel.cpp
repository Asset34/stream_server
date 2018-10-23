#include "streampanel.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include <ui/subpanels/transcodesubpanel.hpp>
#include <ui/subpanels/addresssubpanel.hpp>
#include <ui/subpanels/streaminfosubpanel.hpp>

#include <vlcmanager.hpp>

StreamPanel::StreamPanel(QWidget *parent)
    : QWidget(parent)
{
    VlcManager &manager = VlcManager::getInstance();

    // Create transcode subpanel
    m_transcodeSubpanel = new TranscodeSubpanel;

    // Create address subpanel
    m_addressSubpanel = new AddressSubpanel;

    // Create info subpanel
    m_infoSubpanel = new StreamInfoSubpanel;

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
    setContentsMargins(5, 5, 5, 5);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    setEnabled(false);

    // Create connections
    connect(&manager, &VlcManager::mediaSetted, this, &StreamPanel::setEnabled);
    connect(m_playButton, &QPushButton::clicked,
            [this, &manager](){
        m_transcodeSubpanel->setParameters();
        m_addressSubpanel->setParameters();

        manager.playStream();

        m_playButton->setEnabled(false);
        m_pauseButton->setEnabled(true);
        m_stopButton->setEnabled(true);
    });
    connect(m_pauseButton, &QPushButton::clicked,
            [this, &manager](bool checked){
        if (checked) {
            manager.pauseStream();

            m_pauseButton->setText("Resume");
        }
        else {
            manager.resumeStream();

            m_pauseButton->setText("Pause");
        }
    });
    connect(m_stopButton, &QPushButton::clicked,
            [this, &manager](){
        manager.stopStream();

        m_playButton->setEnabled(true);
        m_pauseButton->setEnabled(false);
        m_stopButton->setEnabled(false);
    });
}
