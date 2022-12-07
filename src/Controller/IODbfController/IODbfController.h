#ifndef IODBFCONTROLLER_H
#define IODBFCONTROLLER_H

#include <QObject>
#include <src/Model/DBFFileInfo.h>
class IODbfController : public QObject
{
    Q_OBJECT
public:
    explicit IODbfController(QObject *parent = nullptr);
    Q_INVOKABLE void invokableWriteFile(DBFFileInfo* dbfFileInfo);
    Q_INVOKABLE void invokableReadFile(DBFFileInfo* dbfFileInfo);
signals:

};

#endif // IODBFCONTROLLER_H
