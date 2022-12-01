#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H

#include <QAbstractListModel>
#include "DBFFileInfo.h"
#include "utils/Log.h"
class MessageModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit MessageModel(QObject *parent = nullptr);
    Q_PROPERTY(DBFFileInfo* dbfInfo READ dbfInfo WRITE setdbfInfo)
    enum{
        NameRole = Qt::UserRole,
        IdRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    DBFFileInfo *dbfInfo();
    void setdbfInfo(DBFFileInfo* newDbfInfo);

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

signals:
    void vMessagesChanged();

private:
    DBFFileInfo* m_dbfInfo;
};

#endif // MESSAGEMODEL_H
