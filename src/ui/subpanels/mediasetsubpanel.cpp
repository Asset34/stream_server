#include "mediasetsubpanel.hpp"

#include "QHBoxLayout"
#include <QPushButton>
#include <QFileInfo>
#include <QMessageBox>

#include <ui/widgets/openfilebox.hpp>

#include "vlcmanager.hpp"

MediaSetSubpanel::MediaSetSubpanel(QWidget *parent)
    : QGroupBox(parent)
{
    VlcManager &manager = VlcManager::getInstance();

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
            [this, &manager](){
        QString path = m_mediaOpenFileBox->getPath();

        if (QFileInfo::exists(path) && QFileInfo(path).isFile()) {
            manager.setMedia(m_mediaOpenFileBox->getPath());
        }
        else {
            QMessageBox errorBox(this);
            errorBox.setWindowTitle("Error");
            errorBox.setText("Invalid path");
            errorBox.exec();
        }
    });
}

MediaSetSubpanel::~MediaSetSubpanel()
{
}
