#include "mainwindow.hpp"

#include <QMessageBox>
#include <QDockWidget>

#include <ui/panels/mediapanel.hpp>
#include <ui/panels/streampanel.hpp>

#include <vlcmanager.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    VlcManager &manager = VlcManager::getInstance();
    QDockWidget *dock;

    // Create media panel
    m_mediaPanel = new MediaPanel;
    dock = new QDockWidget("Media", this);
    dock->setContentsMargins(0, 0, 0, 0);
    dock->setWidget(m_mediaPanel);
    addDockWidget(Qt::TopDockWidgetArea, dock);

    // Create stream panel
    m_streamPanel = new StreamPanel;
    dock = new QDockWidget("Stream", this);
    dock->setContentsMargins(0, 0, 0, 0);
    dock->setWidget(m_streamPanel);
    addDockWidget(Qt::BottomDockWidgetArea, dock);

    // Create window
    setWindowTitle("Stream server");

    // Create connections
    connect(&manager, &VlcManager::errorOccured,
            [this](QString error){
        QMessageBox errorBox(this);

        errorBox.setWindowTitle("Error");
        errorBox.setText(error);
        errorBox.exec();
    });
}
