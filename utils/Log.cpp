#include "Log.h"

#include <iostream>
static Log* m_pLog = nullptr;
Log::Log(const QString& logfile)
{
    if(m_pLog==nullptr){
        m_pLog=static_cast<Log*>(new(Log));
        m_pLog->outfile = new QFile(logfile);
        if (!m_pLog->outfile->open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        m_pLog->outStream =new QTextStream(m_pLog->getFile());
        *(m_pLog->getOutStream()) << "The magic number is: " << 49 << "\n";

    }
}

Log *Log::getInstance()
{
    return m_pLog;
}

void Log::log(const char* file, int line,const QString& info)
{
    std::cout<<"wyr::"<<info.toStdString()<<file<<line<<std::endl;
}

QFile *Log::getFile()
{
    return outfile;
}

QTextStream *Log::getOutStream()
{
    return outStream;
}

Log::~Log()
{
    m_pLog->getFile()->close();
}

Log::Log()
{

}

