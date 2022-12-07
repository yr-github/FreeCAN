#ifndef SIGNALMODEL_H
#define SIGNALMODEL_H

#include <QAbstractListModel>
#include "DBFFileInfo.h"

class SignalModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit SignalModel(QObject *parent = nullptr);
    enum{
        SignalRole = Qt::UserRole,
        BitsRole
    };
    Q_PROPERTY(DBFFileInfo* dbfInfo READ dbfInfo WRITE setDbfInfo)
    Q_PROPERTY(int iCurrentMessageId READ currentMessageId WRITE setCurrentMessageId)
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    DBFFileInfo* dbfInfo();
    void setDbfInfo(DBFFileInfo* newDbfInfo);
    virtual QHash<int, QByteArray> roleNames() const override;

    int currentMessageId();
    void setCurrentMessageId(int newCurrentMessageId);

private:
    //TODO Question need find a way to make sure
    //this point didn't change data
    DBFFileInfo* m_pDbfInfo;
    int m_iCurrentMessageId;
    std::vector<Signal> m_vSignals;
};

#endif // SIGNALMODEL_H
