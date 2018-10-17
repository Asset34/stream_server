#include "streamdstpanel.hpp"

#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <ui/widgets/inputbox.hpp>
#include <ui/widgets/openfilebox.hpp>

StreamDstPanel::StreamDstPanel(VlcManager *vlcManager,
                               QWidget *parent)
    : m_vlcManager(vlcManager)
{
    /* Ip input box */
    m_ipInputBox = new InputBox("Ip");

    /* Port input box */
    m_portInputBox = new InputBox;

    /* SAP check box */
    m_sapCheckBox = new QCheckBox("SAP announce");
    m_sapCheckBox->setChecked(false);

    /* SAP name input */
    m_sapNameInputBox = new InputBox("Name");

    /* Address layout */
    m_addressLayout = new QHBoxLayout;
    m_addressLayout->setMargin(0);
    m_addressLayout->addWidget(m_ipInputBox);
    m_addressLayout->addWidget(m_portInputBox);

    /* SAP layout */
    m_sapLayout = new QHBoxLayout;
    m_sapLayout->setMargin(0);
    m_sapLayout->addWidget(m_sapCheckBox);
    m_sapLayout->addWidget(m_sapNameInputBox);

    /* Start stream button */
    m_playStreamButton = new QPushButton("Start stream");

    /* Main layout */
    m_mainLayout = new QVBoxLayout;
    m_mainLayout->setMargin(0);
    m_mainLayout->addLayout(m_addressLayout);
    m_mainLayout->addLayout(m_sapLayout);
    m_mainLayout->addWidget(m_playStreamButton);

    /* Widget */
    setLayout(m_mainLayout);

    /* Connections */
    connect(m_playStreamButton, &QPushButton::clicked, this, &StreamDstPanel::slotPlayStream);
}

StreamDstPanel::~StreamDstPanel()
{
}

void StreamDstPanel::slotPlayStream()
{
    SoutBuilder &builder = m_vlcManager->getSoutBuilder();

    builder.setRtpIp(m_ipInputBox->getText());
    builder.setRtpPort(m_portInputBox->getText().toInt());
    builder.setSapEnabled(m_sapCheckBox->isChecked());
    builder.setRtpName(m_sapNameInputBox->getText());

    m_vlcManager->playStream();
}
