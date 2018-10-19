#include "mainwindow.hpp"

#include <QMessageBox>
#include <QDockWidget>

#include <ui/panels/mediapanel.hpp>
#include <ui/panels/streampanel.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* Open media panel */
    m_mediaPanel = new MediaPanel(&m_vlcManager);

    /* Stream destination panel */
    m_streamPanel = new StreamPanel(&m_vlcManager);

    QDockWidget *dock = new QDockWidget("Media", this);
    dock->setWidget(m_mediaPanel);
    addDockWidget(Qt::TopDockWidgetArea, dock);

    dock = new QDockWidget("Stream.", this);
    dock->setWidget(m_streamPanel);
    addDockWidget(Qt::BottomDockWidgetArea, dock);

    /* Window */
    setWindowTitle("Stream server");
    setContentsMargins(10, 10, 10, 10);

    /* Connections */
    connect(&m_vlcManager, &VlcManager::errorOccured, this, &MainWindow::handleError);
}

MainWindow::~MainWindow()
{
}

void MainWindow::handleError(QString error)
{
    QMessageBox errorBox(this);
    errorBox.setWindowTitle("Error");
    errorBox.setText(error);
    errorBox.exec();
}
