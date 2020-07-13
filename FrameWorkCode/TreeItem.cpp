#pragma once
#include "TreeItem.h"

TreeItem::TreeItem(const QVector<QVariant>& pData, TreeItem * pParentItem)
{
}

TreeItem::~TreeItem()
{
}

void TreeItem::append_child(TreeItem * child)
{
}

TreeItem * TreeItem::child(int row)
{
	return nullptr;
}

int TreeItem::child_count() const
{
	return 0;
}

int TreeItem::column_count() const
{
	return 0;
}

QVariant TreeItem::data(int column) const
{
	return QVariant();
}

int TreeItem::row() const
{
	return 0;
}

TreeItem * TreeItem::parentItem()
{
	return nullptr;
}
