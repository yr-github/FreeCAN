#include "ParseXML.h"
#include "Log.h"
ParseXML::ParseXML()
{

}

void ParseXML::WriteFile(const DBFFileInfo *dbfInfo)
{
    if(!dbfInfo){
        return;
    }
    QFile writeFile(dbfInfo->sFilename());
    if(!writeFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }
    QXmlStreamWriter stream(&writeFile);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("DBFFile");
    for(const auto &message:dbfInfo->vMessages()){
        stream.writeStartElement("Message");
        stream.writeAttribute("Name",  message.sMessageName);
        stream.writeAttribute("ID",  QString::number(message.iID));
        stream.writeAttribute("Length",  QString::number(message.iLength));
        for(const auto& signal:message.vSignals){
            stream.writeStartElement("Signal");
            stream.writeAttribute("Name",signal.sSignalName);
            stream.writeAttribute("StartBit",QString::number(signal.iStartBit));
            stream.writeAttribute("EndBit",QString::number(signal.iEndBit));
            stream.writeEndElement();
        }
        stream.writeEndElement();

    }
    stream.writeEndElement();
    stream.writeEndDocument();
    writeFile.close();
}

void ParseXML::ReadFile(DBFFileInfo *dbfInfo)
{
    if(!dbfInfo){
        return;
    }
    QDomDocument doc("myDocument");
    QFile readFile(dbfInfo->sFilename());
    if(!readFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    QString errorMsg;
    int errorLine;
    int errorColumn;
    if(!doc.setContent(&readFile,&errorMsg,&errorLine,&errorColumn)){
        LOG_DEBUG(readFile.fileName(),errorMsg,errorLine,errorColumn)
        readFile.close();
        return;
    }
    readFile.close();
    QDomElement docElem = doc.documentElement();

    QDomNode messageComponent = docElem.firstChild();
    while(!messageComponent.isNull()) {
         QDomElement message = messageComponent.toElement();
         if(!message.isNull()) {
             //std::string sss = message.attribute("Name").toStdString();
             dbfInfo->invokableAddVMessages(message.attribute("ID"),message.attribute("Length"),message.attribute("Name"));
             //std::cout<<message.attribute("Name").toStdString()<<message.attribute("ID").toStdString();
             QDomNode signalComponent = message.firstChild();
             while (!signalComponent.isNull()) {
                QDomElement signalDetail = signalComponent.toElement();
                dbfInfo->invokableAddSignal(message.attribute("ID").toInt(),signalDetail.attribute("Name"),signalDetail.attribute("StartBit"),signalDetail.attribute("EndBit"));
                signalComponent = signalComponent.nextSibling();
             }
         }
         messageComponent = messageComponent.nextSibling();
     }
}
