#ifndef PARSEXML_H
#define PARSEXML_H

#include <QObject>
#include <QtXml/QDomDocument>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include "src/Model/DBFFileInfo.h"

class ParseXML
{
public:
    explicit ParseXML();
    void WriteFile(const DBFFileInfo* dbfInfo);
    void ReadFile(DBFFileInfo* dbfInfo);
};

#endif // PARSEXML_H
