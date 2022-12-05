#include "MessageModel.h"

MessageModel::MessageModel(QObject *parent)
: QAbstractListModel(parent),
  m_dbfInfo(nullptr)
{
}

int MessageModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;
    if(!m_dbfInfo){
        return 0;
    }
    return m_dbfInfo->vMessages().size();
    // FIXME: Implement me!
}

QVariant MessageModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    switch (role) {
    case NameRole:
        LOG_DEBUG("message",m_dbfInfo->vMessages().at(index.row()).sMessageName)
        //TODO: Feature the message should sort by ID?
        return m_dbfInfo->vMessages().at(index.row()).sMessageName;
    }
    // FIXME: Implement me!
    return QVariant();
}

DBFFileInfo *MessageModel::dbfInfo()
{
    return m_dbfInfo;
}

void MessageModel::setdbfInfo(DBFFileInfo *newDbfInfo)
{
    beginResetModel();
    if(m_dbfInfo)
        m_dbfInfo->disconnect(this);
    m_dbfInfo=newDbfInfo;
    if(m_dbfInfo){
        connect(m_dbfInfo,&DBFFileInfo::preMessageAppended,this,[=](){
            const int index = m_dbfInfo->vMessages().size();
            beginInsertRows(QModelIndex(),index,index);
        });
        connect(m_dbfInfo,&DBFFileInfo::postMessageAppended,this,[=](){
            endInsertRows();
        });
//        connect(m_dbfInfo,&DBFFileInfo::preItemRemoved,this,[=](int index){
//            beginRemoveRows(QModelIndex(),index,index);
//        });
//        connect(m_dbfInfo,&DBFFileInfo::postItemRemoved,this,[=](){
//            endRemoveRows();
//        });

    }
    endResetModel();
}

bool MessageModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(index)
    Q_UNUSED(value)
    Q_UNUSED(role)
    if (!m_dbfInfo)
        return false;
    std::vector<Message> item;
    return false;
}

Qt::ItemFlags MessageModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> MessageModel::roleNames() const
{
    QHash<int, QByteArray> name;
    name[NameRole]="messageName";
    name[IdRole]="messageID";
    return name;
}
