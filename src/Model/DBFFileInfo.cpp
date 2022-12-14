#include "DBFFileInfo.h"
#include "../CommonEnum.h"

DBFFileInfo::DBFFileInfo(QObject *parent): QObject(parent),
    m_sFilename("NewFile")
{
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

const std::vector<Signal> &DBFFileInfo::GetCurrentSignalsById(int iId) const
{

    for(const auto & messgae:m_vMessages){
        if(messgae.iID==iId){
            return messgae.vSignals;
        }
    }
    //TODO Feature this is a error state
    return m_vMessages.begin()->vSignals;
}

void DBFFileInfo::clearVMessages()
{
    emit signalBegainResetMessage();
    m_vMessages.clear();
    emit signalEndResetMessage();
}

void DBFFileInfo::invokableAddVMessages(const QString &iId,const QString &iLength,const QString &sMessageName)
{
    bool _;
    if(m_mNameId.find(sMessageName)==m_mNameId.end()){
        m_mNameId[sMessageName]=iId.toInt(&_,NUM_FORMART::HEX);
    }else{
        //TODO: Feature alert user
    }
    emit preMessageAppended();
    m_vMessages.push_back(Message(iId.toInt(&_,NUM_FORMART::HEX),iLength.toInt(),sMessageName));
    emit postMessageAppended();
}


void DBFFileInfo::invokableAddSignal(int iId,const QString &sSingalName,const QString &iStartBit,const QString &iEndBit)
{
    for(auto &message:m_vMessages){
        if(message.iID==iId){
            emit preSignalAppended(iId);
            message.vSignals.push_back(Signal(sSingalName,iStartBit.toInt(),iEndBit.toInt()));
            emit postSignalAppended();
            return;
        }
    }
}

int DBFFileInfo::invokableGetIdByName(const QString &sName)
{
    if(m_mNameId.find(sName)==m_mNameId.end()){
        return 0;
    }
    return m_mNameId.at(sName);
}

QString DBFFileInfo::invokableGetBitsColor(const int &iId, const int &index)
{
    for(const auto &message : m_vMessages){
        if(iId==message.iID){
            if(message.isBitsInMessage(index)){
                return "blue";
            }else{
                return "gray";
            }
        }
    }
    return "gray";
}


Message::Message(int id, int len, QString messageName):iID(id),
    iLength(len),
    sMessageName(messageName)
{

}

bool Message::isBitsInMessage(const int &iBit) const
{
    bool result = false;
    for(const auto& signal: vSignals){
        if(signal.isBitsInSignal(iBit)){
            result = true;
            break;
        }
    }
    return result;
}

bool Message::isSignalInMessage(const QString &sSignal)
{
    bool result = false;
    for(const auto& signal: vSignals){
        if(signal.sSignalName==sSignal){
            result=true;
            break;
        }
    }
    return result;
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

bool Signal::isBitsInSignal(const int &iBit) const
{
    return iBit>=iStartBit && iBit<=iEndBit;
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
