#include "audiosubpanel.hpp"

#include <QFormLayout>
#include <QSpinBox>

#include <ui/widgets/audiocodeccombobox.hpp>
#include <ui/widgets/sampleratecombobox.hpp>

#include "vlcmanager.hpp"

AudioSubpanel::AudioSubpanel(QWidget *parent)
    : QGroupBox(parent)
{
    // Create codec combo box
    m_codecComboBox = new AudioCodecComboBox;

    // Create sample rate combo box
    m_sampleRateComboBox = new SampleRateComboBox;

    // Create bitrate spin box
    m_bitrateSpinBox = new QSpinBox;
    m_bitrateSpinBox->setRange(0, 1000000);

    // Create layout
    m_layout = new QFormLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addRow("Codec:"      , m_codecComboBox     );
    m_layout->addRow("Sample rate:", m_sampleRateComboBox);
    m_layout->addRow("Bitrate:"    , m_bitrateSpinBox    );

    // Create widget
    setTitle("Audio");
    setContentsMargins(5, 20, 5, 5);
    setLayout(m_layout);
}

void AudioSubpanel::setParameters()
{
    SoutBuilder &builder = VlcManager::getInstance().getSoutBuilder();

    builder.setTrcAudioCodec(m_codecComboBox->getCurrentCodec());
    builder.setTrcAudioSampleRate(m_sampleRateComboBox->getCurrentSampleRate());
    builder.setTrcAudioBitrate(m_bitrateSpinBox->value());
}
