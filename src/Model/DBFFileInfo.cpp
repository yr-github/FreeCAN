#include "DBFFileInfo.h"


DBFFileInfo::DBFFileInfo(QObject *parent): QObject(parent),
    m_sFilename("New file")
{
m_vMessages.push_back(Message(123,8,"SSS"));
}

const QString &DBFFileInfo::sFilename() const
{
    return m_sFilename;
}

void DBFFileInfo::setSFilename(const QString &newSFilename)
{
    m_sFilename = newSFilename;
    emit signalFilenameChanged();
}

const std::vector<Message> &DBFFileInfo::vMessages() const
{
    return m_vMessages;
}

void DBFFileInfo::setVMessages(const std::vector<Message> &newVMessages)
{
    m_vMessages = newVMessages;
}

void DBFFileInfo::invokableAddVMessages(const QString &iId,const QString &iLength,const QString &sMessageName)
{
    emit preMessageAppended();
    m_vMessages.push_back(Message(iId.toInt(),iLength.toInt(),sMessageName));
    emit postMessageAppended();
}


void DBFFileInfo::invokableAddSignal(const QString &iId,const QString &sSingalName,const QString &iStartBit,const QString &iEndBit)
{
    for(auto &message:m_vMessages){
        if(message.iID==iId.toInt()){
            message.vSignals.push_back(Signal(sSingalName,iStartBit.toInt(),iEndBit.toInt()));
        }
    }
}

Message::Message(int id, int len, QString messageName):iID(id),
    iLength(len),
    sMessageName(messageName)
{

}

bool Message::operator==(const Message &message)
{
    return this->iID==message.iID;
}

bool Message::operator<(const Message &message)
{
    return this->iID<message.iID;
}

bool Message::operator>(const Message &message)
{
    return this->iID>message.iID;
}

bool Message::operator>=(const Message &message)
{
    return this->iID>=message.iID;
}

bool Message::operator<=(const Message &message)
{
    return this->iID<=message.iID;
}

Signal::Signal(QString signalName, int startBit, int endBit):sSignalName(signalName),
    iStartBit(startBit),
    iEndBit(endBit)
{

}

bool Signal::operator==(const Signal &signal)
{
    return this->iStartBit==signal.iStartBit;
}

bool Signal::operator<(const Signal &signal)
{
    return this->iStartBit<signal.iStartBit;
}

bool Signal::operator>(const Signal &signal)
{
    return this->iStartBit>signal.iStartBit;
}

bool Signal::operator>=(const Signal &signal)
{
    return this->iStartBit>=signal.iStartBit;
}

bool Signal::operator<=(const Signal &signal)
{
    return this->iStartBit<=signal.iStartBit;
}
