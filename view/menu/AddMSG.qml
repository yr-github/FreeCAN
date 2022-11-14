import QtQuick 2.2
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window{
    title: "Add MSG"
    visible: false
    id:root_window
    Rectangle {
        width: 600
        height: 400
        visible: true
        id:page
        TextField {
            id: textField
            x: 100
            y: 16
            width: 139
            height: 23
            placeholderText: qsTr("MSG Name")
        }

        TextField {
            id: textField1
            x: 346
            y: 16
            width: 122
            height: 23
            placeholderText: qsTr("Text Field")
        }

        Text {
            id: text1
            x: 8
            y: 16
            width: 86
            height: 23
            text: qsTr("Message Name：")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            clip: true
        }

        Text {
            id: text2
            x: 260
            y: 17
            width: 80
            height: 22
            text: qsTr("Message ID")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            clip: true
        }

        Text {
            id: text3
            x: 8
            y: 58
            width: 76
            height: 20
            text: qsTr("Add Signal:")
            font.pixelSize: 12
            verticalAlignment: Text.AlignVCenter
        }

        Image {
            id: image
            x: 82
            y: 53
            width: 30
            height: 30
            source: "qrc:/pic/plus_icon.svg"
            fillMode: Image.PreserveAspectFit
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("wyr::clicked")
                }
            }
        }
    }
    Dialog {
        id: dialog
        title: "Title"
        property bool isOk: true

        standardButtons: Dialog.Ok | Dialog.Cancel

        onAccepted: {console.log("Ok clicked")
        dialog.isOk=true}
        onRejected: {console.log("Cancel clicked")
            dialog.isOk=false
        }
    }
    onClosing:{

        dialog.visible=true
        close.accepted = false
        if(dialog.isOk){
            close.accepted = true
            console.log("wyr::onClosing1111")
        }
        else{
            close.accepted = false
            console.log("wyr::onClosing22222")
        }
    }
}
