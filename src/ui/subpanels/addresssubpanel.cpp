#include "addresssubpanel.hpp"

#include <QFormLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QCheckBox>

#include <ui/widgets/ipinputbox.hpp>

AddressSubpanel::AddressSubpanel(VlcManager *vlcManager,
                                 QWidget *parent)
    : QGroupBox(parent),
      m_vlcManager(vlcManager)
{
    // Create name line edit
    m_nameLineEdit = new QLineEdit;

    // Create ip input box
    m_ipInputBox = new IpInputBox;

    // Create form layout
    m_formLayout = new QFormLayout;
    m_formLayout->setContentsMargins(0, 0, 0, 0);
    m_formLayout->addRow("Name:"   , m_nameLineEdit);
    m_formLayout->addRow("Address:", m_ipInputBox  );

    // Create sap check box
    m_sapCheckBox = new QCheckBox("SAP");
    m_sapCheckBox->setChecked(false);

    // Create main layout
    m_mainLayout = new QVBoxLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addLayout(m_formLayout);
    m_mainLayout->addWidget(m_sapCheckBox);

    // Create widget
    setTitle("Address");
    setContentsMargins(5, 20, 5, 5);
    setLayout(m_mainLayout);
}

AddressSubpanel::~AddressSubpanel()
{
}

void AddressSubpanel::setParameters()
{
    SoutBuilder &builder = m_vlcManager->getSoutBuilder();

    builder.setRtpName(m_nameLineEdit->text());
    builder.setRtpIp(m_ipInputBox->getIp());
    builder.setRtpPort(m_ipInputBox->getPort());
    builder.setSapEnabled(m_sapCheckBox->isChecked());
}
