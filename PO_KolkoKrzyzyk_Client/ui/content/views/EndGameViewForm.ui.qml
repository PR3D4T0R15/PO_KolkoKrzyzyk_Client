

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import "../controls"

Item {
    id: endGameView
    property string cppId: "endGameView"

    width: 1280
    height: 720

    anchors.fill: parent
    property alias loader: loader
    property alias goToMenuButton: goToMenuButton
    property alias playAgainButton: playAgainButton
    property alias rankingPlace: rankingPlace
    property alias endGameView: endGameView

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
            id: playAgainButton
            property string cppId: "playAgainButton"
            width: 150
            height: 60
            text: "ZAGRAJ PONOWNIE"
        }

        EndGameButton {
            id: goToMenuButton
            property string cppId: "goToMenuButton"
            width: 150
            height: 60
            text: "WYJDŹ DO MENU"
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
            id: rankingPlace
            text: qsTr("5")
            font.pixelSize: 20
            font.bold: true
        }
    }
    states: [
        State {
            name: "win"
            PropertyChanges {
                target: loader
                source: "WinPanel.ui.qml"
            }
        },
        State {
            name: "lost"
            PropertyChanges {
                target: loader
                source: "FailPanel.ui.qml"
            }
        },
        State {
            name: "draw"
            PropertyChanges {
                target: loader
                source: "DrawPanel.ui.qml"
            }
        }
    ]
}
