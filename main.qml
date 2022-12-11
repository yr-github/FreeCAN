import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "view/menu/"
import "widgets"
import LogWrapper 1.0
import PlayBackController 1.0
import QtQuick.Dialogs

ApplicationWindow {
    id:root
    width: 1080
    height: 720
    visible: true
    title: qsTr("FreeCAN")
    signal newFile();
    signal openFile(fileName: string);
    signal saveFile(fileName: string);
    signal saveAsFile();
    menuBar:  MenuBar {
        Menu {
            id: plugins_menu
            title: qsTr("Plugins")
        }
        Menu{
            id: file_menu
            title: qsTr("File")
            width: 70
            MenuItem{
                text: qsTr("New File")
                onTriggered: {
                    root.newFile()
                }
            }
            MenuItem{
                text: qsTr("Open")
                onTriggered: {                    
                    dbfFileDialog.fileMode=FileDialog.OpenFile
                    dbfFileDialog.open()                    
                }
            }
            MenuItem{
                text: qsTr("Save File")
                onTriggered: {
                    dbfFileDialog.fileMode=FileDialog.SaveFile
                    dbfFileDialog.open()                    
                }
            }
            MenuItem{
                text: qsTr("Save As...")
                onTriggered: {
                    root.saveAsFile()
                }
            }
        }
    }

    AddMSG {
        id:directAddmsg
        anchors.fill: parent
    }
    Trigger {
        id:trigger
        visible: false
        anchors.fill: parent
    }

    DbfFileDialog{
        id:dbfFileDialog
        onAccepted: {
            //TODO Bug: why fileUrl didn't work as help docs illustrate?
            //console.log(dbfFileDialog.fileUrl," : ",dbfFileDialog.file,":",dbfFileDialog.currentFile)
            fileMode===FileDialog.SaveFile?root.saveFile(dbfFileDialog.currentFile):root.openFile(dbfFileDialog.currentFile)
        }
    }

    Connections {
        target: PlayBackController
        function onSignaleUserEvent(strEventId){
            console.log(strEventId)
        }        
    }

    onClosing: {
        LogWrapper.invokableCloseLog()
    }
    Component.onCompleted: {

    }
}
