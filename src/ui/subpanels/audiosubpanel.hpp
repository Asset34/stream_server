#ifndef AUDIOSUBPANEL_HPP
#define AUDIOSUBPANEL_HPP

#include <QGroupBox>

class QFormLayout;
class QSpinBox;
class AudioCodecComboBox;
class SampleRateComboBox;

class AudioSubpanel : public QGroupBox
{
    Q_OBJECT

public:
    explicit AudioSubpanel(QWidget *parent = nullptr);

public slots:
    void setParameters();

private:
    QFormLayout *m_layout;

    AudioCodecComboBox *m_codecComboBox;
    SampleRateComboBox *m_sampleRateComboBox;

    QSpinBox *m_bitrateSpinBox;

};

#endif // AUDIOSUBPANEL_HPP
