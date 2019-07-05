#include "mainwindow.h"
#include <QApplication>
#include "DemoQTGUI.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DemoQtGUI test;
    test.show();
    return a.exec();
}
