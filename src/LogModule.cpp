#include "LogModule.h"

LogModule::LogModule() : m_Ltime(0)
{
    m_VSlogs.clear();
}

bool LogModule::operator==(const LogModule &rLog)
{
    return this->m_Ltime==rLog.m_Ltime;
}

bool LogModule::operator!=(const LogModule &rLog)
{
    return this->m_Ltime!=rLog.m_Ltime;
}

bool LogModule::operator<=(const LogModule &rLog)
{
    return this->m_Ltime<=rLog.m_Ltime;
}

bool LogModule::operator>=(const LogModule &rLog)
{
    return this->m_Ltime>=rLog.m_Ltime;
}

bool LogModule::operator<(const LogModule &rLog)
{
    return this->m_Ltime<rLog.m_Ltime;
}

bool LogModule::operator>(const LogModule &rLog)
{
    return this->m_Ltime>rLog.m_Ltime;
}

long long LogModule::Ltime() const
{
    return m_Ltime;
}

void LogModule::setLtime(long long newLtime)
{
    m_Ltime = newLtime;
}

const std::vector<std::string> &LogModule::VSlogs() const
{
    return m_VSlogs;
}

void LogModule::setVSlogs(const std::vector<std::string> &newVSlogs)
{
    m_VSlogs = newVSlogs;
}
