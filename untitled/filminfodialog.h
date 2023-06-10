#ifndef FILMINFODIALOG_H
#define FILMINFODIALOG_H

#include <QDialog>
#include "dataset.h"

namespace Ui {
class FilmInfoDialog;
}

class FilmInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilmInfoDialog(QWidget *parent = nullptr);
    ~FilmInfoDialog();
    void filmInfo(QList<QVariant> newRow);

signals:
    void addToFavourites(QList<QVariant> row);

private slots:

    void on_pushButton_clicked();

private:
    Ui::FilmInfoDialog *ui;
    QList<QVariant> r;
};

#endif // FILMINFODIALOG_H
