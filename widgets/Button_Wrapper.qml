import QtQuick 2.12
import QtQuick.Controls 2.12
import LogWrapper 1.0

Button{
    property string strUniqueId: ""
    onClicked: {
        LogWrapper.invokableUserLog(strUniqueId,"click")
    }
}
