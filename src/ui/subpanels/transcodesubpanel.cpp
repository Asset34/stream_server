#include "transcodesubpanel.hpp"

#include <QVBoxLayout>

#include <ui/subpanels/videosubpanel.hpp>
#include <ui/subpanels/audiosubpanel.hpp>

TranscodeSubpanel::TranscodeSubpanel(VlcManager *vlcManager,
                                     QWidget *parent)
    : QGroupBox(parent),
      m_vlcManager(vlcManager)
{
    // Create video subpanel
    m_videoSubpanel = new VideoSubpanel(vlcManager);
    m_videoSubpanel->setEnabled(false);

    // Create audio subpanel
    m_audioSubpanel = new AudioSubpanel(vlcManager);
    m_audioSubpanel->setEnabled(false);

    // Create layout
    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_videoSubpanel);
    m_layout->addWidget(m_audioSubpanel);

    // Create widget
    setTitle("Transcode");
    setCheckable(true);
    setChecked(false);
    setContentsMargins(5, 20, 5, 5);
    setLayout(m_layout);

    // Create connections
    connect(this, &TranscodeSubpanel::clicked,  m_videoSubpanel, &VideoSubpanel::setEnabled);
    connect(this, &TranscodeSubpanel::clicked,  m_audioSubpanel, &VideoSubpanel::setEnabled);
}

TranscodeSubpanel::~TranscodeSubpanel()
{
}

void TranscodeSubpanel::setParameters()
{
    SoutBuilder &builder = m_vlcManager->getSoutBuilder();

    builder.setTranscodeEnabled(isChecked());

    m_videoSubpanel->setParameters();
    m_audioSubpanel->setParameters();
}
