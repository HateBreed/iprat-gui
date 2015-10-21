#include "mainwindow.h"
#include <QApplication>
#include "identificationcreator.h"
#include <stdio.h>
#include "actor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Actor actor("test");

    return a.exec();
}
