import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import DBFFileInfo 1.0


Window {
    id:messageDialog
    flags: Qt.Tool
    modality: Qt.WindowModal
    title: "Add Message"
    width: 400
    property alias invokMessageId: messageIDField.text
    property alias invokMessageName: messageNameField.text

    ColumnLayout{
        RowLayout{
            Text {
                id: text3
                height: 22
                text: qsTr("New Message ID: 0X")
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                clip: true
            }
            TextInput {
                id: messageIDField
                Layout.maximumWidth: 60
                Layout.minimumWidth: 60
                height: 23
                //TODO Question:GUI use HEX , But backend use DEC currently
                //when implement send data module to determin use DEC or HEX on backend
                validator: RegularExpressionValidator { regularExpression: /[0-9a-fA-F]+/ }
                onTextEdited: text=text.toUpperCase()
                onTextChanged: text=text.toUpperCase()
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
