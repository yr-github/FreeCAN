import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import DBFFileInfo 1.0


Window {
    id:messageDialog
    flags: Qt.Tool
    modality: Qt.WindowModal
    title: "Add Message"
    width: 400

    ColumnLayout{
        RowLayout{
            Text {
                id: text3
                height: 22
                text: qsTr("New Message ID: ")
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                clip: true
            }
            TextField {
                id: messageIDField
                Layout.maximumWidth: 60
                height: 23
            }
            Text {
                id: text4
                height: 22
                text: qsTr("Name: ")
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                clip: true
            }
            TextField {
                id: messageNameField
                Layout.maximumWidth: 100
                height: 23
            }
        }
        RowLayout{
            Text {
                id: text5
                height: 22
                text: qsTr("Length(Byte): ")
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                clip: true
            }
            TextField {
                id: messageLengthField
                height: 23
                Layout.maximumWidth: 30
            }
            Button{
                id: buttonAddMessage
                text: qsTr("Add Message")
                onClicked: {
                    //TODO: Feature add alert if property is wrong
                    DBFFileInfo.invokableAddVMessages(messageIDField.text,messageLengthField.text,messageNameField.text)
                }
            }
        }
    }
}
