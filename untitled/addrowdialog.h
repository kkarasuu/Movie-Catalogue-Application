#ifndef ADDROWDIALOG_H
#define ADDROWDIALOG_H

#include <QDialog>
#include <QVariantList>

namespace Ui {
class AddRowDialog;
}

class AddRowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRowDialog(QWidget *parent = nullptr);
    ~AddRowDialog();

signals:
    void rowWasAdded(QList<QVariant>);

private slots:
    void on_applyButton_clicked();

private:
    Ui::AddRowDialog *ui;
};

#endif // ADDROWDIALOG_H
