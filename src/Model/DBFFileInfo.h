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
    Q_INVOKABLE void invokableAddVMessages(const QString &iId,const QString &iLength,const QString &m_sMessageName);
    Q_INVOKABLE void invokableAddSignal(const QString &iId,const QString &sSingalName,const QString &iStartBit,const QString &iEndBit);

signals:
    void signalFilenameChanged();
    void signalMessageAdd();
    void preMessageAppended();
    void postMessageAppended();

private:

    QString m_sFilename;
    std::vector<Message> m_vMessages;

};

#endif // DBFFILEINFO_H
