

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls

TextField {
    id: customTextField
    width: 296
    height: 40
    horizontalAlignment: Text.AlignLeft
    verticalAlignment: Text.AlignVCenter
    placeholderTextColor: "#88373535"
    anchors.horizontalCenter: parent.horizontalCenter
    placeholderText: qsTr("Login")
    font.pointSize: 12
    background: borderRectangle
    state: "default"
    states: [
        State {
            name: "default"

            PropertyChanges {
                target: borderRectangle
                border.color: "#2f2f2f"
            }
        },
        State {
            name: "error"

            PropertyChanges {
                target: borderRectangle
                border.color: "#92140c"
            }
        },
        State {
            name: "ok"

            PropertyChanges {
                target: borderRectangle
                border.color: "#08bc06"
            }
        }
    ]

    Rectangle {
        id: borderRectangle
        border.width: 2
    }
}
