import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "view/menu/"
import "widgets"
import LogWrapper 1.0
import PlayBackController 1.0

ApplicationWindow {
    id:root
    width: 640
    height: 480
    visible: true
    title: qsTr("FreeCAN")
    menuBar: MenuBar {
        Menu {
            id: plugins_menu
            title: qsTr("Plugins")
        }
        Menu{
            id: file_menu
            title: qsTr("File")
        }
    }
    AddMSG {
        id:directAddmsg
        onClosing:{
            console.log("wyr::ondirectAddmsgClosing")
        }
    }
    Trigger {
        id:trigger
        anchors.fill: parent
    }

    Connections {
        target: PlayBackController
        function onSignaleUserEvent(strEventId){
            console.log(strEventId)
        }
    }

    onClosing: {
        LogWrapper.closeLog()
    }
}
