#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include "dataset.h"
#include <QFile>
#include "addrowdialog.h"
#include "filminfodialog.h"
#include <QSortFilterProxyModel>
#include "aboutdialog.h"
#include "helpdialog.h"
#include <QPixmap>
#include "favoritesdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/AnimeXTyan_024.webp");
    ui->image->setPixmap(pix.scaled(ui->image->width(), ui->image->height(), Qt::KeepAspectRatio));

    dataset = new Dataset(this);
    listOfFavorites = new Dataset(this);
    ui->myDataset->setModel(dataset);

    QObject::connect(ui->addDataset, SIGNAL(clicked()), this, SLOT(loadFileSlot()));
    QObject::connect(ui->scoreButton, SIGNAL(clicked()), this, SLOT(on_scoreButton_clicked()));
    QObject::connect(ui->yearButton, SIGNAL(clicked()), this, SLOT(on_yearButton_clicked()));
    QObject::connect(ui->myDataset, &QAbstractItemView::clicked, this, &MainWindow::highlightDataItem);
}

void MainWindow::loadFileSlot()
{
    const QString _fileName = QFileDialog::getOpenFileName(this, "Open File", "../", "Images (*.csv)");
    delete dataset;
    dataset = new Dataset(this);
    dataset->fillDataTable(_fileName);
    ui->myDataset->setModel(dataset);
    ui->myDataset->setColumnHidden(0, true);
    ui->myDataset->setColumnHidden(2, true);
    ui->myDataset->setColumnHidden(5, true);
    ui->myDataset->setColumnHidden(6, true);
    ui->myDataset->setColumnHidden(7, true);
    ui->myDataset->setColumnHidden(8, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addRowButton_clicked()
{
    AddRowDialog dialog(this);
    dialog.setWindowTitle("Add row");
    connect(&dialog, &AddRowDialog::rowWasAdded, this, &MainWindow::on_listEntered);
    dialog.exec();
}

void MainWindow::on_listEntered(QList<QVariant> row)
{
    dataset->addRow(row);
}

void MainWindow::on_scoreButton_clicked()
{
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(ui->myDataset->model());
    ui->myDataset->setModel(proxyModel);
    proxyModel->sort(3, Qt::DescendingOrder);
}


void MainWindow::on_yearButton_clicked()
{
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(ui->myDataset->model());
    ui->myDataset->setModel(proxyModel);
    proxyModel->sort(2, Qt::DescendingOrder);
}

void MainWindow::highlightDataItem(const QModelIndex& clickIndex)
{
    FilmInfoDialog dialog(this);
    dialog.setWindowTitle("Film info");
    int row = clickIndex.row();
    QList<QVariant> newRow;
    QModelIndex index_title = dataset->index(row, 1);
    QModelIndex index_score = dataset->index(row, 3);
    QModelIndex index_director = dataset->index(row, 4);
    newRow.append(dataset->data(index_title).toString());
    newRow.append(dataset->data(index_score).toString());
    newRow.append(dataset->data(index_director).toString());
    dialog.filmInfo(newRow);
    connect(&dialog, &FilmInfoDialog::addToFavourites, this, &MainWindow::inFavsAdded);
    dialog.exec();
}

void MainWindow::on_actionAbout_app_triggered()
{
    AboutDialog dialog(this);
    dialog.setWindowTitle("About");
    dialog.exec();

}

void MainWindow::on_actionHow_to_use_app_triggered()
{
    HelpDialog dialog(this);
    dialog.setWindowTitle("How to use app");
    dialog.exec();
}


void MainWindow::on_favoriteFilmsButton_clicked()
{
    FavoritesDialog favs;
    favs.setModal(true);
    favs.showFavouriteFilms(listOfFavorites);
    favs.exec();
}

void MainWindow::inFavsAdded(QList<QVariant> row)
{
    listOfFavorites->insertFilm(row);
}

