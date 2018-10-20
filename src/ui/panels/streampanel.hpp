#ifndef STREAMPANEL_HPP
#define STREAMPANEL_HPP

#include <QWidget>

#include <vlcmanager.hpp>

class QHBoxLayout;
class QVBoxLayout;
class QGroupBox;
class QCheckBox;
class QLabel;
class QPushButton;
class SelectBox;
class InputBox;
class OutputBox;

class StreamPanel : public QWidget
{
public:
    StreamPanel(VlcManager *vlcManager,
                   QWidget *parent = nullptr);
    virtual ~StreamPanel();

private:
    void setParameters();

    QHBoxLayout *m_mainLayout;
    QVBoxLayout *m_transcodeLayout;
    QVBoxLayout *m_videoLayout;
    QVBoxLayout *m_audioLayout;
    QVBoxLayout *m_destLayout;
    QVBoxLayout *m_infoLayout;
    QVBoxLayout *m_rightAdditionalLayout;
    QHBoxLayout *m_addressLayout;

    QGroupBox *m_transcodeGroupBox;
    QGroupBox *m_videoGroupBox;
    QGroupBox *m_audioGroupBox;
    QGroupBox *m_destGroupBox;
    QGroupBox *m_infoGroupBox;

    QCheckBox *m_transcodeEnableCheckBox;
    QCheckBox *m_sapCheckBox;

    SelectBox *m_vcodecSelectBox;
    SelectBox *m_qualitySelectBox;
    SelectBox *m_aspectRatioSelectBox;
    SelectBox *m_acodecSelectBox;

    InputBox *m_vbitrateInputBox;
    InputBox *m_frameRateInputBox;
    InputBox *m_abitrateInputBox;
    InputBox *m_sampleRateInputBox;
    InputBox *m_ipInputBox;
    InputBox *m_portInputBox;
    InputBox *m_nameInputBox;

    OutputBox *m_statusOutputBox;
    OutputBox *m_nameOutputBox;
    OutputBox *m_posOutputBox;

    QPushButton *m_playButton;
    QPushButton *m_pauseButton;
    QPushButton *m_stopButton;

    VlcManager *m_vlcManager;

    bool m_isPaused;

private slots:
    void playStream();
    void pauseStream();
    void stopStream();

    void transcodeSetEnabled(bool enabled);

};

#endif // STREAMDSTPANEL_HPP
