#include <QApplication>

#include <ui/windows/mainwindow.hpp>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindow mw;
    mw.show();

    return app.exec();
}
