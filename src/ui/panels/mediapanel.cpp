#include "mediapanel.hpp"

#include <QVBoxLayout>

#include <ui/subpanels/mediasetsubpanel.hpp>
#include <ui/subpanels/mediainfosubpanel.hpp>

MediaPanel::MediaPanel(VlcManager *vlcManager,
                       QWidget *parent)
    : QWidget(parent),
      m_vlcManager(vlcManager)
{
    // Create set subpanel
    m_setSubpanel = new MediaSetSubpanel(vlcManager);

    // Create info subpanel
    m_infoSubpanel = new MediaInfoSubpanel(vlcManager);

    // Create layout
    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_setSubpanel);
    m_layout->addWidget(m_infoSubpanel);

    // Create widget
    setLayout(m_layout);
}

MediaPanel::~MediaPanel()
{
}
