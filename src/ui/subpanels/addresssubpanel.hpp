#ifndef ADDRESSSUBPANEL_HPP
#define ADDRESSSUBPANEL_HPP

#include <QGroupBox>

#include "vlcmanager.hpp"

class QFormLayout;
class QVBoxLayout;
class QLineEdit;
class QCheckBox;
class IpInputBox;

class AddressSubpanel : public QGroupBox
{
    Q_OBJECT

public:
    explicit AddressSubpanel(VlcManager *vlcManager,
                             QWidget *parent = nullptr);
    virtual ~AddressSubpanel();

public slots:
    void setParameters();

private:
    QVBoxLayout *m_mainLayout;
    QFormLayout *m_formLayout;

    QLineEdit *m_nameLineEdit;

    IpInputBox *m_ipInputBox;

    QCheckBox *m_sapCheckBox;

    VlcManager *m_vlcManager;

};

#endif // ADDRESSSUBPANEL_HPP
