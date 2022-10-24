import QtQuick 2.0
import QtQuick.Controls 2.12


Button{
    id:root
    property color cButtonFocusColor: "#FFFFFF"
    signal buttonClicked()
    QtObject{
        id:attribute
    }

    background: {
        color:cButtonFocusColor
    }
}
