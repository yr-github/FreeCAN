import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import DBFFileInfo 1.0
import MessageModel 1.0
import SignalModel 1.0
import IODbfController 1.0
import "../popUp"

Rectangle {
    visible: false
    id:page

    function caculateRelativelyHeight(){
        return 1
    }
    function caculateRelativelyWidth(){
        return 1
    }

    AddMessage{
        id:messageDialog
    }

    AddSignal{
        id:signalDialog
        iMessageId:messageField.iCurrentMessageId
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
            Layout.maximumWidth: 140
        }
    }

    Rectangle{
        id:horizontalDividLine
        height: 1
        width: parent.width
        color: "black"
        anchors{
            top: filenameRow.bottom
            topMargin: 5
        }
    }
    Rectangle{
        id:verticalDividLine
        height: parent.height
        width: 1
        color: "black"
        anchors{
            top: horizontalDividLine.bottom
            left: page.left
            leftMargin: 300
        }
    }
    RowLayout{
        anchors{
            top: horizontalDividLine.bottom
            topMargin: 5
            left: parent.left
            leftMargin: 10
        }
        spacing: 20
        Text {
            id: text2
            height: 22
            text: qsTr("Exist Message ID: ")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            clip: true
        }
        Button{
            id: openAddMessageWindow
            text: qsTr("Add Message")
            onClicked: {
                messageDialog.visible=true
            }
        }
    }

    Item {

        anchors{
            top: horizontalDividLine.bottom
            topMargin: 40
            left: parent.left
            leftMargin: 10
        }

        //Frame{
            ListView{
                id: messageField

                implicitWidth: 250
                implicitHeight: 250
                clip: false
                property int iCurrentMessageId: 0
                property int iCurrentMessageLen: 8
                model:MessageModel{
                    dbfInfo: DBFFileInfo
                }
                delegate: RowLayout{
                    TextField{
                        Layout.fillWidth: true
                        text: model.messageName
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                messageField.iCurrentMessageId = DBFFileInfo.invokableGetIdByName(parent.text)
                            }
                        }
                    }
                    Button{
                        text: "Edit"
                    }
                    Button{
                        text: "Delete"
                    }
                }
            }
        //}
    }


    RowLayout {
        id: signaleRow
        anchors{
            top: horizontalDividLine.bottom
            topMargin: 10
            left: signalGridView.right
            leftMargin: 10
        }

        height: 20
        spacing: 5
        Button {
            id: addSignale
            text: qsTr("Add Signal")
            onClicked:{
                signalDialog.visible=true
            }
        }
    }

    Text {
        id: signalAreaText
        anchors{
            top: horizontalDividLine.bottom
            topMargin: 10
            left: verticalDividLine.right
            leftMargin: 20
        }
        text: qsTr("Signal Area: ")
    }

    GridView {
        id: signalGridView
        signal buttonClicked()
        anchors{
            left: signalAreaText.right
            leftMargin: 10
            top: signalAreaText.top
        }
        width: 600
        height: 200
        cellWidth: 70
        cellHeight: 30
        model: SignalModel{
            dbfInfo: DBFFileInfo
            iCurrentMessageId: messageField.iCurrentMessageId
        }
        //TODO Bug always add 2 empty item to first signal
        delegate: Button{
            text: model.signalNames
            onClicked: {
                signalGridView.buttonClicked();
            }
        }
    }
    Text {
        id: bitsAreaText
        anchors{
            top: signalAreaText.bottom
            topMargin: 10
            left: signalAreaText.left
        }
        text: qsTr("Bits Area: ")
    }

    GridView {
        id: bitsView
        anchors{
            left: bitsAreaText.right
            leftMargin: 10
            top: bitsAreaText.top
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
    Connections{
        target: root
        onNewFile:{
            page.visible=true
        }
        onOpenFile: (fileName)=>{
                        IODbfController.invokableReadFile(DBFFileInfo,fileName);
                        page.visible=true
                        console.log(fileName)
                    }
        onSaveFile: (fileName)=> {
                        IODbfController.invokableWriteFile(DBFFileInfo,fileName);
                    }
    }
}
