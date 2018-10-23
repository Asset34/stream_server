#ifndef MEDIAINFOSUBPANEL_HPP
#define MEDIAINFOSUBPANEL_HPP

#include <QGroupBox>

class QFormLayout;
class QLabel;

class MediaInfoSubpanel : public QGroupBox
{
    Q_OBJECT

public:
    explicit MediaInfoSubpanel(QWidget *parent = nullptr);
    virtual ~MediaInfoSubpanel();

private:
    QFormLayout *m_layout;
    QLabel *m_pathLabel;
    QLabel *m_titleLabel;
    QLabel *m_durationLabel;
    QLabel *m_descriptionLabel;

};

#endif // MEDIAINFOSUBPANEL_HPP
