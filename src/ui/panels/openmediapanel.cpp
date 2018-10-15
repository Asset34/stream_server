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
    m_openFileBox = new OpenFileBox("Path",
                                    "C:\\Users\\User\\Desktop\\Study\\6th_Semester\\Computer_Networks\\CW\\Video_samples");

    /* Open button */
    m_openButton = new QPushButton("Open");
    m_openButton->setFixedWidth(50);
    m_openButton->setFixedHeight(25);

    /* Layout */
    m_layout = new QHBoxLayout;
    m_layout->setMargin(0);
    m_layout->addWidget(m_openFileBox);
    m_layout->addWidget(m_openButton);

    /* Widget */
    setLayout(m_layout);

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
