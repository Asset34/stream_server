#include "mainwindow.hpp"

#include <QMessageBox>
#include <QDockWidget>

#include <ui/panels/openmediapanel.hpp>
#include <ui/panels/streamdstpanel.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* Open media panel */
    m_openMediaPanel = new OpenMediaPanel(&m_vlcManager);

    /* Stream destination panel */
    m_streamDstPanel = new StreamDstPanel(&m_vlcManager);

    QDockWidget *dock = new QDockWidget("Open media", this);
    dock->setWidget(m_openMediaPanel);
    addDockWidget(Qt::TopDockWidgetArea, dock);

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
