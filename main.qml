import Qt.labs.platform 1.1 as Platform
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "view/menu/"
import "widgets"
import LogWrapper 1.0
import PlayBackController 1.0


ApplicationWindow {
    id:root
    width: 1080
    height: 720
    visible: true
    title: qsTr("FreeCAN")
    signal newFile();
    signal openFile();
    signal saveFile();
    signal saveAsFile();
    menuBar: MenuBar {
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
                    root.openFile()
                }
            }
            MenuItem{
                text: qsTr("Save File")
                onTriggered: {
                    root.saveFile()
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

    Connections {
        target: PlayBackController
        function onSignaleUserEvent(strEventId){
            console.log(strEventId)
        }
    }

    onClosing: {
        LogWrapper.invokableCloseLog()
    }
}
