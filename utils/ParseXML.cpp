#include "ParseXML.h"
#include "Log.h"
ParseXML::ParseXML(const QString& file)
{
    LOG_INFO(file);
    LOG_DEBUG("1",2,3.0,"wyrrrr");
    Log log(file);
    LOG_INFO(file);
    LOG_DEBUG("1",2,3.0,"wyrrrr");
//    Log::logs("1",2,3.0,"wyrrrr");
//    Log::logs("1",2,3.00000,"wyrrrr");
//    Log::logs("1",2,3.00000,"wyrrrr","sss","asdas",12);
}
