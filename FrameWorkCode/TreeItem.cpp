#pragma once
#include "TreeItem.h"
#include "Filters.h"

TreeItem::~TreeItem()
{
	qDeleteAll(mChildItems);
}

void TreeItem::append_child(TreeItem * child)
{
	mChildItems.append(child);
}

TreeItem * TreeItem::child(int row)
{
	if(row < 0 || row >= mChildItems.size())
	return nullptr;
	return mChildItems.at(row);
}

int TreeItem::child_count() const
{
	return mChildItems.count();
}

int TreeItem::column_count() const
{
	return mItemData.count();
}

QVariant TreeItem::data(int column) const
{
	if(column < 0 || column >= mItemData.size())
		return QVariant();
	return mItemData.at(column);
}
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
int TreeItem::row() const
{
	if (mParentItem)
		return mParentItem->mChildItems.indexOf(const_cast<TreeItem*>(this));
	return 0;
}

TreeItem * TreeItem::parentItem()
{
	return mParentItem;
}

void TreeItem :: SetFile( QFile * pFile) {
        file = pFile;
    }
    void TreeItem :: SetFilter(Filter * pFilter) {
        mFilter = pFilter;
    }
    NodeType TreeItem :: GetNodeType() {
        return type;
    }
    QFile * TreeItem :: GetFile() {
        return file;
    }
    Filter * TreeItem :: GetFilter() {
        return mFilter;
    }
    TreeItem * TreeItem :: FindFileNode(QFile*f,TreeItem * item) {
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

    void TreeItem :: RemoveNode(TreeItem * item) {
        int id = mChildItems.indexOf(item);
        if (id < mChildItems.size()) {
            mChildItems.remove(id);
        }
    }
