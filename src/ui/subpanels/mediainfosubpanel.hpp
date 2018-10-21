#ifndef MEDIAINFOSUBPANEL_HPP
#define MEDIAINFOSUBPANEL_HPP

#include <QGroupBox>

#include "vlcmanager.hpp"

class QFormLayout;
class QLabel;

class MediaInfoSubpanel : public QGroupBox
{
    Q_OBJECT

public:
    explicit MediaInfoSubpanel(VlcManager *vlcManager,
                               QWidget *parent = nullptr);
    virtual ~MediaInfoSubpanel();

private:
    QFormLayout *m_layout;
    QLabel *m_pathLabel;
    QLabel *m_titleLabel;
    QLabel *m_durationLabel;
    QLabel *m_descriptionLabel;

    VlcManager *m_vlcManager;

};

#endif // MEDIAINFOSUBPANEL_HPP
