#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <vlcmanager.hpp>

class OpenMediaPanel;
class StreamDstPanel;
class TranscodePanel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private:
    OpenMediaPanel *m_openMediaPanel;
    TranscodePanel *m_transcodePanel;
    StreamDstPanel *m_streamDstPanel;

    VlcManager m_vlcManager;

private slots:
    void slotHandleError(const QString &error);

};

#endif // MAINWINDOW_HPP
