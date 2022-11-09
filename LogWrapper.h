#ifndef LOGWRAPPER_H
#define LOGWRAPPER_H

#include <QObject>

class LogWrapper : public QObject
{
    Q_OBJECT
public:
    explicit LogWrapper(QObject *parent = nullptr);
    Q_INVOKABLE void invokableLog(QString info);
    Q_INVOKABLE void closeLog();
signals:

};

#endif // LOGWRAPPER_H
