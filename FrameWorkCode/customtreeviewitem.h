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
    customTreeviewItem(QTreeView* treeView, QMap<QString, int> corrected,QAbstractItemModel *model);

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override
    {
        QString treeItemLabel = index.data(Qt::DisplayRole).toString();
        QStringList pageNames = changed_pages.keys();
        if (pageNames.contains(treeItemLabel)){

            painter->fillRect(option.rect, QColor(60,179,113));
            QRect adjustedRect = option.rect.adjusted(0, 0, 0, 0);
            painter->setPen(Qt::black);
            painter->drawRect(adjustedRect);
            painter->setPen(Qt::black);
            painter->drawText(adjustedRect.adjusted(22,0,0,0), Qt::AlignLeft | Qt::AlignVCenter, treeItemLabel);

        }
        else{
            QStyledItemDelegate::paint(painter, option, index);
        }
    }

private:
    QTreeView* treeView;
    QMap<QString, int> changed_pages;
    QAbstractItemModel *model;
};

#endif // CUSTOMTREEVIEWITEM_H
