#include "openmediapanel.hpp"

#include <QGroupBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <ui/widgets/openfilebox.hpp>

OpenMediaPanel::OpenMediaPanel(VlcManager *vlcManager, QWidget *parent)
    : QWidget(parent),
      m_vlcManager(vlcManager)
{
    /* Open file box */
    m_openFileBox = new OpenFileBox("Path");

    /* Open button */
    m_openButton = new QPushButton("Open");
    m_openButton->setFixedWidth(50);
    m_openButton->setFixedHeight(25);

    /* Group box Layout */
    m_groupBoxLayout = new QHBoxLayout;
    m_groupBoxLayout->setMargin(0);
    m_groupBoxLayout->addWidget(m_openFileBox);
    m_groupBoxLayout->addWidget(m_openButton);

    /* Group box */
    m_groupBox = new QGroupBox("Open media");
    m_groupBox->setLayout(m_groupBoxLayout);

    /* Main layout */
    m_mainLayout = new QHBoxLayout;
    m_mainLayout->setMargin(0);
    m_mainLayout->addWidget(m_groupBox);

    /* Widget */
    setContentsMargins(5, 5, 5, 5);
    setLayout(m_mainLayout);

    /* Connections */
    connect(m_openButton, &QPushButton::clicked, this, &OpenMediaPanel::slotOpenMedia);
}

OpenMediaPanel::~OpenMediaPanel()
{
}

void OpenMediaPanel::slotOpenMedia()
{
    m_vlcManager->openMedia(m_openFileBox->getPath());
}
