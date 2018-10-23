#include "mediapanel.hpp"

#include <QVBoxLayout>

#include <ui/subpanels/mediasetsubpanel.hpp>
#include <ui/subpanels/mediainfosubpanel.hpp>

#include <vlcmanager.hpp>

MediaPanel::MediaPanel(QWidget *parent)
    : QWidget(parent)
{
    VlcManager &manager = VlcManager::getInstance();

    // Create set subpanel
    m_setSubpanel = new MediaSetSubpanel;
    m_setSubpanel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    // Create info subpanel
    m_infoSubpanel = new MediaInfoSubpanel;

    // Create layout
    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_setSubpanel);
    m_layout->addWidget(m_infoSubpanel);

    // Create widget
    setLayout(m_layout);
    setContentsMargins(5, 5, 5, 5);
}

MediaPanel::~MediaPanel()
{
}
