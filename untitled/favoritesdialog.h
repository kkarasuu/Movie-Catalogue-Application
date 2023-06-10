#ifndef FAVORITESDIALOG_H
#define FAVORITESDIALOG_H

#include <QDialog>
#include "dataset.h"

namespace Ui {
class FavoritesDialog;
}

class FavoritesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FavoritesDialog(QWidget *parent = nullptr);
    ~FavoritesDialog();
    void showFavouriteFilms(Dataset *films);

private slots:

private:
    Ui::FavoritesDialog *ui;
};

#endif // FAVORITESDIALOG_H
