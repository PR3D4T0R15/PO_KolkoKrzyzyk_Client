

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import "../controls"

Item {
    id: endGame

    width: 1280
    height: 720

    anchors.fill: parent

    Rectangle {
        id: rectangle
        width: 480
        height: 600
        color: "#ffffff"
        radius: 20
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Row {
        id: row
        y: 539
        anchors.bottom: rectangle.bottom
        anchors.bottomMargin: 60
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 50

        EndGameButton {
            id: endGameButton1
            width: 150
            height: 60
            text: "ZAGRAJ PONOWNIE"
        }

        EndGameButton {
            id: endGameButton
            width: 150
            height: 60
            text: "WYJDŹ DO MEU"
        }
    }

    Loader {
        id: loader
        anchors.left: rectangle.left
        anchors.right: rectangle.right
        anchors.top: rectangle.top
        anchors.bottom: row1.top
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.topMargin: 0
        anchors.bottomMargin: 23
    }

    Row {
        id: row1
        y: 478
        anchors.bottom: row.top
        anchors.bottomMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            id: text1
            text: qsTr("Twoje miejsce w rankingu: ")
            font.pixelSize: 20
        }

        Text {
            id: text2
            text: qsTr("5")
            font.pixelSize: 20
            font.bold: true
        }
    }
}
