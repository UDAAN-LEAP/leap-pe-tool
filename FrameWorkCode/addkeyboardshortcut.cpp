#include "addkeyboardshortcut.h"

addKeyboardShortcut::addKeyboardShortcut(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant addKeyboardShortcut::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex addKeyboardShortcut::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex addKeyboardShortcut::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int addKeyboardShortcut::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int addKeyboardShortcut::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant addKeyboardShortcut::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
