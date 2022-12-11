#include "IODbfController.h"
#include "utils/ParseXML.h"
IODbfController::IODbfController(QObject *parent) : QObject(parent)
{

}

void IODbfController::invokableWriteFile(DBFFileInfo * dbfFileInfo, const QString& fileName)
{
    ParseXML parseXmlObj;
    //TODO Perf: Too many place modify the DBFFileInfo
    //may be I should detached filename and DBFFileInfo
    QString file(fileName);
    dbfFileInfo->setSFilename(file.replace("file:///",""));
    parseXmlObj.WriteFile(dbfFileInfo);
}

void IODbfController::invokableReadFile(DBFFileInfo *dbfFileInfo, const QString& fileName)
{
    //TODO Feature alert user will clear current dbfinfo
    dbfFileInfo->clearVMessages();
    ParseXML parseXmlObj;
    QString file(fileName);
    dbfFileInfo->setSFilename(file.replace("file:///",""));
    parseXmlObj.ReadFile(dbfFileInfo);
}
