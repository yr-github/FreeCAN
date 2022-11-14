#ifndef PLAYBACKCONTROLLER_H
#define PLAYBACKCONTROLLER_H

#include <QObject>
#include"src/LogModule.h"

enum PLAYTYPE{
    USER = 0,
    OUTPUT
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


private:
    void DisableAllWidgets();
    std::vector<LogModule> m_VLlogList;
    PLAYTYPE m_Ptype;
    QString m_SfileName;
    void playUserLog();
    void playOutPutLog();


signals:

};

#endif // PLAYBACKCONTROLLER_H
