import QtQuick 2.2
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import DBFFileInfo 1.0
import MessageModel 1.0
import SignalModel 1.0
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
    RowLayout {
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
            id: messageField
            height: 23
            model: MessageModel{
                dbfInfo: DBFFileInfo                
            }
            textRole: "messageName"
            property int iCurrentMessageId: 0
            //TODO Feature binding with backend
            property int iCurrentMessageLen: 8
            signal  messageIdChanged()
            onActivated: {
                iCurrentMessageId = DBFFileInfo.invokableGetIdByName(textAt(currentIndex))
                messageIdChanged()
            }
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

    RowLayout {
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
                DBFFileInfo.invokableAddSignal(messageField.iCurrentMessageId,signalName.text,startBitField.text,endBitField.text);
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
        id: signalGridView
        signal buttonClicked()
        anchors{
            left: signalAreaText.right
            leftMargin: 10
            top: signaleRow.bottom
            topMargin: 10
        }
        width: 600
        height: 200
        cellWidth: 70
        cellHeight: 30
        model: SignalModel{
            dbfInfo: DBFFileInfo
            iCurrentMessageId: messageField.iCurrentMessageId
        }
        delegate: Button{
            text:model.signalNames
            onClicked: {
                signalGridView.buttonClicked();
            }
        }
    }
    Text {
        id: bitsAreaText
        anchors.top: signalAreaText.bottom
        anchors.topMargin: 10
        text: qsTr("Bits Area: ")
    }

    GridView {
        id: bitsView
        anchors{
            left: bitsAreaText.right
            leftMargin: 10
            top: signalAreaText.bottom
            topMargin: 10
        }
        cellWidth: 30
        cellHeight: 30
        width: 480
        height: 200
        model: {
            8*messageField.iCurrentMessageLen
        }
        delegate: Button{
            width: 30
            text: index + 1
            background: Rectangle{
                id: rectCustomiz
                implicitHeight: 30
                implicitWidth: 30
                color:DBFFileInfo.invokableGetBitsColor(messageField.iCurrentMessageId,index+1)
                Connections{
                    target: signalGridView
                    function onButtonClicked(){
                        //TODO Feature color need more perfomence implemention
                        rectCustomiz.color = DBFFileInfo.invokableGetBitsColor(messageField.iCurrentMessageId,index+1)
                    }
                }
            }
        }
    }
}
