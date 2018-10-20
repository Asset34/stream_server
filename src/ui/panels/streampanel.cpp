#include "streampanel.hpp"

#include <QGridLayout>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <ui/widgets/selectbox.hpp>
#include <ui/widgets/inputbox.hpp>
#include <ui/widgets/outputbox.hpp>

StreamPanel::StreamPanel(VlcManager *vlcManager,
                         QWidget *parent)
    : QWidget(parent),
      m_vlcManager(vlcManager),
      m_isPaused(false)
{
    // Enable check box
    m_transcodeEnableCheckBox = new QCheckBox("Enable");
    m_transcodeEnableCheckBox->setChecked(true);

    // Video codec select box
    m_vcodecSelectBox = new SelectBox("Codec");
    m_vcodecSelectBox->addItem("MPEG1V", Vlc::MPEG1Video);
    m_vcodecSelectBox->addItem("MPEG2V", Vlc::MPEG2Video);
    m_vcodecSelectBox->addItem("MPEG4V", Vlc::MPEG4Video);
    m_vcodecSelectBox->addItem("H.264" , Vlc::H264);
    m_vcodecSelectBox->addItem("JPEG"  , Vlc::JPEG);

    // Quality select box
    m_qualitySelectBox = new SelectBox("Quality");
    m_qualitySelectBox->addItem("240" , 240);
    m_qualitySelectBox->addItem("360" , 360);
    m_qualitySelectBox->addItem("480" , 480);
    m_qualitySelectBox->addItem("720" , 720);
    m_qualitySelectBox->addItem("1080", 1080);

    // Aspect ratio select box
    m_aspectRatioSelectBox = new SelectBox("Aspect ratio");
    m_aspectRatioSelectBox->addItem("4:3"     , Vlc::R_4_3);
    m_aspectRatioSelectBox->addItem("16:9"    , Vlc::R_16_9);
    m_aspectRatioSelectBox->addItem("16:10"   , Vlc::R_16_10);

    // Video bitrate input box
    m_vbitrateInputBox = new InputBox("Bitrate");

    // Fps input box
    m_frameRateInputBox = new InputBox("Frame rate");

    // Video layout
    m_videoLayout = new QVBoxLayout;
    m_videoLayout->setMargin(0);
    m_videoLayout->addWidget(m_vcodecSelectBox);
    m_videoLayout->addWidget(m_qualitySelectBox);
    m_videoLayout->addWidget(m_aspectRatioSelectBox);
    m_videoLayout->addWidget(m_vbitrateInputBox);
    m_videoLayout->addWidget(m_frameRateInputBox);

    // Video group box
    m_videoGroupBox = new QGroupBox("Video");
    m_videoGroupBox->setContentsMargins(10, 15, 10, 10);
    m_videoGroupBox->setLayout(m_videoLayout);

    // Audio codec
    m_acodecSelectBox = new SelectBox("Codec");
    m_acodecSelectBox->addItem("MPEG2A", Vlc::MPEG2Audio);
    m_acodecSelectBox->addItem("MP3"   , Vlc::MP3);
    m_acodecSelectBox->addItem("MPEG4A", Vlc::MPEG4Audio);
    m_acodecSelectBox->addItem("A52"   , Vlc::A52);

    // Audio bitrate
    m_abitrateInputBox = new InputBox("Bitrate");

    // Audio sample rate
    m_sampleRateInputBox = new InputBox("Sample rate");

    // Audio layout
    m_audioLayout = new QVBoxLayout;
    m_audioLayout->setMargin(0);
    m_audioLayout->addWidget(m_acodecSelectBox);
    m_audioLayout->addWidget(m_abitrateInputBox);
    m_audioLayout->addWidget(m_sampleRateInputBox);

    // Audio group box
    m_audioGroupBox = new QGroupBox("Audio");
    m_audioGroupBox->setContentsMargins(10, 15, 10, 10);
    m_audioGroupBox->setLayout(m_audioLayout);

    // Transcode layout
    m_transcodeLayout = new QVBoxLayout;
    m_transcodeLayout->setMargin(0);
    m_transcodeLayout->addWidget(m_transcodeEnableCheckBox);
    m_transcodeLayout->addWidget(m_videoGroupBox);
    m_transcodeLayout->addWidget(m_audioGroupBox);

    // Transcode group box
    m_transcodeGroupBox = new QGroupBox("Transcode");
    m_transcodeGroupBox->setContentsMargins(10, 15, 10, 10);
    m_transcodeGroupBox->setLayout(m_transcodeLayout);

    // Ip input box
    m_ipInputBox = new InputBox("Ip");

    // Port input box
    m_portInputBox = new InputBox;

    // Address layout
    m_addressLayout = new QHBoxLayout;
    m_addressLayout->setMargin(0);
    m_addressLayout->addWidget(m_ipInputBox);
    m_addressLayout->addWidget(m_portInputBox);

    // SAP check box
    m_sapCheckBox = new QCheckBox("SAP");
    m_sapCheckBox->setChecked(false);

    // Name input
    m_nameInputBox = new InputBox("Name");

    // Destination layout
    m_destLayout = new QVBoxLayout;
    m_destLayout->setMargin(0);
    m_destLayout->addWidget(m_nameInputBox);
    m_destLayout->addLayout(m_addressLayout);
    m_destLayout->addWidget(m_sapCheckBox);

    // Destination group box
    m_destGroupBox = new QGroupBox("Destination");
    m_destGroupBox->setContentsMargins(10, 15, 10, 10);
    m_destGroupBox->setLayout(m_destLayout);

    // Status output box
    m_statusOutputBox = new OutputBox("Status");

    // Name output box
    m_nameOutputBox = new OutputBox("Name");

    // Position output box
    m_posOutputBox = new OutputBox("Position");

    // Info layout
    m_infoLayout = new QVBoxLayout;
    m_infoLayout->setMargin(0);
    m_infoLayout->addWidget(m_statusOutputBox);
    m_infoLayout->addWidget(m_nameOutputBox);
    m_infoLayout->addWidget(m_posOutputBox);

    // Info group box
    m_infoGroupBox = new QGroupBox("Info");
    m_infoGroupBox->setContentsMargins(10, 15, 10, 10);
    m_infoGroupBox->setLayout(m_infoLayout);

    // Play stream button
    m_playButton = new QPushButton("Play");
    m_playButton->setEnabled(true);

    // Pause stream button
    m_pauseButton = new QPushButton("Pause");
    m_pauseButton->setEnabled(false);

    // Stop stream button
    m_stopButton = new QPushButton("Stop");
    m_stopButton->setEnabled(false);

    // Right additional panel
    m_rightAdditionalLayout = new QVBoxLayout;
    m_rightAdditionalLayout->setMargin(0);
    m_rightAdditionalLayout->addWidget(m_destGroupBox);
    m_rightAdditionalLayout->addWidget(m_infoGroupBox);
    m_rightAdditionalLayout->addWidget(m_playButton);
    m_rightAdditionalLayout->addWidget(m_pauseButton);
    m_rightAdditionalLayout->addWidget(m_stopButton);

    // Top additional panel
    m_mainLayout = new QHBoxLayout;
    m_mainLayout->setMargin(0);
    m_mainLayout->addWidget(m_transcodeGroupBox);
    m_mainLayout->addLayout(m_rightAdditionalLayout);

    // Widget
    setLayout(m_mainLayout);
    setEnabled(false);

    // Connections
    connect(m_playButton, &QPushButton::clicked, this, &StreamPanel::playStream);
    connect(m_pauseButton, &QPushButton::clicked, this, &StreamPanel::pauseStream);
    connect(m_stopButton, &QPushButton::clicked, this, &StreamPanel::stopStream);
    connect(m_transcodeEnableCheckBox, &QCheckBox::toggled, this, &StreamPanel::transcodeSetEnabled);
    connect(m_vlcManager, &VlcManager::mediaSetted, this, &StreamPanel::setEnabled);
}

StreamPanel::~StreamPanel()
{
}

void StreamPanel::setParameters()
{
    SoutBuilder &builder = m_vlcManager->getSoutBuilder();

    // Set transcode parameters
    builder.setTranscodeEnabled(m_transcodeEnableCheckBox->isChecked());
    if (m_transcodeEnableCheckBox->isChecked()) {
        builder.setTrcVideoCodec(static_cast<Vlc::VideoCodec>(m_vcodecSelectBox->currentData().toInt()));
        builder.setTrcVideoQuality(m_qualitySelectBox->currentData().toInt());
        builder.setTrcVideoAspectRatio(static_cast<Vlc::Ratio>(m_aspectRatioSelectBox->currentData().toInt()));
        builder.setTrcVideoBitrate(m_vbitrateInputBox->getText().toInt());
        builder.setTrcVideoFrameRate(m_frameRateInputBox->getText().toInt());
        builder.setTrcAudioCodec(static_cast<Vlc::AudioCodec>(m_acodecSelectBox->currentData().toInt()));
        builder.setTrcAudioBitrate(m_abitrateInputBox->getText().toInt());
        builder.setTrcAudioSampleRate(m_sampleRateInputBox->getText().toInt());
    }

    // Set rtp parameters
    builder.setRtpName(m_nameInputBox->getText());
    builder.setRtpIp(m_ipInputBox->getText());
    builder.setRtpPort(m_portInputBox->getText().toInt());
    builder.setSapEnabled(m_sapCheckBox->isChecked());
}

void StreamPanel::playStream()
{
    setParameters();
    m_vlcManager->playStream();

    m_playButton->setEnabled(false);
    m_pauseButton->setEnabled(true);
    m_stopButton->setEnabled(true);
}

void StreamPanel::pauseStream()
{
    if (m_isPaused) {
        m_vlcManager->resumeStream();
        m_isPaused = false;
        m_pauseButton->setText("Pause");
    }
    else {
        m_vlcManager->pauseStream();
        m_isPaused = true;
        m_pauseButton->setText("Resume");
    }
}

void StreamPanel::stopStream()
{
    m_vlcManager->stopStream();

    m_playButton->setEnabled(true);
    m_pauseButton->setEnabled(false);
    m_stopButton->setEnabled(false);
}

void StreamPanel::transcodeSetEnabled(bool enabled)
{
    m_videoGroupBox->setEnabled(enabled);
    m_audioGroupBox->setEnabled(enabled);
}
