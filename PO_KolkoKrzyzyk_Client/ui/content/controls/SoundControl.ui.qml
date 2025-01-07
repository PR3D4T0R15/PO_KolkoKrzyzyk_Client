

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls

CheckBox {
    id: control
    implicitWidth: 39
    implicitHeight: 39
    checked: true
    indicator: rectangle

    Rectangle {
        id: rectangle
        color: "#75100a"
        anchors.fill: parent
        width: 39
        height: 39

        Image {
            id: sound_off
            width: 30
            height: 30
            visible: false
            anchors.verticalCenter: parent.verticalCenter
            source: "../images/sound_off.png"
            anchors.horizontalCenter: parent.horizontalCenter
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: sound_on
            width: 30
            height: 30
            anchors.verticalCenter: parent.verticalCenter
            source: "../images/sound_on.png"
            anchors.horizontalCenter: parent.horizontalCenter
            fillMode: Image.PreserveAspectFit
        }
    }

    states: [
        State {
            name: "checked"
            when: control.checked
        },
        State {
            name: "unchecked"
            when: !control.checked

            PropertyChanges {
                target: sound_off
                visible: true
            }

            PropertyChanges {
                target: sound_on
                visible: false
            }
        }
    ]
}
