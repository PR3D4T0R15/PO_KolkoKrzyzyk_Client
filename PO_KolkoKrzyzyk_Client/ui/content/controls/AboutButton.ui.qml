

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls

Button {
    id: control
    width: 39
    height: 39

    leftPadding: 4
    rightPadding: 4

    text: "My Button"
    display: AbstractButton.IconOnly

    background: buttonBackground
    Rectangle {
        id: buttonBackground
        color: "#00000000"
        implicitWidth: 39
        implicitHeight: 39
        opacity: enabled ? 1 : 0.3
        radius: 0
        border.color: "#047eff"
    }

    Image {
        id: aboutvector
        anchors.fill: parent
        anchors.leftMargin: 5
        anchors.rightMargin: 5
        anchors.topMargin: 5
        anchors.bottomMargin: 5
        source: "../images/aboutvector.png"
        fillMode: Image.PreserveAspectFit
    }

    states: [
        State {
            name: "normal"
            when: !control.down

            PropertyChanges {
                target: buttonBackground
                color: "#75100a"
                border.color: "#75100a"
            }
        },
        State {
            name: "down"
            when: control.down

            PropertyChanges {
                target: buttonBackground
                color: "#111d4a"
                border.color: "#111d4a"
            }
        }
    ]
}
