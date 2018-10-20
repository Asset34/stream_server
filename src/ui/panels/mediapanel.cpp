#include "mediapanel.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPushButton>

#include <ui/widgets/openfilebox.hpp>
#include <ui/widgets/outputbox.hpp>

MediaPanel::MediaPanel(VlcManager *vlcManager,
                       QWidget *parent)
    : QWidget(parent),
      m_vlcManager(vlcManager)
{
    // Open file box
    m_setFileBox = new OpenFileBox("Path");

    // Set button
    m_setButton = new QPushButton("Set");
    m_setButton->setFixedWidth(50);
    m_setButton->setFixedHeight(25);

    // Set layout
    m_setLayout = new QHBoxLayout;
    m_setLayout->setMargin(0);
    m_setLayout->addWidget(m_setFileBox);
    m_setLayout->addWidget(m_setButton);

    // Media path
    m_infoPathOutputBox = new OutputBox("Path");

    // Media title
    m_infoTitleOutputBox = new OutputBox("Title");

    // Media description
    m_infoDescOutputBox = new OutputBox("Description");

    // Media info layout
    m_infoLayout = new QVBoxLayout;
    m_infoLayout->setMargin(0);
    m_infoLayout->addWidget(m_infoPathOutputBox);
    m_infoLayout->addWidget(m_infoTitleOutputBox);
    m_infoLayout->addWidget(m_infoDescOutputBox);

    // Media info group box
    m_infoGroupBox = new QGroupBox("Info");
    m_infoGroupBox->setContentsMargins(10, 15, 10, 10);
    m_infoGroupBox->setLayout(m_infoLayout);

    // Main layout
    m_mainLayout = new QVBoxLayout;
    m_mainLayout->setMargin(0);
    m_mainLayout->addLayout(m_setLayout);
    m_mainLayout->addWidget(m_infoGroupBox);

    // Widget
    setLayout(m_mainLayout);

    // Connections
    connect(m_setButton, &QPushButton::clicked, this, &MediaPanel::setMedia);
    connect(m_vlcManager, &VlcManager::mediaSetted, this, &MediaPanel::setMediaInfo);
}

MediaPanel::~MediaPanel()
{
}

void MediaPanel::setMedia()
{
    m_vlcManager->setMedia(m_setFileBox->getPath());
}

void MediaPanel::setMediaInfo(bool status)
{
    if (status) {
        m_infoPathOutputBox->setText(m_vlcManager->getMediaPath());
        m_infoTitleOutputBox->setText(m_vlcManager->getMediaTitle());
        m_infoDescOutputBox->setText(m_vlcManager->getMediaDescription());
    }
    else {
        m_infoPathOutputBox->clear();
        m_infoTitleOutputBox->clear();
        m_infoDescOutputBox->clear();
    }
}
