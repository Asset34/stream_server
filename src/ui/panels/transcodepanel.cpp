#include "transcodepanel.hpp"

#include <QVBoxLayout>
#include <QGroupBox>
#include <ui/widgets/selectbox.hpp>
#include <ui/widgets/inputbox.hpp>

#include <vlcmanager.hpp>

#include <VLCQtCore/Enums.h>

TranscodePanel::TranscodePanel(VlcManager *vlcManager,
                               QWidget *parent)
    : QWidget(parent),
      m_vlcManager(vlcManager)
{
    // Video codec select box
    m_vcodecSelectBox = new SelectBox("Codec");
    fillVideoCodecs();

    // Quality select box
    m_qualitySelectBox = new SelectBox("Quality");
    fillQualities();

    // Aspect ratio select box
    m_aspectRatioSelectBox = new SelectBox("Aspect ratio");
    fillAspectRatios();

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
    fillAudioCodecs();

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

    // Layout
    m_layout = new QVBoxLayout;
    m_layout->setMargin(0);
    m_layout->addWidget(m_videoGroupBox);
    m_layout->addWidget(m_audioGroupBox);

    // Widget
    setLayout(m_layout);
}

TranscodePanel::~TranscodePanel()
{
}

void TranscodePanel::fillVideoCodecs()
{
    m_vcodecSelectBox->addItem("None"  , Vlc::NoVideo);
    m_vcodecSelectBox->addItem("MPEG2V", Vlc::MPEG2Video);
    m_vcodecSelectBox->addItem("MPEG4V", Vlc::MPEG4Video);
    m_vcodecSelectBox->addItem("H.264" , Vlc::H264);
    m_vcodecSelectBox->addItem("Theora", Vlc::Theora);
}

void TranscodePanel::fillQualities()
{
    m_qualitySelectBox->addItem("240" , 240);
    m_qualitySelectBox->addItem("360" , 360);
    m_qualitySelectBox->addItem("480" , 480);
    m_qualitySelectBox->addItem("720" , 720);
    m_qualitySelectBox->addItem("1080", 1080);
}

void TranscodePanel::fillAspectRatios()
{
    m_aspectRatioSelectBox->addItem("Original", Vlc::Original);
    m_aspectRatioSelectBox->addItem("4:3"     , Vlc::R_4_3);
    m_aspectRatioSelectBox->addItem("16:9"    , Vlc::R_16_9);
    m_aspectRatioSelectBox->addItem("16:10"   , Vlc::R_16_10);
}

void TranscodePanel::fillAudioCodecs()
{
    m_acodecSelectBox->addItem("None"  , Vlc::NoAudio);
    m_acodecSelectBox->addItem("MPEG2A", Vlc::MPEG2Audio);
    m_acodecSelectBox->addItem("MP3"   , Vlc::MP3);
    m_acodecSelectBox->addItem("MPEG4A", Vlc::MPEG4Audio);
    m_acodecSelectBox->addItem("Vorbis", Vlc::Vorbis);
    m_acodecSelectBox->addItem("Flac"  , Vlc::Flac);
}
