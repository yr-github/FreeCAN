#include "ParseXML.h"
#include "Log.h"
#include "../src/CommonEnum.h"
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
        stream.writeAttribute("ID",  QString::number(message.iID,FreeCANEnum::NUM_FORMART::HEX));
        stream.writeAttribute("Length",  QString::number(message.iLength));
        stream.writeAttribute("FrameFormat",  QString::number(message.bIsStandard));
        stream.writeAttribute("DataFormat",  QString::number(message.bIsIntel));
        for(const auto& signal:message.vSignals){
            stream.writeStartElement("Signal");
            stream.writeAttribute("Name",signal.sSignalName);
            stream.writeAttribute("StartBit",QString::number(signal.iStartBit));
            stream.writeAttribute("ByteIndex",QString::number(signal.iByteindex));
            stream.writeAttribute("Length",QString::number(signal.iLength));
            stream.writeAttribute("MinValue",QString::number(signal.iMinValue));
            stream.writeAttribute("MaxValue",QString::number(signal.iMaxValue));
            stream.writeAttribute("Factor",QString::number(signal.fSignalFactor));
            stream.writeAttribute("Offset",QString::number(signal.fSignalOffset));
            stream.writeAttribute("ValueType",QString::number(signal.eValueType));
            stream.writeAttribute("Unit",signal.sUnit);
            stream.writeAttribute("OrderType",QString::number(signal.eOrderType));
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
            dbfInfo->invokableAddVMessages(message.attribute("ID"),message.attribute("Length"),message.attribute("Name"),message.attribute("FrameFormat")==QStringLiteral("1")
                                           ,message.attribute("DataFormat")==QStringLiteral("1"));
            QDomNode signalComponent = message.firstChild();
            while (!signalComponent.isNull()) {
                QDomElement signalDetail = signalComponent.toElement();
                //dbfInfo->invokableAddSignal(message.attribute("ID").toInt(),signalDetail.attribute("Name"),signalDetail.attribute("StartBit"),signalDetail.attribute("EndBit"));
                dbfInfo->invokableAddSignal(message.attribute("ID").toInt(),
                                            signalDetail.attribute("Name"),
                                            signalDetail.attribute("StartBit"),
                                            signalDetail.attribute("ByteIndex"),
                                            signalDetail.attribute("Length"),
                                            signalDetail.attribute("MinValue"),
                                            signalDetail.attribute("MaxValue"),
                                            signalDetail.attribute("Factor"),
                                            signalDetail.attribute("Offset"),
                                            static_cast<FreeCANEnum::SIGNAL_VALUE_TYPE>(signalDetail.attribute("ValueType").toInt()),
                                            signalDetail.attribute("Unit"),
                                            static_cast<FreeCANEnum::SIGNAL_ORDER_TYPE>(signalDetail.attribute("OrderType").toInt()));
                signalComponent = signalComponent.nextSibling();
            }
        }
        messageComponent = messageComponent.nextSibling();
    }
}
