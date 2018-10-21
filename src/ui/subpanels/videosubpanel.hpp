#ifndef VIDEOSUBPANEL_HPP
#define VIDEOSUBPANEL_HPP

#include <QGroupBox>

#include "vlcmanager.hpp"

class QFormLayout;
class QSpinBox;
class VideoCodecComboBox;
class QualityComboBox;
class AspectRatioComboBox;

class VideoSubpanel : public QGroupBox
{
    Q_OBJECT

public:
    explicit VideoSubpanel(VlcManager *vlcManager,
                           QWidget *parent = nullptr);
    virtual ~VideoSubpanel();

public slots:
    void setParameters();

private:
    QFormLayout *m_layout;

    VideoCodecComboBox *m_codecComboBox;
    QualityComboBox *m_qualityBox;
    AspectRatioComboBox *m_aspectRatioComboBox;

    QSpinBox *m_bitrateSpinBox;
    QSpinBox *m_frameRateSpinBox;

    VlcManager *m_vlcManager;

};

#endif // VIDEOSUBPANEL_HPP
