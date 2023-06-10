#include "favoritesdialog.h"
#include "ui_favoritesdialog.h"

FavoritesDialog::FavoritesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FavoritesDialog)
{
    ui->setupUi(this);
}

FavoritesDialog::~FavoritesDialog()
{
    delete ui;
}

void FavoritesDialog::showFavouriteFilms(Dataset *films)
{
    ui->favoriteFilms->setModel(films);
}
