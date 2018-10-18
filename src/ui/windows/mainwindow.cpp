#include "mainwindow.hpp"

#include <QMessageBox>
#include <QDockWidget>

#include <ui/panels/mediapanel.hpp>
#include <ui/panels/streamdstpanel.hpp>
#include <ui/panels/transcodepanel.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* Open media panel */
    m_mediaPanel = new MediaPanel(&m_vlcManager);

    /* Transcode panel */
    m_transcodePanel = new TranscodePanel(&m_vlcManager);

    /* Stream destination panel */
    m_streamDstPanel = new StreamDstPanel(&m_vlcManager);

    QDockWidget *dock = new QDockWidget("Open media", this);
    dock->setWidget(m_mediaPanel);
    addDockWidget(Qt::TopDockWidgetArea, dock);

    dock = new QDockWidget("Transcode", this);
    dock->setWidget(m_transcodePanel);
    addDockWidget(Qt::BottomDockWidgetArea, dock);

    dock = new QDockWidget("Stream destination", this);
    dock->setWidget(m_streamDstPanel);
    addDockWidget(Qt::BottomDockWidgetArea, dock);

    /* Window */
    setWindowTitle("Stream server");
    setContentsMargins(10, 10, 10, 10);

    /* Connections */
    connect(&m_vlcManager, &VlcManager::errorOccured, this, &MainWindow::slotHandleError);
}

MainWindow::~MainWindow()
{
}

void MainWindow::slotHandleError(const QString &error)
{
    QMessageBox errorBox(this);
    errorBox.setWindowTitle("Error");
    errorBox.setText(error);
    errorBox.exec();
}
