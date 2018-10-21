#include "mediasetsubpanel.hpp"

#include "QHBoxLayout"
#include <QPushButton>

#include <ui/widgets/openfilebox.hpp>

MediaSetSubpanel::MediaSetSubpanel(VlcManager *vlcManager,
                                   QWidget *parent)
    : QGroupBox(parent),
      m_vlcManager(vlcManager)
{
    // Create media open file box
    m_mediaOpenFileBox = new OpenFileBox("Path");

    // Create set media button
    m_setMediaButton = new QPushButton("Set");

    // Create layout
    m_layout = new QHBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_mediaOpenFileBox);
    m_layout->addWidget(m_setMediaButton);

    // Create widget
    setTitle("Set media");
    setContentsMargins(5, 20, 5, 5);
    setLayout(m_layout);

    // Create connections
    connect(m_setMediaButton, &QPushButton::clicked,
            [this](){
        m_vlcManager->setMedia(m_mediaOpenFileBox->getPath());
    });
}

MediaSetSubpanel::~MediaSetSubpanel()
{
}
