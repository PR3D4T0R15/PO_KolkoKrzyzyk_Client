

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
    id: loginPanel
    width: 450
    height: 370
    property alias logInButton: logInButton
    property alias newAccountButton: newAccountButton
    property alias passField: passField
    property alias loginField: loginField

    TextField {
        id: loginField
        x: 77
        y: 82
        width: 296
        height: 40
        anchors.top: parent.top
        anchors.topMargin: 82
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        placeholderTextColor: "#88373535"
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
        y: 147
        width: 296
        height: 40
        anchors.top: loginField.bottom
        anchors.topMargin: 25
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenter: parent.horizontalCenter
        placeholderText: qsTr("Hasło")
        background: Rectangle {
            border.color: "green"
            border.width: 2
        }
    }

    Text {
        id: errorText
        x: 123
        y: 212
        color: "#920014"
        text: qsTr("Nieprawidłowy login lub hasło")
        anchors.top: passField.bottom
        anchors.topMargin: 25
        font.pixelSize: 14
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Row {
        id: row
        x: 80
        y: 270
        anchors.top: errorText.bottom
        anchors.topMargin: 39
        spacing: 49
        anchors.horizontalCenter: parent.horizontalCenter

        AccountButton {
            id: newAccountButton
            text: qsTr("Nowe konto")
        }

        AccountButton {
            id: logInButton
            text: qsTr("Zaloguj się")
        }
    }
}