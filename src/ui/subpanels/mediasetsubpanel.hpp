#ifndef MEDIASETSUBPANEL_HPP
#define MEDIASETSUBPANEL_HPP

#include <QGroupBox>

class QHBoxLayout;
class QPushButton;
class OpenFileBox;

class MediaSetSubpanel : public QGroupBox
{
    Q_OBJECT

public:
    explicit MediaSetSubpanel(QWidget *parent = nullptr);
    virtual ~MediaSetSubpanel();

private:
    QHBoxLayout *m_layout;
    OpenFileBox *m_mediaOpenFileBox;
    QPushButton *m_setMediaButton;

};

#endif // MEDIASETSUBPANEL_HPP
