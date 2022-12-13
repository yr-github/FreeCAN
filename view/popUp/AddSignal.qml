import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import DBFFileInfo 1.0

Window {
    id:messageDialog
    property int iMessageId: 0
    flags: Qt.Tool
    modality: Qt.WindowModal
    title: "Add Signal"
    width: 400
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

            Text {
                id: endBitText
                text: qsTr("End Bit:")
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: endBitField
                Layout.maximumWidth: 20
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
            }
        }
        RowLayout{
            Button {
                id: addSignale
                text: qsTr("Add Signal")
                onClicked:{
                    DBFFileInfo.invokableAddSignal(iMessageId,signalName.text,startBitField.text,endBitField.text);
                }
            }
        }
    }
}
