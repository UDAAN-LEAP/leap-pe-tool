#include "customtreeviewitem.h"

customTreeviewItem::customTreeviewItem(QTreeView* tv,QMap<QString, int> checkedPages, QAbstractItemModel *model)
{
    this->treeView = tv;
    this->changedPages = checkedPages;
    this->model = model;
}

