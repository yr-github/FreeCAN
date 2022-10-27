import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "view/menu/"

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
    Rectangle {
        id: rectangle
        anchors.fill: parent
        Button {
            id: button
            x: 21
            y: 17
            text: qsTr("Button")
            anchors.left: parent.left
            anchors.top: parent.top
            onClicked: {
               directAddmsg.show()
            }
        }
    }
}