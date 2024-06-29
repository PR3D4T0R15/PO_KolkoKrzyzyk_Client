

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Layouts
import "../controls"

Item {
    id: gameView
    property string cppId: "gameView"
    width: 1280
    height: 720

    anchors.fill: parent
    property alias gameControlC3: gameControlC3
    property alias gameControlB3: gameControlB3
    property alias gameControlA3: gameControlA3
    property alias gameControlC2: gameControlC2
    property alias gameControlB2: gameControlB2
    property alias gameControlA2: gameControlA2
    property alias gameControlC1: gameControlC1
    property alias gameControlB1: gameControlB1
    property alias gameControlA1: gameControlA1

    property alias timeLeftValue: timeLeftValue
    property alias roundTitle: roundTitle
    property alias roundImage: roundImage

    property alias gameLeaveButton: gameLeaveButton

    GridLayout {
        id: mainLayout
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.topMargin: 0
        anchors.bottomMargin: 0
        rows: 1
        rowSpacing: 0
        Item {
            id: gameItem
            implicitWidth: 670
            implicitHeight: 560
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Rectangle {
                id: gameBackground
                color: "#ffffff"
                radius: 50
                anchors.fill: parent
            }

            Image {
                id: game_field
                anchors.fill: parent
                anchors.leftMargin: 10
                anchors.rightMargin: 10
                anchors.topMargin: 10
                anchors.bottomMargin: 10
                source: "../images/game_field.svg"
                fillMode: Image.PreserveAspectFit
            }

            GameControl {
                id: gameControlA1
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 50
                anchors.topMargin: 18
            }

            GameControl {
                id: gameControlB1
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 242
                anchors.topMargin: 18
                controlLocation: "B1"
            }

            GameControl {
                id: gameControlC1
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 436
                anchors.topMargin: 18
                controlLocation: "C1"
            }

            GameControl {
                id: gameControlA2
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 50
                anchors.topMargin: 195
                controlLocation: "A2"
            }

            GameControl {
                id: gameControlB2
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 242
                anchors.topMargin: 195
                controlLocation: "B2"
            }

            GameControl {
                id: gameControlC2
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 436
                anchors.topMargin: 195
                controlLocation: "C2"
            }

            GameControl {
                id: gameControlA3
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 50
                anchors.topMargin: 375
                controlLocation: "A3"
            }

            GameControl {
                id: gameControlB3
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 242
                anchors.topMargin: 375
                controlLocation: "B3"
            }

            GameControl {
                id: gameControlC3
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 436
                anchors.topMargin: 375
                controlLocation: "C3"
            }
        }

        Item {
            id: toolsItem

            implicitWidth: 340
            implicitHeight: 450
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Rectangle {
                id: toolsBackground
                color: "#ffffff"
                radius: 50
                anchors.fill: parent
            }

            Text {
                id: time
                text: qsTr("pozostało:")
                anchors.top: parent.top
                anchors.topMargin: 210
                font.pixelSize: 24
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: timeLeftValue
                color: "#92140c"
                text: qsTr("15")
                anchors.top: time.bottom
                anchors.topMargin: 0
                font.pixelSize: 48
                anchors.horizontalCenter: parent.horizontalCenter
            }

            GameLeaveButton {
                id: gameLeaveButton
                property string cppId: "gameLeaveButton"
                text: qsTr("Zrezygnuj i wyjdź do MENU")
                anchors.top: parent.top
                anchors.topMargin: 342
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Column {
                id: column
                anchors.top: parent.top
                anchors.topMargin: 12
                anchors.horizontalCenter: parent.horizontalCenter

                Text {
                    id: roundTitle
                    width: 200
                    text: qsTr("Ruch \nprzeciwnika!")
                    font.pixelSize: 32
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.weight: Font.DemiBold
                    font.bold: false
                }
            }

            Image {
                id: roundImage
                x: 135
                width: 70
                height: 70
                anchors.top: parent.top
                anchors.topMargin: 110
                source: "../images/o.png"
                anchors.horizontalCenter: parent.horizontalCenter
                fillMode: Image.PreserveAspectFit
            }
        }

        columns: 2
        columnSpacing: 0
    }
    states: [
        State {
            name: "enemyTurn"
            PropertyChanges {
                target: text1
                text: qsTr("RUCH")
            }
            PropertyChanges {
                target: text2
                text: qsTr("PRZECIWNIKA!")
            }
        },
        State {
            name: "yourTurn"
            PropertyChanges {
                target: text1
                text: qsTr("TWÓJ")
            }
            PropertyChanges {
                target: text2
                text: qsTr("RUCH!")
            }
        }
    ]
}
