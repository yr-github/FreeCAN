#include "LogWrapper.h"
#include "utils/Log.h"
#include "src/LogModule.h"
LogWrapper::LogWrapper(QObject *parent) : QObject(parent)
{

}

void LogWrapper::invokableLog(QString info)
{
 LOG_DEBUG(info);
}

void LogWrapper::closeLog()
{
    Log::destroyLog();
}
