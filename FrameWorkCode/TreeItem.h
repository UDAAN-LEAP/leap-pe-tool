#pragma once
#include <QVector>
#include <QVariant>
class TreeItem {
public:
	explicit TreeItem(const QVector<QVariant> &pData, TreeItem * pParentItem = nullptr);
	~TreeItem();
	void append_child(TreeItem * child);
	TreeItem *child(int row);
	int child_count() const;
	int column_count() const;
	QVariant data(int column) const;
	int row() const;
	TreeItem * parentItem();
private:
	QVector<TreeItem*> mChildItems;
	QVector<QVariant> mItemData;
	TreeItem *mParentItem;
};