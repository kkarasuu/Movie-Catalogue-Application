#include "addrowdialog.h"
#include "ui_addrowdialog.h"

AddRowDialog::AddRowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRowDialog)
{
    ui->setupUi(this);
}

AddRowDialog::~AddRowDialog()
{
    delete ui;
}

void AddRowDialog::on_applyButton_clicked()
{
    QList<QVariant> dataRow;
    dataRow.append(ui->lineEdit->text());
    dataRow.append(ui->lineEdit_2->text());
    dataRow.append(ui->lineEdit_3->text());
    dataRow.append(ui->lineEdit_4->text());
    dataRow.append(ui->lineEdit_5->text());
    dataRow.append(ui->lineEdit_6->text());
    dataRow.append(ui->lineEdit_7->text());
    dataRow.append(ui->lineEdit_8->text());
    dataRow.append(ui->lineEdit_9->text());

    emit rowWasAdded(dataRow);
    QDialog::accept();
}
