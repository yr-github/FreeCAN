#ifndef DBFFILEINFO_H
#define DBFFILEINFO_H

#include <QObject>
#include <QBitArray>
#include <vector>
#include <map>

struct Signal{
    explicit Signal(QString signalName,int startBit,int endBit);
    QString sSignalName;
    int iStartBit;
    int iEndBit;
    bool isBitsInSignal(const int &iBit) const;
    bool operator==(const Signal& signal);
    bool operator<(const Signal& signal);
    bool operator>(const Signal& signal);
    bool operator>=(const Signal& signal);
    bool operator<=(const Signal& signal);
};

struct Message{
    explicit Message(int id,int len,QString messageName);
    int iID;
    int iLength;
    QString sMessageName;
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
    Q_INVOKABLE void invokableAddVMessages(const QString &iId,const QString &iLength,const QString &m_sMessageName);
    Q_INVOKABLE void invokableAddSignal(int iId,const QString &sSingalName,const QString &iStartBit,const QString &iEndBit);
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
