#include "filminfodialog.h"
#include "ui_filminfodialog.h"


FilmInfoDialog::FilmInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilmInfoDialog)
{
    ui->setupUi(this);
}

FilmInfoDialog::~FilmInfoDialog()
{
    delete ui;
}

void FilmInfoDialog::filmInfo(QList<QVariant> newRow)
{
    r = newRow;
    ui->label->setText(newRow[0].toString());
    ui->label_2->setText(newRow[1].toString());
    ui->label_3->setText(newRow[2].toString());
}

void FilmInfoDialog::on_pushButton_clicked()
{
    emit addToFavourites(r);
    QDialog::accept();
}
