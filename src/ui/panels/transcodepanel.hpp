#ifndef TRANSCODEPANEL_HPP
#define TRANSCODEPANEL_HPP

#include <QWidget>

class QVBoxLayout;
class QGroupBox;
class SelectBox;
class InputBox;

class VlcManager;

class TranscodePanel : public QWidget
{
    Q_OBJECT

public:
    explicit TranscodePanel(VlcManager *vlcManager,
                            QWidget *parent = nullptr);
    virtual ~TranscodePanel();

private:
    void fillVideoCodecs();
    void fillQualities();
    void fillAspectRatios();
    void fillAudioCodecs();

    QVBoxLayout *m_layout;
    QVBoxLayout *m_videoLayout;
    QGroupBox *m_videoGroupBox;
    SelectBox *m_vcodecSelectBox;
    SelectBox *m_qualitySelectBox;
    SelectBox *m_aspectRatioSelectBox;
    InputBox *m_vbitrateInputBox;
    InputBox *m_frameRateInputBox;
    QGroupBox *m_audioGroupBox;
    QVBoxLayout *m_audioLayout;
    SelectBox *m_acodecSelectBox;
    InputBox *m_abitrateInputBox;
    InputBox *m_sampleRateInputBox;

    VlcManager *m_vlcManager;

};

#endif // TRANSCODEPANEL_HPP
