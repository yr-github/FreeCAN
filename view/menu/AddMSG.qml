import QtQuick 2.2
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle {
    visible: true
    id:page

    function caculateRelativelyHeight(){
        return 1
    }
    function caculateRelativelyWidth(){
        return 1
    }

    TextField {
        id: textField
        x: 100
        y: 16
        width: 139
        height: 23
        placeholderText: qsTr("File Name")
    }

    ComboBox {
        id: textField1
        x: 346
        y: 16
        width: 122
        height: 23
        //placeholderText: qsTr("Text Field")
    }

    Text {
        id: text1
        x: 8
        y: 16
        width: 86
        height: 23
        text: qsTr("File Name：")
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


    RowLayout{
        id: signaleRow
        x: 8
        y: 58
        height: 20
        spacing: 5
        Text {
            id: text3

//            width: 76
//            height: 20
            text: qsTr("Add Signal:")
            font.pixelSize: 12
            verticalAlignment: Text.AlignVCenter
        }
        Text {
            id: text4
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
            id: text5
//            width: 76
//            height: 20
            text: qsTr("Start Bit:")
            font.pixelSize: 12
            verticalAlignment: Text.AlignVCenter
        }

        TextField {
            id: startBit
            width: 10
//            height: 20
            //text: qsTr("Signal name:")
            Layout.maximumWidth: 20
            font.pixelSize: 12
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: text6
//            width: 76
//            height: 20
            text: qsTr("End Bit:")
            font.pixelSize: 12
            verticalAlignment: Text.AlignVCenter
        }

        TextField {
            id: endBit
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
