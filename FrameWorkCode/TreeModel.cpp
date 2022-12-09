/*!
  \class TreeModel.cpp
  \brief The class contains functions regarding TreeModel. It contains
         Operations such as Creation and handling of index and data.
  */
#pragma once
#include "TreeModel.h"

/*!
 * \fn TreeModel::~TreeModel
 * \brief Destructor
 */
TreeModel::~TreeModel()
{
	delete mRootItem;
}

/*!
 * \fn TreeModel::data
 * \brief Fetches the data from TreeItem stored in specific column
 * \param pIndex
 * \param pRole
 * \return bool
 */
QVariant TreeModel::data(const QModelIndex & pIndex, int pRole) const
{
    //!checking index validity
	if (!pIndex.isValid())
		return QVariant();
	if (pRole != Qt::DisplayRole)
		return QVariant();

    //!Creating a new tree item and returning data
	TreeItem * item = static_cast<TreeItem*>(pIndex.internalPointer());
	return item->data(pIndex.column());
}

/*!
 * \fn TreeModel::flags
 * \brief Checks if the QModelindex is valid.
 * \param pIndex
 * \return ItemsFlag
 */
Qt::ItemFlags TreeModel::flags(const QModelIndex & pIndex) const
{
	if (!pIndex.isValid()) {
		return Qt::NoItemFlags;
	}
	return QAbstractItemModel::flags(pIndex);
}

/*!
 * \fn TreeModel::headerData
 * \brief Gets the header data of root items
 * \param pSection
 * \param pOrientation
 * \param pRole
 * \return QVariant
 */
QVariant TreeModel::headerData(int pSection, Qt::Orientation pOrientation, int pRole) const
{
	if (pOrientation == Qt::Horizontal && pRole == Qt::DisplayRole)
		return mRootItem->data(pSection);
	return QVariant();
}

/*!
 * \fn TreeModel::index
 * \brief It validates and returns the index. If it doesn't exists, it creates a new one
 * \param pRow
 * \param pColumn
 * \param pParent
 * \return
 */
QModelIndex TreeModel::index(int pRow, int pColumn, const QModelIndex & pParent) const
{
    //!Checks if index already exists
	if(!hasIndex(pRow,pColumn,pParent))
	return QModelIndex();

    //!Validates the Parent index
	TreeItem * parentItem;
	if (!pParent.isValid()) {
		parentItem = mRootItem;
	}
	else
	{
		parentItem = static_cast<TreeItem*>(pParent.internalPointer());
	}

    //!Creates a new index on the given row if it doesn't exists
	TreeItem * childItem = parentItem->child(pRow);
	if (childItem) {
		return createIndex(pRow, pColumn,childItem);
	}
	return QModelIndex();
}

/*!
 * \fn TreeModel::parent
 * \brief Validates and creates a new parent index
 * \param pIndex
 * \return
 */
QModelIndex TreeModel::parent(const QModelIndex & pIndex) const
{
    //!Validating the index
	if(!pIndex.isValid())
		return QModelIndex();
	TreeItem * childItem = static_cast<TreeItem*>(pIndex.internalPointer());
	TreeItem * parentItem = childItem->parentItem();
	if (parentItem == mRootItem)
	return QModelIndex();
	return createIndex(parentItem->row(), 0, parentItem);
}

/*!
 * \fn TreeModel::rowCount
 * \brief It returns the count of rows
 * \param pParent
 * \return int
 */
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
/*!
 * \fn TreeModel::columnCount
 * \brief It returns the count of column
 * \param pParent
 * \return
 */
int TreeModel::columnCount(const QModelIndex & pParent) const
{
	if (pParent.isValid())
		return static_cast<TreeItem*>(pParent.internalPointer())->column_count();
	return mRootItem->column_count();
}

/*!
 * \fn TreeModel::setupModelData
 * \brief Setup the model data
 * \param lines
 * \param parent
 */
void TreeModel::setupModelData(const QStringList & lines, TreeItem * parent)
{
}
