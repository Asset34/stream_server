#include "mediainfosubpanel.hpp"

#include <QFormLayout>
#include <QLabel>

MediaInfoSubpanel::MediaInfoSubpanel(VlcManager *vlcManager,
                                     QWidget *parent)
    : QGroupBox(parent),
      m_vlcManager(vlcManager)
{
    // Create path label
    m_pathLabel = new QLabel;

    // Create title label
    m_titleLabel = new QLabel;

    // Create duration label
    m_durationLabel = new QLabel;

    // Create description label
    m_descriptionLabel = new QLabel;

    // Create layout
    m_layout = new QFormLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addRow("Path:", m_pathLabel);
    m_layout->addRow("Title:", m_titleLabel);
    m_layout->addRow("Duration:", m_durationLabel);
    m_layout->addRow("Description:", m_descriptionLabel);

    // Create widget
    setTitle("Info");
    setLayout(m_layout);
    setContentsMargins(5, 20, 5, 5);

    // Create connections
    connect(m_vlcManager, &VlcManager::mediaSetted,
            [this](){
        m_pathLabel->setText(m_vlcManager->getMediaPath());
        m_titleLabel->setText(m_vlcManager->getMediaTitle());
        m_durationLabel->setText(m_vlcManager->getMediaDuration().toString());
        m_descriptionLabel->setText(m_vlcManager->getMediaDescription());
    });
}

MediaInfoSubpanel::~MediaInfoSubpanel()
{
}
