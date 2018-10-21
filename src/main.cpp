#include <QApplication>

#include <ui/windows/mainwindow.hpp>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}
