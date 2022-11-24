import QtQuick 2.0
import "../../widgets"
import LogWrapper 1.0
import PlayBackController 1.0
Item {
    QtObject{
        id: attributes
        property var strMap: {"attribute":attributes};
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
               LogWrapper.invokableUserLog("is this ok?")
            }
            Component.onCompleted: {
                attributes.strMap["idAddMsgButton"]=addMsgButton
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
                attributes.strMap[strUniqueId]=startPlayBack
            }
        }
    }
    Connections{
        target: PlayBackController
        //DONE Feature: need qml map or other container
        function onSignaleUserEvent(strEventId){
            if(undefined === console.log(attributes.strMap[strEventId])){
                //TODO Feature: alert user?
                LogWrapper.invokableDebugLog("Log have unmatched Item ID, Input Wrong Log?",1)
            }
            attributes.strMap[strEventId].text = "Success!"
        }
    }

}
