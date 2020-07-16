#pragma once
#include <QVector>
#include <QVariant>
#include <QFile>
class TreeItem {
public:
	//Use values not containers like QVector
	template<typename T>
	explicit TreeItem(T &pData, TreeItem * pParentItem = nullptr) {
		QVariant qvar(pData);
		
		//qvar.setValue(pData);
		mItemData.push_back(qvar);
		mParentItem = pParentItem;
		
	}
	~TreeItem();
	void append_child(TreeItem * child);
	TreeItem *child(int row);
	int child_count() const;
	int column_count() const;
	TreeItem * find(QString & str);
	QVariant data(int column) const;
	int row() const;
	void SetFile( QFile * pFile) {
		file = pFile;
	}
	QFile * GetFile() {
		return file;
	}
	TreeItem * parentItem();
private:
	QVector<TreeItem*> mChildItems;
	QVector<QVariant> mItemData;
	TreeItem *mParentItem;
	QFile * file=nullptr;

};