/*!
\class TreeItem
\brief This class provide all the functionality of the project tree opened like correctors , verifiers and output files.

\sa    append_child(), child(),child_count(), column_count(), data(), find(), row()
       parentItem(), SetFile(), GetNodeType(),SetFilter(), GetFile(), GetFilter(), FindFileNode(), RemoveNode()
*/
#pragma once
#include "TreeItem.h"
#include "Filters.h"

/*!
 * \fn TreeItem::~TreeItem
 * \brief Destructor
 */
TreeItem::~TreeItem()
{
	qDeleteAll(mChildItems);
}

/*!
 * \fn TreeItem::append_child
 * \brief This function appends child into the tree.
 * \param child
 */
void TreeItem::append_child(TreeItem * child)
{
	mChildItems.append(child);
}

/*!
 * \fn TreeItem::child
 * \brief This function returns the item present at specific row passed in parameters.
 * \param row
 * \return mChildItems.at(row)
 */
TreeItem * TreeItem::child(int row)
{
	if(row < 0 || row >= mChildItems.size())
	return nullptr;
	return mChildItems.at(row);
}

/*!
 * \fn TreeItem::child_count
 * \brief This function returns count of child items in the tree.
 * \return mChildItems.count()
 */
int TreeItem::child_count() const
{
	return mChildItems.count();
}

/*!
 * \fn TreeItem::column_count
 * \brief This function returns count colums of data items.
 * \return mItemData.count()
 */
int TreeItem::column_count() const
{
	return mItemData.count();
}

/*!
 * \fn TreeItem::data
 * \brief This function checks columns and if it is not greater than size of
 *        mITemData then returns data at of the column.
 *
 * \param column
 * \return QVariant(), mItemData.at(column)
 */
QVariant TreeItem::data(int column) const
{
	if(column < 0 || column >= mItemData.size())
		return QVariant();
	return mItemData.at(column);
}

/*!
 * \fn TreeItem::find
 * \brief This function implements search operation in the tree and returns if found returns item else returns nullptr.
 * \param str
 * \return This object's pointer
 */
TreeItem * TreeItem::find(QString & str) {

	for (auto & v : mItemData) {
		//if (std::string(v.typeName()) == "Filter") {
			auto name = (QString*) v.data();
			if (str == *name) {
				return this;
			}
		//}		
	}
	TreeItem *t;
	for (auto p : mChildItems) {
		if (t = p->find(str))
			return t;
	}

	return nullptr;
}

/*!
 * \fn TreeItem::row
 * \brief This function returns indexes of row in the tree.
 * \return mParentItem->mChildItems.indexOf(const_cast<TreeItem*>(this)),0
 */
int TreeItem::row() const
{
	if (mParentItem)
		return mParentItem->mChildItems.indexOf(const_cast<TreeItem*>(this));
	return 0;
}

/*!
 * \fn TreeItem::parentItem
 * \brief This function returns parent items of the tree.
 * \return mParentItem
 */
TreeItem * TreeItem::parentItem()
{
	return mParentItem;
}

/*!
 * \fn TreeItem::SetFile
 * \brief This function assigns pFile param to file variable.
 * \param pFile
 */
void TreeItem::SetFile( QFile * pFile)
{
        file = pFile;
}

/*!
 * \fn TreeItem::SetFilter
 * \brief This function assigns pFilter param to mFilter variable.
 * \param pFilter
 */
void TreeItem::SetFilter(Filter * pFilter)
{
        mFilter = pFilter;
}

/*!
 * \fn TreeItem::GetNodeType
 * \brief This function returns the type of node of the tree.
 * \return type
 */
NodeType TreeItem::GetNodeType()
{
        return type;
}

/*!
 * \fn TreeItem::GetFile
 * \brief This function returns the file of tree.
 * \return file
 */
QFile * TreeItem::GetFile()
{
   return file;
}

/*!
 * \fn TreeItem::GetFilter
 * \brief This function returns mFilter when called.
 * \return mFilter
 */
Filter * TreeItem::GetFilter()
{
  return mFilter;
}


/*!
 * \fn TreeItem::FindFileNode
 * \brief This function is used to search for the file node in the tree and returns
 *        item if found else retuns nullptr if size gets to 0 else recursivly call itself.
 * \param f
 * \param item
 * \return this object's pointer
 */
TreeItem * TreeItem::FindFileNode(QFile*f,TreeItem * item)
{
        if (!item->file) {
            if (f->fileName() == item->file->fileName())
            {
                return item;
            }
        }
        if (item->mChildItems.size() == 0) return nullptr;
        else
        {
            TreeItem * retnVal = nullptr;
            for (TreeItem * n : mChildItems) {
                retnVal = FindFileNode(f, item);
                if (retnVal) return retnVal;
            }
            return retnVal;
        }
}

/*!
 * \fn TreeItem::RemoveNode
 * \brief This function is called to remove a node from the tree.
 * \param item
 */
void TreeItem::RemoveNode(TreeItem * item)
{
    int id = mChildItems.indexOf(item);
    if (id < mChildItems.size()) {
            mChildItems.remove(id);
       }
}
