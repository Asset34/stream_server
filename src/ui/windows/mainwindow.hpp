#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <vlcmanager.hpp>

class OpenMediaPanel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private:
    /* Panels */
    OpenMediaPanel *m_openMediaPanel;

    VlcManager m_vlcManager;

private slots:
    void slotHandleError(const QString &error);

};

#endif // MAINWINDOW_HPP
