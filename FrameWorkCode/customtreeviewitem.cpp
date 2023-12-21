#include "customtreeviewitem.h"

customTreeviewItem::customTreeviewItem(QTreeView* tv,QMap<QString, int> checkedPages, QAbstractItemModel *model)
{
    this->treeView = tv;
    this->changedPages = checkedPages;
    this->model = model;
}

void customTreeviewItem::update(QMap<QString, int> checkedPages)
{
    this->changedPages = checkedPages;
}

