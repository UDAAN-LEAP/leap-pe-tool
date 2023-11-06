#include "customtreeviewitem.h"

customTreeviewItem::customTreeviewItem(QTreeView* tv,QMap<QString, int> corrected, QAbstractItemModel *model)
{
    this->treeView = tv;
    this->changed_pages = corrected;
    this->model = model;
}

