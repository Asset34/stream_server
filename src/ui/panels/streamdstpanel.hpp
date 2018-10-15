#ifndef STREAMDSTPANEL_HPP
#define STREAMDSTPANEL_HPP

#include <QWidget>

#include <vlcmanager.hpp>

class QHBoxLayout;
class QVBoxLayout;
class QCheckBox;
class QLabel;
class QPushButton;
class InputBox;
class OutputBox;

class StreamDstPanel : public QWidget
{
public:
    StreamDstPanel(VlcManager *vlcManager,
                   QWidget *parent = nullptr);
    virtual ~StreamDstPanel();

private:
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_addressLayout;
    QHBoxLayout *m_sapLayout;
    InputBox *m_ipInputBox;
    InputBox *m_portInputBox;
    QCheckBox *m_sapCheckBox;
    InputBox *m_sapNameInputBox;
    QPushButton *m_playStreamButton;

    VlcManager *m_vlcManager;

private slots:
    void slotPlayStream();

};

#endif // STREAMDSTPANEL_HPP
