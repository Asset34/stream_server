#ifndef MEDIAPANEL_HPP
#define MEDIAPANEL_HPP

#include <QWidget>

#include <vlcmanager.hpp>

class QVBoxLayout;
class QHBoxLayout;
class QGroupBox;
class QPushButton;
class OpenFileBox;
class OutputBox;

class MediaPanel : public QWidget
{
    Q_OBJECT

public:
    explicit MediaPanel(VlcManager *vlcManager,
                        QWidget *parent = nullptr);
    virtual ~MediaPanel();

private:
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_setLayout;
    QVBoxLayout *m_infoLayout;

    QGroupBox *m_infoGroupBox;

    OutputBox *m_infoPathOutputBox;
    OutputBox *m_infoTitleOutputBox;
    OutputBox *m_infoDescOutputBox;
    OutputBox *m_infoDurationOutputBox;

    OpenFileBox *m_setFileBox;

    QPushButton *m_setButton;

    VlcManager *m_vlcManager;

private slots:
    void setMedia();
    void setMediaInfo(bool status);

};

#endif // MEDIAPANEL_HPP
