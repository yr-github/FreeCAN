import QtQuick.Controls 2.12
import QtQuick 2.12
import QtQuick.Dialogs



FileDialog {
    id: fileDialog
    fileMode:FileDialog.OpenFile
    selectedNameFilter.index: 1
    title: fileMode===FileDialog.OpenFile?"Please choose a file":"Save Xml File at..."
    nameFilters: ["All files (*)", "XML files (*.xml)"]
}



