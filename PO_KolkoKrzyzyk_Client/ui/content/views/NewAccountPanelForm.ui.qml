

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls
import "../controls"

Item {
    id: newAccountPanel
    width: 450
    height: 370
    anchors.fill: parent
    property alias logInButton: logInButton
    property alias newAccountButton: newAccountButton
    property alias pass2Field: pass2Field
    property alias passField: passField
    property alias loginField: loginField

    TextField {
        id: loginField
        x: 77
        y: 62
        width: 296
        anchors.top: parent.top
        anchors.topMargin: 62
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenter: parent.horizontalCenter
        placeholderText: qsTr("Login")
        background: Rectangle {
            border.color: "red"
            border.width: 2
        }
    }

    TextField {
        id: passField
        x: 77
        y: 127
        width: 296
        anchors.top: loginField.bottom
        anchors.topMargin: 25
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenter: parent.horizontalCenter
        placeholderText: qsTr("Hasło")
        background: Rectangle {
            border.color: "red"
            border.width: 2
        }
    }

    TextField {
        id: pass2Field
        x: 77
        y: 177
        width: 296
        anchors.top: passField.bottom
        anchors.topMargin: 10
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenter: parent.horizontalCenter
        placeholderText: qsTr("Powtórz Hasło")
        background: Rectangle {
            border.color: "red"
            border.width: 2
        }
    }

    Text {
        id: errorText
        x: 123
        y: 227
        color: "#920014"
        text: qsTr("Nieprawidłowy login lub hasło")
        anchors.top: pass2Field.bottom
        anchors.topMargin: 10
        font.pixelSize: 14
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Row {
        id: row
        x: 80
        y: 266
        anchors.top: errorText.bottom
        anchors.topMargin: 20
        spacing: 49
        anchors.horizontalCenter: parent.horizontalCenter

        AccountButton {
            id: newAccountButton
            text: qsTr("Załóż konto")
        }

        AccountButton {
            id: logInButton
            text: "Cofnij"
        }
    }
}