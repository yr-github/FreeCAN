import QtQuick 2.0
import QtQuick.Controls 2.12
import LogWrapper 1.0

Button{
    property string strUniqueId: ""
    onClicked: {
        LogWrapper.invokableLog(strUniqueId)
    }
}
