#include "SignalModel.h"
#include "utils/Log.h"

SignalModel::SignalModel(QObject *parent)
    : QAbstractListModel(parent),
      m_pDbfInfo(nullptr),
      m_iCurrentMessageId(0)
{
}

int SignalModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;
    //TODO :Feature this line need find a alternative solution
    //currently use a default value
    if (m_iCurrentMessageId==0){
        return 0;
    }
    return m_pDbfInfo->GetCurrentSignalsById(m_iCurrentMessageId).size();
    // FIXME: Implement me!
}

QVariant SignalModel::data(const QModelIndex &index, int role) const
{

    if (!index.isValid())
        return QVariant();
    switch (role) {
    case SignalRole:
        return m_pDbfInfo->GetCurrentSignalsById(m_iCurrentMessageId).at(index.row()).sSignalName;
    }
    // FIXME: Implement me!
    return QVariant();
}

bool SignalModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(index)
    Q_UNUSED(value)
    Q_UNUSED(role)
    if (!m_pDbfInfo)
        return false;
    std::vector<Message> item;
    return false;
}

Qt::ItemFlags SignalModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

DBFFileInfo *SignalModel::dbfInfo()
{
    return m_pDbfInfo;
}

void SignalModel::setDbfInfo(DBFFileInfo *newDbfInfo)
{

    beginResetModel();
    if(m_pDbfInfo)
        m_pDbfInfo->disconnect(this);
    m_pDbfInfo=newDbfInfo;    
    if(m_pDbfInfo){
        connect(m_pDbfInfo,&DBFFileInfo::preSignalAppended,this,[=](int msgId){
            const int index = m_pDbfInfo->GetCurrentSignalsById(msgId).size();
            beginInsertRows(QModelIndex(),index,index);
        });
        connect(m_pDbfInfo,&DBFFileInfo::postSignalAppended,this,[=](){
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

QHash<int, QByteArray> SignalModel::roleNames() const
{
    QHash<int, QByteArray> name;
    name[SignalRole]="signalNames";
    name[BitsRole]="signalBits";
    return name;
}

int SignalModel::currentMessageId()
{
    return m_iCurrentMessageId;
}

void SignalModel::setCurrentMessageId(int newCurrentMessageId)
{
    m_iCurrentMessageId = newCurrentMessageId;
    beginResetModel();
    endResetModel();
}
