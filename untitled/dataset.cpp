#include "dataset.h"
#include <QFile>


Dataset::Dataset(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant Dataset::headerData(int section, Qt::Orientation orientation, int role) const
{

    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        if (section == 1)
            return "Movie Title";

        if (section == 3)
            return "Score";

        if (section == 4)
            return "Director";

    }

    return QVariant();
}

QList<QList<QVariant> > Dataset::getList()
{
    return dataTable;
}

int Dataset::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return dataTable.size();
}

int Dataset::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    if (dataTable.empty())
    {
        return 0;
    }

    return dataTable[0].size();
}

QVariant Dataset::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole)
    {
        int row = index.row();
        int column = index.column();

        return dataTable[row][column];
    }

    return QVariant();
}


void Dataset::fillDataTable(QString path)
{
    QFile inputFile(path);
    inputFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream inputStream(&inputFile);

    QString firstline = inputStream.readLine();

    while(!inputStream.atEnd())
    {
        QString line = inputStream.readLine();

        QList<QVariant> dataRow;
        for (QString& item : line.split(";")) {
            dataRow.append(item);
        }
        dataTable.append(dataRow);
    }

    inputFile.close();
}

void Dataset::addRow(const QList<QVariant>& row)
{
    int nRows = rowCount(QModelIndex());
    beginInsertRows(QModelIndex(), nRows, nRows);
    dataTable.append(row);
    endInsertRows();
}

void Dataset::insertFilm(QList<QVariant> newRow)
{
    int nRows = rowCount(QModelIndex());
    beginInsertRows(QModelIndex(), nRows, nRows);
    dataTable.append(newRow);
    endInsertRows();
}
