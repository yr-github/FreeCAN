#pragma once
#ifndef LOG_H
#define LOG_H
/*
 *@Description: Log interface
 *
 *@
 *@author Yuran Wang
*/

#include <QObject>
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <QTime>
#include <QDateTime>

#define LOG_DEBUG(x...) if(Log::getDebugLogInstance()!=nullptr) Log::getDebugLogInstance()->writeLog(__FILE__, __LINE__,x);
#define LOG_USER(x...) if(Log::getUserLogInstance()!=nullptr) Log::getUserLogInstance()->writeLog(x);
#define LOG_INPUT(x...) if(Log::getInputLogInstance()!=nullptr) Log::getInputLogInstance()->writeLog(x);
#define LOG_OUTPUT(x...) if(Log::getOutputLogInstance()!=nullptr) Log::getOutputLogInstance()->writeLog(x);


class Log
{
public:    
    static Log* getUserLogInstance();
    static Log* getInputLogInstance();
    static Log* getOutputLogInstance();
    static Log* getDebugLogInstance();
    static void destroyLog();

    void setPOutFile(QFile *newPOutFile);
    QFile* getFile();
    void setPOutStream(QTextStream *newPOutStream);
    QTextStream* getOutStream();
    ~Log();

public:
    template<typename T>
    void writeLog(const T& arg){
        *(this->getOutStream())<<arg<<","<<QDateTime::currentDateTime().toString("hh:mm:ss.zzz")<<","<<QDateTime::currentMSecsSinceEpoch()<<"\n";

    }
    template<typename T ,typename ... Args>
    void writeLog(const T& arg,const Args& ... pargs){
        *(this->getOutStream())<<arg<<",";
        this->writeLog(pargs...);
    }


private:
    Log();
    void destroyInstance(Log* pLog);
    QFile* m_pOutFile;
    QTextStream* m_pOutStream;
};


#endif // LOG_H
