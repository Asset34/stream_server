#include "transcodesubpanel.hpp"

#include <QVBoxLayout>
#include <QCheckBox>

#include <ui/subpanels/videosubpanel.hpp>
#include <ui/subpanels/audiosubpanel.hpp>

TranscodeSubpanel::TranscodeSubpanel(VlcManager *vlcManager,
                                     QWidget *parent)
    : QGroupBox(parent),
      m_vlcManager(vlcManager)
{
    // Create enable check box
    m_enableCheckBox = new QCheckBox;
    m_enableCheckBox->setChecked(false);

    // Create video subpanel
    m_videoSubpanel = new VideoSubpanel(vlcManager);
    m_videoSubpanel->setEnabled(false);

    // Create audio subpanel
    m_audioSubpanel = new AudioSubpanel(vlcManager);
    m_audioSubpanel->setEnabled(false);

    // Create layout
    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);

    // Create widget
    setTitle("Transcode");
    setContentsMargins(5, 20, 5, 5);
    setLayout(m_layout);

    // Create connections
    connect(m_enableCheckBox, &QCheckBox::clicked, m_videoSubpanel, &VideoSubpanel::setEnabled);
    connect(m_enableCheckBox, &QCheckBox::clicked, m_audioSubpanel, &AudioSubpanel::setEnabled);
}

TranscodeSubpanel::~TranscodeSubpanel()
{
}

void TranscodeSubpanel::setParameters()
{
    SoutBuilder &builder = m_vlcManager->getSoutBuilder();

    builder.setTranscodeEnabled(m_enableCheckBox->isChecked());

    m_videoSubpanel->setParameters();
    m_audioSubpanel->setParameters();
}
