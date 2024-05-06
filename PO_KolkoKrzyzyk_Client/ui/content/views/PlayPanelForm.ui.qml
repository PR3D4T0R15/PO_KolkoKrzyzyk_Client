

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
    id: playPanel
    width: 450
    height: 370

    PlayButton {
        id: playButton
        anchors.top: parent.top
        anchors.topMargin: 85
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Row {
        id: row
        anchors.top: parent.top
        anchors.topMargin: 270
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 49

        AccountButton {
            id: logOutButton
            text: qsTr("Wyloguj")
        }

        AccountButton {
            id: exitButton
            text: qsTr("Wyjdź z gry")
        }
    }
}
