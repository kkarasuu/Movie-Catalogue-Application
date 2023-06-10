#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/AnimeXTyan_024.webp");
    ui->imageAbout->setPixmap(pix.scaled(ui->imageAbout->width(), ui->imageAbout->height(), Qt::KeepAspectRatio));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
