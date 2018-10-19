#include "mediapanel.hpp"

#include <QGroupBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <ui/widgets/openfilebox.hpp>

#include <QDebug>

MediaPanel::MediaPanel(VlcManager *vlcManager,
                       QWidget *parent)
    : QWidget(parent),
      m_vlcManager(vlcManager)
{
    // Open file box
    m_openFileBox = new OpenFileBox("Path",
                                    "C:\\Users\\User\\Desktop\\Study\\6th_Semester\\Computer_Networks\\CW\\Video_samples");

    // Open button
    m_setButton = new QPushButton("Set");
    m_setButton->setFixedWidth(50);
    m_setButton->setFixedHeight(25);

    // Layout
    m_layout = new QHBoxLayout;
    m_layout->setMargin(0);
    m_layout->addWidget(m_openFileBox);
    m_layout->addWidget(m_setButton);

    // Widget
    setLayout(m_layout);

    // Connections
    connect(m_setButton, &QPushButton::clicked, this, &MediaPanel::setMedia);
}

MediaPanel::~MediaPanel()
{
}

void MediaPanel::setMedia()
{
    m_vlcManager->setMedia(m_openFileBox->getPath());
}
