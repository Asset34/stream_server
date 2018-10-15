#include "mainwindow.hpp"

#include <QMessageBox>

#include <ui/panels/openmediapanel.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* Open media panel */
    m_openMediaPanel = new OpenMediaPanel(&m_vlcManager);

    /* Window */
    setCentralWidget(m_openMediaPanel);
    setWindowTitle("Stream server");

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
