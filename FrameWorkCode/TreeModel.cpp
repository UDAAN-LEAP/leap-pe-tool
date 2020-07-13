#pragma once
#include "TreeModel.h"

TreeModel::~TreeModel()
{
}

QVariant TreeModel::data(const QModelIndex & pIndex, int pRole) const
{
	return QVariant();
}

Qt::ItemFlags TreeModel::flags(const QModelIndex & pIndex) const
{
	return Qt::ItemFlags();
}

QVariant TreeModel::headerData(int pSection, Qt::Orientation pOrientation, int pRole) const
{
	return QVariant();
}

QModelIndex TreeModel::index(int pRow, int pColumn, const QModelIndex & pParent) const
{
	return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex & pParent) const
{
	return QModelIndex();
}

int TreeModel::rowCount(const QModelIndex & pParent) const
{
	return 0;
}

int TreeModel::columnCount(const QModelIndex & pParent) const
{
	return 0;
}

void TreeModel::setupModelData(const QStringList & lines, TreeItem * parent)
{
}
