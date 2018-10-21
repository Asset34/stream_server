#ifndef MEDIAPANEL_HPP
#define MEDIAPANEL_HPP

#include <QWidget>

#include <vlcmanager.hpp>

class QVBoxLayout;
class MediaSetSubpanel;
class MediaInfoSubpanel;

class MediaPanel : public QWidget
{
    Q_OBJECT

public:
    explicit MediaPanel(VlcManager *vlcManager,
                        QWidget *parent = nullptr);
    virtual ~MediaPanel();

private:
    QVBoxLayout *m_layout;

    MediaSetSubpanel *m_setSubpanel;
    MediaInfoSubpanel *m_infoSubpanel;

    VlcManager *m_vlcManager;

};

#endif // MEDIAPANEL_HPP
