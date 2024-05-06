

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../controls"

Item {
    width: 1280
    height: 720

    anchors.fill: parent
    property alias areaC3: areaC3
    property alias areaC2: areaC2
    property alias areaC1: areaC1
    property alias areaB3: areaB3
    property alias areaA3: areaA3
    property alias area2A: area2A
    property alias area1A: area1A
    property alias areaB1: areaB1
    property alias areaB2: areaB2

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

            MouseArea {
                id: areaB2
                width: 170
                height: 160
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 243
                anchors.topMargin: 196
            }

            MouseArea {
                id: areaB1
                width: 170
                height: 160
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 243
                anchors.topMargin: 17
            }

            MouseArea {
                id: area1A
                width: 170
                height: 160
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 48
                anchors.topMargin: 18
            }

            MouseArea {
                id: area2A
                width: 170
                height: 160
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 48
                anchors.topMargin: 196
            }

            MouseArea {
                id: areaA3
                x: 48
                y: 377
                width: 170
                height: 160
            }

            MouseArea {
                id: areaB3
                x: 243
                y: 377
                width: 170
                height: 160
            }

            MouseArea {
                id: areaC1
                x: 439
                y: 18
                width: 170
                height: 160
            }

            MouseArea {
                id: areaC2
                x: 439
                y: 196
                width: 170
                height: 160
            }

            MouseArea {
                id: areaC3
                x: 439
                y: 377
                width: 170
                height: 160
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
        }
        columns: 2
        columnSpacing: 0
    }
}
