#ifndef MEDIAPANEL_HPP
#define MEDIAPANEL_HPP

#include <QWidget>

class QVBoxLayout;
class MediaSetSubpanel;
class MediaInfoSubpanel;

class MediaPanel : public QWidget
{
    Q_OBJECT

public:
    explicit MediaPanel(QWidget *parent = nullptr);
    virtual ~MediaPanel();

private:
    QVBoxLayout *m_layout;

    MediaSetSubpanel *m_setSubpanel;
    MediaInfoSubpanel *m_infoSubpanel;

};

#endif // MEDIAPANEL_HPP
