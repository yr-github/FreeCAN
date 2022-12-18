#ifndef DBFFILEINFO_H
#define DBFFILEINFO_H

#include <QObject>
#include <QBitArray>
#include <vector>
#include <map>
#include "../CommonEnum.h"

struct Signal{
    explicit Signal(const QString &signalName,
                    int startBit,
                    int byteindex,
                    int length,
                    qint64 minValue,
                    qint64 maxValue,
                    float signalFactor,
                    float signalOffset,
                    FreeCANEnum::SIGNAL_VALUE_TYPE valueType,
                    const QString &unit,
                    FreeCANEnum::SIGNAL_ORDER_TYPE orderType);
    QString sSignalName;
    int iStartBit;
    int iEndBit;
    int iByteindex;
    int iLength;
    qint64 iMinValue;
    qint64 iMaxValue;
    float  fSignalFactor;
    float  fSignalOffset;
    FreeCANEnum::SIGNAL_VALUE_TYPE eValueType;
    QString sUnit;
    FreeCANEnum::SIGNAL_ORDER_TYPE eOrderType;//motorola or intel

    bool isBitsInSignal(const int &iBit) const;
    bool operator==(const Signal& signal);
    bool operator<(const Signal& signal);
    bool operator>(const Signal& signal);
    bool operator>=(const Signal& signal);
    bool operator<=(const Signal& signal);
};

struct Message{
    explicit Message(int id,int len,QString messageName,bool isStandard,bool isIntel=true);
    int iID;
    int iLength;
    QString sMessageName;
    bool bIsIntel;//default true
    bool bIsStandard;
    std::vector<Signal> vSignals;
    bool isBitsInMessage(const int &iBit)const;
    bool isSignalInMessage(const QString &sSignal);
    bool operator==(const Message& message);
    bool operator<(const Message& message);
    bool operator>(const Message& message);
    bool operator>=(const Message& message);
    bool operator<=(const Message& message);
};



class DBFFileInfo :public QObject
{
    Q_OBJECT
public:    
    explicit DBFFileInfo(QObject *parent = nullptr);
    Q_PROPERTY(QString fileName READ sFilename WRITE setSFilename NOTIFY signalFilenameChanged);    

    const QString &sFilename() const;
    void setSFilename(const QString &newSFilename);    
    const std::vector<Message> &vMessages() const;
    void setVMessages(const std::vector<Message> &newVMessages);
    const std::vector<Signal> &GetCurrentSignalsById(int iId) const;
    void clearVMessages();
    Q_INVOKABLE void invokableAddVMessages(const QString &iId,const QString &iLength,const QString &m_sMessageName, const bool bIsStandard,const bool bIsIntel);
    Q_INVOKABLE void invokableAddSignal(int iId,const QString &signalName,const QString &startBit,const QString & byteindex,const QString & length
                                        ,const QString & minValue,const QString & maxValue, const QString & signalFactor,const QString & signalOffset,FreeCANEnum::SIGNAL_VALUE_TYPE valueType,
                                        const QString &unit,FreeCANEnum::SIGNAL_ORDER_TYPE orderType);
    Q_INVOKABLE int invokableGetIdByName(const QString &sName);
    Q_INVOKABLE QString invokableGetBitsColor(const int &iId,const int &index);

signals:
    void signalBegainResetMessage();
    void signalEndResetMessage();
    void signalFilenameChanged();
    void signalMessageAdd();
    void preMessageAppended();
    void postMessageAppended();

    void preSignalAppended(int id);
    void postSignalAppended();
private:

    QString m_sFilename;
    std::vector<Message> m_vMessages;
    std::map<QString,int> m_mNameId;

};

#endif // DBFFILEINFO_H
