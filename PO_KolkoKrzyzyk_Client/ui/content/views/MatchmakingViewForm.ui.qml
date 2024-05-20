

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
    id: matchmakingView
    width: 1280
    height: 720
    anchors.fill: parent
    property alias valueQueue: valueQueue
    property alias exitMatchmakingButton: exitMatchmakingButton

    Rectangle {
        id: rectangle
        width: 650
        height: 500
        color: "#ffffff"
        radius: 20
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: title
        text: qsTr("POCZEKAJ NA PRZECIWNIKA")
        anchors.top: parent.top
        anchors.topMargin: 135
        font.pixelSize: 32
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.bold: true
    }

    Row {
        id: rowQueue
        anchors.top: parent.top
        anchors.topMargin: 184
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            id: titleQueue
            text: qsTr("Ilość graczy w kolejce: ")
            font.pixelSize: 18
        }

        Text {
            id: valueQueue
            text: qsTr("5")
            font.pixelSize: 18
        }
    }

    Text {
        id: title1
        text: qsTr("ŁADOWANIE...")
        anchors.top: parent.top
        anchors.topMargin: 450
        font.pixelSize: 32
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
    }

    AccountButton {
        id: exitMatchmakingButton
        text: "Wyjdź z gry"
        anchors.top: parent.top
        anchors.topMargin: 536
        anchors.horizontalCenter: parent.horizontalCenter
    }

    BusyIndicator {
        id: busyIndicator
        x: 544
        y: 246
        width: 192
        height: 170
        anchors.top: parent.top
        anchors.topMargin: 230
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
