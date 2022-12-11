import QtQuick.Controls 2.12
import QtQuick 2.12
import QtQuick.Dialogs



FileDialog {
    id: fileDialog
    fileMode:FileDialog.OpenFile
    title: fileMode===FileDialog.OpenFile?"Please choose a file":"Save Xml File at..."
    nameFilters: ["All files (*)","XML files (*.xml)"]
//    onAccepted: {
//        console.log("You chose: " + fileDialog.file)
//    }
}



