#include "videosubpanel.hpp"

#include <QFormLayout>
#include <QSpinBox>

#include <ui/widgets/videocodeccombobox.hpp>
#include <ui/widgets/qualitycombobox.hpp>
#include <ui/widgets/aspectratiocombobox.hpp>

#include "vlcmanager.hpp"

VideoSubpanel::VideoSubpanel(QWidget *parent)
    : QGroupBox(parent)
{
    // Create codec combo box
    m_codecComboBox = new VideoCodecComboBox;

    // Create quality combo box
    m_qualityBox = new QualityComboBox;

    // Create aspect ratio combo box
    m_aspectRatioComboBox = new AspectRatioComboBox;

    // Create bitrate spin box
    m_bitrateSpinBox = new QSpinBox;
    m_bitrateSpinBox->setRange(0, 1000000);

    // Create frame rate spin box
    m_frameRateSpinBox = new QSpinBox;
    m_frameRateSpinBox->setRange(0, 999);

    // Create layout
    m_layout = new QFormLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addRow("Codec:"       , m_codecComboBox      );
    m_layout->addRow("Quality:"     , m_qualityBox         );
    m_layout->addRow("Aspect ratio:", m_aspectRatioComboBox);
    m_layout->addRow("Bitrate:"     , m_bitrateSpinBox     );
    m_layout->addRow("Fps:    "     , m_frameRateSpinBox   );

    // Create widget
    setTitle("Video");
    setContentsMargins(5, 20, 5, 5);
    setLayout(m_layout);
}

void VideoSubpanel::setParameters()
{
    SoutBuilder &builder = VlcManager::getInstance().getSoutBuilder();

    builder.setTrcVideoCodec(m_codecComboBox->getCurrentCodec());
    builder.setTrcVideoQuality(m_qualityBox->getCurrentQuality());
    builder.setTrcVideoAspectRatio(m_aspectRatioComboBox->getCurrentAspectRatio());
    builder.setTrcVideoBitrate(m_bitrateSpinBox->value());
    builder.setTrcVideoFrameRate(m_frameRateSpinBox->value());
}
