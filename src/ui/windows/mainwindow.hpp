#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <vlcmanager.hpp>

class MediaPanel;
class StreamPanel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private:
    MediaPanel *m_mediaPanel;
    StreamPanel *m_streamPanel;

    VlcManager m_vlcManager;

private slots:
    void slotHandleError(const QString &error);

};

#endif // MAINWINDOW_HPP
