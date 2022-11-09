#include "Log.h"

#include <iostream>
//TODO： four log
//log 1: user click
//log 2: output
//log 3: input
//log 4: debug log
//all the log have timestamp
//make a text reader can mix log 1 2 3 4
//use timestamp to sort, difrent log have different bgcolor.
static Log* m_pUserLog = nullptr;
static Log* m_pInputLog = nullptr;
static Log* m_pOutputLog = nullptr;
static Log* m_pDebugLog = nullptr;

Log *Log::getUserLogInstance()
{
    if(m_pUserLog==nullptr){
        m_pUserLog=static_cast<Log*>(new(Log));
        m_pUserLog->setPOutFile(new QFile("User.log"));
        if (!m_pUserLog->getFile()->open(QIODevice::WriteOnly | QIODevice::Text))
            return nullptr;
        m_pUserLog->setPOutStream(new QTextStream(m_pUserLog->getFile()));
    }
    return m_pUserLog;
}

Log *Log::getInputLogInstance()
{
    if(m_pInputLog==nullptr){
        m_pInputLog=static_cast<Log*>(new(Log));
        m_pInputLog->setPOutFile(new QFile("Input.log"));
        if (!m_pInputLog->getFile()->open(QIODevice::WriteOnly | QIODevice::Text))
            return nullptr;
        m_pInputLog->setPOutStream(new QTextStream(m_pInputLog->getFile()));
    }
    return m_pInputLog;
}

Log *Log::getOutputLogInstance()
{
    if(m_pOutputLog==nullptr){
        m_pOutputLog=static_cast<Log*>(new(Log));
        m_pOutputLog->setPOutFile(new QFile("Output.log"));
        if (!m_pOutputLog->getFile()->open(QIODevice::WriteOnly | QIODevice::Text))
            return nullptr;
        m_pOutputLog->setPOutStream(new QTextStream(m_pOutputLog->getFile()));
    }
    return m_pOutputLog;
}

Log *Log::getDebugLogInstance()
{
    if(m_pDebugLog==nullptr){
        m_pDebugLog=static_cast<Log*>(new(Log));
        m_pDebugLog->setPOutFile(new QFile("Debug.log"));
        if (!m_pDebugLog->getFile()->open(QIODevice::WriteOnly | QIODevice::Text))
            return nullptr;
        m_pDebugLog->setPOutStream(new QTextStream(m_pDebugLog->getFile()));
    }
    return m_pDebugLog;
}

void Log::setPOutFile(QFile *newPOutFile)
{
    m_pOutFile = newPOutFile;
}

QFile *Log::getFile()
{
    return m_pOutFile;
}

void Log::setPOutStream(QTextStream *newPOutStream)
{
    m_pOutStream = newPOutStream;
}

QTextStream *Log::getOutStream()
{
    return m_pOutStream;
}

Log::~Log()
{

}

Log::Log()
{

}

void Log::destroyInstance(Log* pLog){
    if(pLog){
        LOG_DEBUG("Log destuctor")
        pLog->getFile()->close();
        delete pLog->m_pOutFile;
        delete pLog->m_pOutStream;
        delete pLog;
        pLog = nullptr;
    }
}

//TODO: call this when user stop software
void Log::destroyLog()
{
    m_pUserLog->destroyInstance(m_pUserLog);
    m_pOutputLog->destroyInstance(m_pOutputLog);
    m_pInputLog->destroyInstance(m_pInputLog);
    m_pDebugLog->destroyInstance(m_pDebugLog);
}



