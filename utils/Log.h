#pragma once
#ifndef LOG_H
#define LOG_H
/*
 *
 *
 *
 *
*/
#include <QObject>
#include <iostream>
#include <QTextStream>
#include <QFile>
#define LOG_INFO( x ) if(Log::getInstance()!=nullptr) Log::getInstance()->log(__FILE__, __LINE__,x);
#define LOG_DEBUG(x...) if(Log::getInstance()!=nullptr) Log::getInstance()->logs(__FILE__, __LINE__,x);

class Log
{
public:
    explicit Log(const QString& logfile);
    static Log* getInstance();
    void log(const char* file,int line,const QString& info);
    QFile* getFile();
    QTextStream* getOutStream();
    template<typename T>
    void writeFile(T& info){
        this->getFile()->write(QString(info).toStdString().c_str());
    }
    template<typename T>
    static void logs(const T& arg){
        *(Log::getInstance()->getOutStream())<<arg<<"\n";
    }
    template<typename T ,typename ... Args>
    static void logs(const T& arg,const Args& ... pargs){
        *(Log::getInstance()->getOutStream())<<arg<<",";
        logs(pargs...);
    }
    ~Log();
private:
    Log();
    QFile* outfile;
    QTextStream* outStream;
};


#endif // LOG_H
