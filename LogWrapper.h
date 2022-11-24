#ifndef LOGWRAPPER_H
#define LOGWRAPPER_H

#include <QObject>

class LogWrapper : public QObject
{
    Q_OBJECT
public:
    explicit LogWrapper(QObject *parent = nullptr);
    Q_INVOKABLE void invokableUserLog(QString info, QString action);
    Q_INVOKABLE void invokableDebugLog(QString info, QString errorID);
    Q_INVOKABLE void invokableCloseLog();
signals:

};

#endif // LOGWRAPPER_H
