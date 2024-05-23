

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
    property alias errorText: errorText
    property alias logInButton: logInButton
    property alias newAccountButton: newAccountButton
    property alias pass2Field: pass2Field
    property alias passField: passField
    property alias loginField: loginField

    CustomTextField {
        id: loginField
        anchors.top: parent.top
        anchors.topMargin: 62
        anchors.horizontalCenter: parent.horizontalCenter
        placeholderText: qsTr("Login")
    }

    CustomTextField {
        id: passField
        anchors.top: loginField.bottom
        anchors.topMargin: 25
        anchors.horizontalCenter: parent.horizontalCenter
        placeholderText: qsTr("Hasło")
        echoMode: TextInput.Password
    }

    CustomTextField {
        id: pass2Field
        anchors.top: passField.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        placeholderText: qsTr("Powtórz Hasło")
        echoMode: TextInput.Password
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
            property string cppId: "createNewAccountButton"
            text: qsTr("Załóż konto")
        }

        AccountButton {
            id: logInButton
            property string cppId: "goToLoginButton"
            text: "Cofnij"
        }
    }
}
