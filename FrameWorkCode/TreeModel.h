#pragma once
#include<QAbstractItemModel>
#include "TreeItem.h"
class TreeModel : public QAbstractItemModel
{
	Q_OBJECT
public:
	
	explicit TreeModel( QObject *pParent = nullptr){}
	~TreeModel();
	QVariant data(const QModelIndex & pIndex, int pRole) const override;
	Qt::ItemFlags flags(const QModelIndex &pIndex) const override;
	QVariant headerData(int pSection, Qt::Orientation  pOrientation, int pRole = Qt::DisplayRole) const override;
	QModelIndex index(int pRow, int pColumn, const QModelIndex & pParent = QModelIndex()) const override;
	QModelIndex parent(const QModelIndex &pParent = QModelIndex()) const override;
	int rowCount(const QModelIndex &pParent = QModelIndex()) const override;
	int columnCount(const QModelIndex &pParent = QModelIndex()) const override;
	void setRoot(TreeItem * root) {
		mRootItem = root;
	}
private:
	void setupModelData(const QStringList &lines, TreeItem * parent);
	TreeItem * mRootItem;
};