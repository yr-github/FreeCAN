#ifndef PLAYBACKCONTROLLER_H
#define PLAYBACKCONTROLLER_H

#include <QObject>
#include <QThread>
#include"src/LogModule.h"

enum PLAYTYPE{
    USER = 0,
    OUTPUT
};

class PlayBackThread : public QThread
{
    Q_OBJECT
public:
    PlayBackThread(const QString &SfileName, PLAYTYPE Etype);

    void run() override;

    void setSfileName(const QString &newSfileName);

    void setEtype(PLAYTYPE newEtype);
signals:
    void signaleUserEvent(QString);
private:
    void runUserPlayBack();
    void runOutPutPlayBack();
    QString m_SfileName;
    PLAYTYPE m_Etype;
};

class PlayBackController : public QObject
{
    Q_OBJECT
public:
    explicit PlayBackController(QObject *parent = nullptr);
    Q_INVOKABLE void invokUserLogPlayBack();
    Q_INVOKABLE void invokOutPutLogPlayBack();
    Q_INVOKABLE void invokStartPlayBack();
    Q_INVOKABLE void invokStopPlayBack();
    Q_INVOKABLE void invokPausePlayBack();

signals:
    void signaleUserEvent(QString);
private:
    void DisableAllWidgets();
    void playUserLog();
    void playOutPutLog();
private:
    std::vector<LogModule> m_VLlogList;
    PLAYTYPE m_Etype;
    QString m_SfileName;
    PlayBackThread* m_pPlbackThread;


signals:

};

#endif // PLAYBACKCONTROLLER_H
