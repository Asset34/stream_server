#include "mainwindow.hpp"

#include <QMessageBox>
#include <QDockWidget>

#include <ui/panels/mediapanel.hpp>
#include <ui/panels/streampanel.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QDockWidget *dock;

    // Create media panel
    m_mediaPanel = new MediaPanel(&m_vlcManager);
    dock = new QDockWidget("Media", this);
    dock->setContentsMargins(0, 0, 0, 0);
    dock->setWidget(m_mediaPanel);
    addDockWidget(Qt::TopDockWidgetArea, dock);

    // Create stream panel
    m_streamPanel = new StreamPanel(&m_vlcManager);
    dock = new QDockWidget("Stream", this);
    dock->setContentsMargins(0, 0, 0, 0);
    dock->setWidget(m_streamPanel);
    addDockWidget(Qt::BottomDockWidgetArea, dock);

    // Create window
    setWindowTitle("Stream server");

    // Create connections
    connect(&m_vlcManager, &VlcManager::errorOccured,
            [this](QString error){
        QMessageBox errorBox(this);

        errorBox.setWindowTitle("Error");
        errorBox.setText(error);
        errorBox.exec();
    });
}

MainWindow::~MainWindow()
{
}
