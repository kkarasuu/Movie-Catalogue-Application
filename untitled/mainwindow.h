#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dataset.h"
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void loadFileSlot();

    void on_addRowButton_clicked();

    void on_listEntered(QList<QVariant> row);

    void on_scoreButton_clicked();

    void on_yearButton_clicked();

    void highlightDataItem(const QModelIndex& clickIndex);

    void on_actionAbout_app_triggered();

    void on_actionHow_to_use_app_triggered();

    void on_favoriteFilmsButton_clicked();

    void inFavsAdded(QList<QVariant> row);

private:
    Ui::MainWindow *ui;
    Dataset *dataset;
    Dataset *listOfFavorites;
    const QString _fileName;
};
#endif // MAINWINDOW_H
