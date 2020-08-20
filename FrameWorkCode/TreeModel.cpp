#pragma once
#include "TreeModel.h"



TreeModel::~TreeModel()
{
	delete mRootItem;
}

QVariant TreeModel::data(const QModelIndex & pIndex, int pRole) const
{
	if (!pIndex.isValid())
		return QVariant();
	if (pRole != Qt::DisplayRole)
		return QVariant();
	TreeItem * item = static_cast<TreeItem*>(pIndex.internalPointer());
	return item->data(pIndex.column());
}

Qt::ItemFlags TreeModel::flags(const QModelIndex & pIndex) const
{
	if (!pIndex.isValid()) {
		return Qt::NoItemFlags;
	}
	return QAbstractItemModel::flags(pIndex);
}

QVariant TreeModel::headerData(int pSection, Qt::Orientation pOrientation, int pRole) const
{
	if (pOrientation == Qt::Horizontal && pRole == Qt::DisplayRole)
		return mRootItem->data(pSection);
	return QVariant();
}

QModelIndex TreeModel::index(int pRow, int pColumn, const QModelIndex & pParent) const
{
	if(!hasIndex(pRow,pColumn,pParent))
	return QModelIndex();
	TreeItem * parentItem;
	if (!pParent.isValid()) {
		parentItem = mRootItem;
	}
	else
	{
		parentItem = static_cast<TreeItem*>(pParent.internalPointer());
	}
	TreeItem * childItem = parentItem->child(pRow);
	if (childItem) {
		return createIndex(pRow, pColumn,childItem);
	}
	return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex & pIndex) const
{
	if(!pIndex.isValid())
		return QModelIndex();
	TreeItem * childItem = static_cast<TreeItem*>(pIndex.internalPointer());
	TreeItem * parentItem = childItem->parentItem();
	if (parentItem == mRootItem)
	return QModelIndex();
	return createIndex(parentItem->row(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex & pParent) const
{
	TreeItem * parentItem;
	if(pParent.column()>0)
		return 0;
	if (!pParent.isValid()) {
		parentItem = mRootItem;
	}
	else
	{
		parentItem = static_cast<TreeItem*>(pParent.internalPointer());
	}
	return parentItem->child_count();
}

int TreeModel::columnCount(const QModelIndex & pParent) const
{
	if (pParent.isValid())
		return static_cast<TreeItem*>(pParent.internalPointer())->column_count();
	return mRootItem->column_count();
}

void TreeModel::setupModelData(const QStringList & lines, TreeItem * parent)
{
}
