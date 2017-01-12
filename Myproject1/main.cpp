#include "mainwindow.h"
#include <QApplication>
#include "globals.h"
#include <QtSql>
#include <QtCore/QCoreApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
   // QCoreApplication a(argc,argv);
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
