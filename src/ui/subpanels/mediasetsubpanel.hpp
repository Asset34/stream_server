#ifndef MEDIASETSUBPANEL_HPP
#define MEDIASETSUBPANEL_HPP

#include <QGroupBox>

#include "vlcmanager.hpp"

class QHBoxLayout;
class QPushButton;
class OpenFileBox;

class MediaSetSubpanel : public QGroupBox
{
    Q_OBJECT

public:
    explicit MediaSetSubpanel(VlcManager *vlcManager,
                              QWidget *parent = nullptr);
    virtual ~MediaSetSubpanel();

private:
    QHBoxLayout *m_layout;
    OpenFileBox *m_mediaOpenFileBox;
    QPushButton *m_setMediaButton;

    VlcManager *m_vlcManager;

};

#endif // MEDIASETSUBPANEL_HPP
