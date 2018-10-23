#include "mediainfosubpanel.hpp"

#include <QFormLayout>
#include <QLabel>

#include "vlcmanager.hpp"

MediaInfoSubpanel::MediaInfoSubpanel(QWidget *parent)
    : QGroupBox(parent)
{
    VlcManager &manager = VlcManager::getInstance();

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
    connect(&manager, &VlcManager::mediaSetted,
            [this, &manager](){
        m_pathLabel->setText(manager.getMediaPath());
        m_titleLabel->setText(manager.getMediaTitle());
        m_durationLabel->setText(manager.getMediaDuration().toString());
        m_descriptionLabel->setText(manager.getMediaDescription());
    });
}

MediaInfoSubpanel::~MediaInfoSubpanel()
{
}
