import QtQuick 2.2
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import DBFFileInfo 1.0
import MessageModel 1.0
Rectangle {
    visible: true
    id:page

    Connections{
        target: DBFFileInfo
    }

    function caculateRelativelyHeight(){
        return 1
    }
    function caculateRelativelyWidth(){
        return 1
    }
    RowLayout{
        id: filenameRow
        anchors{
            top: parent.top
            topMargin: 20
        }
        spacing: 5

        Text {
            id: text1
            height: 23
            text: qsTr("File Name：")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            clip: true
        }
        TextField {
            id: filenameText
            text: DBFFileInfo.fileName
            height: 23           
        }
        Text {
            id: text2
            height: 22
            text: qsTr("Exist Message ID: ")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            clip: true
        }
        ComboBox {
            id: textField1
            height: 23
            model: MessageModel{
                dbfInfo: DBFFileInfo
            }
            textRole: "messageName"
        }
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
            height: 23
        }
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
            placeholderText: qsTr("8")
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

    RowLayout{
        id: signaleRow
        anchors{
            top: filenameRow.bottom
            topMargin: 20
        }

        height: 20
        spacing: 5
        Text {
            id: addSignalText
            text: qsTr("Add Signal:")
            font.pixelSize: 12
            verticalAlignment: Text.AlignVCenter
        }
        Text {
            id: signalNameText
//            width: 76
//            height: 20
            text: qsTr("Signal Name:")
            font.pixelSize: 12
            verticalAlignment: Text.AlignVCenter
        }

        TextField {
            id: signalName
//            width: 76
//            height: 20
            //text: qsTr("Signal name:")
            font.pixelSize: 12
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: startBitStaticText
//            width: 76
//            height: 20
            text: qsTr("Start Bit:")
            font.pixelSize: 12
            verticalAlignment: Text.AlignVCenter
        }

        TextField {
            id: startBitField
            width: 10
//            height: 20
            //text: qsTr("Signal name:")
            Layout.maximumWidth: 20
            font.pixelSize: 12
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: endBitText
//            width: 76
//            height: 20
            text: qsTr("End Bit:")
            font.pixelSize: 12
            verticalAlignment: Text.AlignVCenter
        }

        TextField {
            id: endBitField
            Layout.maximumWidth: 20
//            height: 20
            //text: qsTr("Signal name:")
            font.pixelSize: 12
            verticalAlignment: Text.AlignVCenter
        }

        Button {
            id: addSignale
            text: qsTr("Add Signal")
            onClicked:{

            }
        }
    }

    Text {
        id: signalAreaText
        anchors.top: signaleRow.bottom
        anchors.topMargin: 10
        text: qsTr("Signal Area: ")
    }

    GridView {
        anchors{
            left: signalAreaText.right
            leftMargin: 10
            top: signaleRow.bottom
            topMargin: 10
        }
        width: 600
        height: 200
        model: 7
        delegate: Button{
            text:qsTr("test")
        }
    }
    Text {
        id: bitsAreaText
        anchors.top: signalAreaText.bottom
        anchors.topMargin: 10
        text: qsTr("Bits Area: ")
    }

    GridView {
        anchors{
            left: bitsAreaText.right
            leftMargin: 10
            top: signalAreaText.bottom
            topMargin: 10
        }
        width: 600
        height: 200
        model: 7
        delegate: Button{
            text:qsTr("haha")
        }
    }


}
