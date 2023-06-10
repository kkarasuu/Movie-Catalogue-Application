#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file(":/resources/styles/style.css");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(file.readAll());
    a.setWindowIcon(QIcon(":/resources/img/AnimeXTyan_024.webp"));
    MainWindow w;
    w.setWindowTitle("Movie Catalogue Application");
    w.show();
    return a.exec();
}
