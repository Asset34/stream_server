#ifndef AUDIOSUBPANEL_HPP
#define AUDIOSUBPANEL_HPP

#include <QGroupBox>

#include "vlcmanager.hpp"

class QFormLayout;
class QSpinBox;
class AudioCodecComboBox;
class SampleRateComboBox;

class AudioSubpanel : public QGroupBox
{
    Q_OBJECT

public:
    explicit AudioSubpanel(VlcManager *vlcManager,
                           QWidget *parent = nullptr);
    virtual ~AudioSubpanel();

public slots:
    void setParameters();

private:
    QFormLayout *m_layout;

    AudioCodecComboBox *m_codecComboBox;
    SampleRateComboBox *m_sampleRateComboBox;

    QSpinBox *m_bitrateSpinBox;

    VlcManager *m_vlcManager;

};

#endif // AUDIOSUBPANEL_HPP
