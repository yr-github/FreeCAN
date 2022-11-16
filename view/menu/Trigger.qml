import QtQuick 2.0
import "../../widgets"
import LogWrapper 1.0
import PlayBackController 1.0
Item {
    QtObject{
        id: attributes

    }
    Rectangle {
        id: rectangle
        anchors.fill: parent
        Button_Wrapper {
            id: addMsgButton
            strUniqueId: "idAddMsgButton"
            x: 21
            y: 17
            text: qsTr("Button")
            anchors.left: parent.left
            anchors.top: parent.top
            onClicked: {
               directAddmsg.show()
               LogWrapper.invokableLog("is this ok?")
            }
            Component.onCompleted: {
                //attributes.strIdMap[strUniqueId]=button
            }
        }
        Button_Wrapper{
            id: startPlayBack
            strUniqueId: "idstartPlayBack"
            text: qsTr("PlayBack")
            anchors {
                left: addMsgButton.right
            }
            onClicked: {
                PlayBackController.invokStartPlayBack()
            }
            Component.onCompleted: {
                //attributes.strIdMap[strUniqueId]=button
            }
        }
    }
    Connections{
        target: PlayBackController
        //TODO Feature: need qml map or other container
        function onSignaleUserEvent(strEventId){
            console.log("onSignaleUserEvent:",strEventId)
            switch(strEventId){
            case "idAddMsgButton":
                addMsgButton.clicked()
                break;
            }
        }
    }

}
