#include "LogWrapper.h"
#include "utils/Log.h"
#include "src/LogModule.h"
LogWrapper::LogWrapper(QObject *parent) : QObject(parent)
{

}

void LogWrapper::invokableUserLog(QString info, QString action)
{
    LOG_USER(info,action);
}

void LogWrapper::invokableDebugLog(QString info, QString errorID)
{
    LOG_DEBUG(info,errorID);
}

void LogWrapper::invokableCloseLog()
{
    Log::destroyLog();
}
