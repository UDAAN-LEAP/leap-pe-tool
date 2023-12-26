#ifndef CUSTOMTREEVIEWITEM_H
#define CUSTOMTREEVIEWITEM_H

#include<QStyledItemDelegate>
#include<QTreeView>
#include<QObject>
#include<QPainter>
#include<QStyleOptionViewItem>
#include<QModelIndex>
#include<QDebug>
#include<QAbstractItemModel>
class customTreeviewItem: public QStyledItemDelegate
{
public:
    customTreeviewItem(QTreeView* treeView, QMap<QString, int> checkedPages,QAbstractItemModel *model);

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override
    {
        QString treeItemLabel = index.data(Qt::DisplayRole).toString();
        QStringList pageNames = changedPages.keys();
        if (pageNames.contains(treeItemLabel) ){
            painter->fillRect(option.rect, QColor(60,179,113));
            QRect adjustedRect = option.rect.adjusted(0, 0, 0, 0);
            painter->drawRect(adjustedRect);
        }
        QStyledItemDelegate::paint(painter, option, index);

    }

    void update(QMap<QString, int> checkedPages);

private:
    QTreeView* treeView;
    QMap<QString, int> changedPages;
    QAbstractItemModel *model;
};

#endif // CUSTOMTREEVIEWITEM_H
