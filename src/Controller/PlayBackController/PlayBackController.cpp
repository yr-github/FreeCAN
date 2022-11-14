#include "PlayBackController.h"
#include <QFile>
#include "utils/Log.h"
PlayBackController::PlayBackController(QObject *parent) : QObject(parent),
    m_Ptype(USER),
    m_SfileName("test.log")
{

}

void PlayBackController::invokUserLogPlayBack()
{

}

void PlayBackController::invokOutPutLogPlayBack()
{

}

void PlayBackController::invokStartPlayBack()
{
    switch (m_Ptype) {
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

    QFile file(m_SfileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        //TODO: alert user
        return;
    }
    //TODO: need thread
    std::vector<LogModule> VlogModules;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        QList<QByteArray> lineSplits = line.split(',');
        LogModule logModule;
        std::vector<std::string> lineLogs;
        for(auto split :lineSplits){
            lineLogs.push_back(split.toStdString());
        }
        logModule.setVSlogs(lineLogs);
        //TODO: need to dig out why this code cause crash.
        //QString time = QString::fromUtf8(lineLogs.end()->c_str());
        QString time = QString(lineLogs.at(lineLogs.size()-1).c_str());
        logModule.setLtime(time.toLongLong());
        VlogModules.push_back(logModule);
    }
    std::vector<LogModule>::iterator iter=VlogModules.begin();

    for(;iter!=VlogModules.end();){
        std::vector<LogModule>::iterator currentIter = iter++;
        if(iter!=VlogModules.end()){
            LOG_DEBUG("diff is: ",iter->Ltime()-currentIter->Ltime());
        }
    }
    return;
}
