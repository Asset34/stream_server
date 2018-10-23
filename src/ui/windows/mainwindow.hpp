#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

class MediaPanel;
class StreamPanel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    MediaPanel *m_mediaPanel;
    StreamPanel *m_streamPanel;

};

#endif // MAINWINDOW_HPP
