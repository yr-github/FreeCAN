#include "IODbfController.h"
#include "utils/ParseXML.h"
IODbfController::IODbfController(QObject *parent) : QObject(parent)
{

}

void IODbfController::invokableWriteFile(DBFFileInfo * dbfFileInfo)
{
    ParseXML parseXmlObj;
    parseXmlObj.WriteFile(dbfFileInfo);
}

void IODbfController::invokableReadFile(DBFFileInfo *dbfFileInfo)
{
    //TODO Feature alert user will clear current dbfinfo
    dbfFileInfo->clearVMessages();
    ParseXML parseXmlObj;
    parseXmlObj.ReadFile(dbfFileInfo);
}
