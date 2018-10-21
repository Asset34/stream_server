#ifndef STREAMINFOSUBPANEL_HPP
#define STREAMINFOSUBPANEL_HPP

#include <QGroupBox>

#include "vlcmanager.hpp"

class QFormLayout;
class QLabel;
class TimePositionWidget;

class StreamInfoSubpanel : public QGroupBox
{
    Q_OBJECT

public:
    explicit StreamInfoSubpanel(VlcManager *vlcManager,
                                QWidget *parent = nullptr);
    virtual ~StreamInfoSubpanel();

private:
    QFormLayout *m_layout;

    QLabel *m_nameLabel;
    QLabel *m_stateLabel;

    TimePositionWidget *m_timePostWidget;

    VlcManager *m_vlcManager;

};

#endif // STREAMINFOSUBPANEL_HPP
