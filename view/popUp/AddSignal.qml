import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import DBFFileInfo 1.0
import FreeCANEnum 1.0
Window {
    id:messageDialog
    property int iMessageId: 0
    flags: Qt.Tool
    modality: Qt.WindowModal
    title: "Add Signal"
    width: 400
    height: 300
    ColumnLayout{
        RowLayout{
            Text {
                id: signalNameText
                text: qsTr("Signal Name:")
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: signalName
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }
        }
        RowLayout{
            Text {
                id: valueTypeText
                text: qsTr("Type:")
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }
            ComboBox{
                id:valueTypeCombo
                //model order is importent
                //as same as FreeCANEnum::SIGNAL_VALUE_TYPE
                model: ["bool","int","unsigned int"]
            }
            Text {
                id: byteIndexText
                text: qsTr("Byte Index:")
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }
            TextField {
                id: byteLengthField
                width: 10
                Layout.maximumWidth: 20
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }
            Text {
                id: startBitStaticText
                text: qsTr("Start Bit:")
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: startBitField
                width: 10
                Layout.maximumWidth: 20
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }
        }
        RowLayout{
            Text {
                id: byteLengthText
                text: qsTr("Bit Length:")
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }
            TextField {
                id: bitLengthField
                width: 10
                Layout.maximumWidth: 20
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }
            Text {
                id: minValueText
                text: qsTr("Min Value: 0x")
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }
            TextField {
                id: minValueField
                width: 10
                Layout.maximumWidth: 60
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
                validator: RegularExpressionValidator { regularExpression: /[0-9a-fA-F]+/ }
                onTextEdited: text=text.toUpperCase()
                onTextChanged: text=text.toUpperCase()
            }
            Text {
                id: maxValueText
                text: qsTr("Max Value: 0x")
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }
            TextField {
                id: maxValueField
                width: 10
                Layout.maximumWidth: 60
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
                validator: RegularExpressionValidator { regularExpression: /[0-9a-fA-F]+/ }
                onTextEdited: text=text.toUpperCase()
                onTextChanged: text=text.toUpperCase()
            }
        }
        RowLayout{
            Text {
                id: offsetText
                text: qsTr("Offset:")
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }
            TextField {
                id: offsetField
                width: 10
                Layout.maximumWidth: 20
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }
            Text {
                id: factorText
                text: qsTr("Factor:")
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }
            TextField {
                id: factorField
                width: 10
                Layout.maximumWidth: 20
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }
            Text {
                id: unitText
                text: qsTr("Unit:")
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }
            TextField {
                id: unitField
                width: 10
                Layout.maximumWidth: 20
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }
        }
        RowLayout{
            Text {
                id: orderTypeText
                text: qsTr("Byte Order:")
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }
            RadioButton {
                checked: true
                id:orderTypeIntel
                text: qsTr("Intel(Little-Endian)")
            }
            RadioButton {
                id:orderTypeMotorola
                text: qsTr("Motorola(Big-Endian)")
            }
        }
        RowLayout{
            Button {
                id: addSignale
                text: qsTr("Add Signal")
                onClicked:{
                    DBFFileInfo.invokableAddSignal(iMessageId,signalName.text,startBitField.text,byteLengthField.text,
                                                   bitLengthField.text,minValueField.text,maxValueField.text,
                                                   factorField.text,offsetField.text,valueTypeCombo.currentIndex,
                                                   unitField.text,orderTypeIntel?FreeCANEnum.TYPE_INTEL:FreeCANEnum.TYPE_MOTOROLA);
                }
            }
        }
    }
}
