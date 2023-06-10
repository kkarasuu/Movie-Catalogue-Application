#ifndef DATASET_H
#define DATASET_H

#include <QAbstractTableModel>

class Dataset : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit Dataset(QObject *parent = nullptr);

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QList<QList<QVariant>> getList();

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void fillDataTable(QString path);

    void addRow(const QList<QVariant>& row);
    void insertFilm(QList<QVariant> newRow);

private:
    QList<QList<QVariant>> dataTable;
};

#endif // DATASET_H
