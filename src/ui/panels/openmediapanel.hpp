#ifndef OPENMEDIAPANEL_HPP
#define OPENMEDIAPANEL_HPP

#include <QWidget>

#include <vlcmanager.hpp>

class QHBoxLayout;
class QPushButton;
class OpenFileBox;

class OpenMediaPanel : public QWidget
{
    Q_OBJECT

public:
    explicit OpenMediaPanel(VlcManager *vlcManager,
                            QWidget *parent = nullptr);
    virtual ~OpenMediaPanel();

private:
    QHBoxLayout *m_layout;
    OpenFileBox *m_openFileBox;
    QPushButton *m_openButton;

    VlcManager *m_vlcManager;

private slots:
    void slotOpenMedia();

};

#endif // OPENMEDIAPANEL_HPP
