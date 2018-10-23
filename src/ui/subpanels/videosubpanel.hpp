#ifndef VIDEOSUBPANEL_HPP
#define VIDEOSUBPANEL_HPP

#include <QGroupBox>

class QFormLayout;
class QSpinBox;
class VideoCodecComboBox;
class QualityComboBox;
class AspectRatioComboBox;

class VideoSubpanel : public QGroupBox
{
    Q_OBJECT

public:
    explicit VideoSubpanel(QWidget *parent = nullptr);

public slots:
    void setParameters();

private:
    QFormLayout *m_layout;

    VideoCodecComboBox *m_codecComboBox;
    QualityComboBox *m_qualityBox;
    AspectRatioComboBox *m_aspectRatioComboBox;

    QSpinBox *m_bitrateSpinBox;
    QSpinBox *m_frameRateSpinBox;

};

#endif // VIDEOSUBPANEL_HPP
