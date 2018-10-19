#ifndef MEDIAPANEL_HPP
#define MEDIAPANEL_HPP

#include <QWidget>

#include <vlcmanager.hpp>

class QHBoxLayout;
class QPushButton;
class OpenFileBox;

class MediaPanel : public QWidget
{
    Q_OBJECT

public:
    explicit MediaPanel(VlcManager *vlcManager,
                            QWidget *parent = nullptr);
    virtual ~MediaPanel();

private:
    QHBoxLayout *m_layout;
    OpenFileBox *m_openFileBox;
    QPushButton *m_setButton;

    VlcManager *m_vlcManager;

private slots:
    void setMedia();

};

#endif // MEDIAPANEL_HPP
