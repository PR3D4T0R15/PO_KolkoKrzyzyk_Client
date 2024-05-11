import QtQuick
import QtQuick.Controls

Popup {
    id: gameInfoPopup
    width: 400
    height: 40
    x: (parent.width - width) / 2
    y: 0
    modal: false
    visible: true
    focus: true
    background: rectangleBackground

    property string textMessage: "TEST!"

    onOpened: closeTimer.start()

    Rectangle {
        id: rectangleBackground
        color: "#ffffff"
        radius: 20
        border.color: "#75100a"
        border.width: 2
    }

    Text {
        id: textPopup
        text: gameInfoPopup.textMessage
        anchors.fill: parent
        anchors.leftMargin: 20
        anchors.rightMargin: 20
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
    }

    Timer {
        id: closeTimer
        interval: 5000
        repeat: false
        running: false

        onTriggered: gameInfoPopup.close()
    }
}
