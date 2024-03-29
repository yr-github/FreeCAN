#include "PlayBackController.h"
#include <QFile>
#include "utils/Log.h"

PlayBackController::PlayBackController(QObject *parent) : QObject(parent),
    m_Etype(USER),
    m_SfileName("USER1.log"),
    m_pPlbackThread(nullptr)
{
    m_VLlogList.clear();
}

void PlayBackController::invokUserLogPlayBack()
{

}

void PlayBackController::invokOutPutLogPlayBack()
{

}

void PlayBackController::invokStartPlayBack()
{
    switch (m_Etype) {
    case USER:
        playUserLog();
        break;
    case OUTPUT:
        break;
    default:
        break;
    }
}

void PlayBackController::invokStopPlayBack()
{

}

void PlayBackController::invokPausePlayBack()
{

}

void PlayBackController::playUserLog()
{
    m_pPlbackThread = new PlayBackThread(m_SfileName,USER);
    //TODO: Feature :connect pause end signal
    connect(m_pPlbackThread,&PlayBackThread::signaleUserEvent,this,&PlayBackController::signaleUserEvent);
    m_pPlbackThread->start();
}

void PlayBackThread::run()
{
    switch (m_Etype) {
    case PLAYTYPE::USER:
        runUserPlayBack();
        break;
    case PLAYTYPE::OUTPUT:
        runOutPutPlayBack();
        break;
    default://TODO: Feature need to think what to do here
        break;
    }
}

void PlayBackThread::setSfileName(const QString &newSfileName)
{
    m_SfileName = newSfileName;
}

void PlayBackThread::setEtype(PLAYTYPE newEtype)
{
    m_Etype = newEtype;
}

void PlayBackThread::runUserPlayBack()
{
    //TODO: Feature: if need log then log instance need lock and that is expensive
    QFile file(m_SfileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        //TODO: Feature alert user
        return;
    }
    std::vector<LogModule> VlogModules;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        QList<QByteArray> lineSplits = line.split(',');
        LogModule logModule;
        std::vector<std::string> lineLogs;
        for(const auto &split : lineSplits){
            lineLogs.push_back(split.toStdString());
        }
        logModule.setVSlogs(lineLogs);
        //TODO: Question : need to dig out why this code cause crash.
        //QString time = QString::fromUtf8(lineLogs.end()->c_str());
        QString time = QString(lineLogs.at(lineLogs.size()-1).c_str());
        QString eventId = QString(lineLogs.at(0).c_str());
        emit signaleUserEvent(eventId);
        logModule.setLtime(time.toLongLong());
        VlogModules.push_back(logModule);
    }
    std::vector<LogModule>::iterator iter=VlogModules.begin();
    //TODO: Feature :read line one by one, don't push them into memorry once a time.
    for(;iter!=VlogModules.end();){
        std::vector<LogModule>::iterator currentIter = iter++;
        if(iter!=VlogModules.end()){
            LOG_DEBUG("diff is: ",iter->Ltime()-currentIter->Ltime());
        }
    }
    return;
}

void PlayBackThread::runOutPutPlayBack()
{

}

PlayBackThread::PlayBackThread(const QString &SfileName, PLAYTYPE Etype) : m_SfileName(SfileName),
    m_Etype(Etype)
{}
