import QtQuick
import QtQuick.Controls

Popup {
    id: gameInfoPopup
    width: 400
    height: 40
    x: (parent.width - width) / 2
    y: 20
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
        textFormat: Text.RichText
    }

    Timer {
        id: closeTimer
        interval: 4000
        repeat: false
        running: false

        onTriggered: gameInfoPopup.close()
    }

    enter: Transition {
        NumberAnimation { property: "y"; from: -50; to: 20; duration: 300 }
    }
    exit: Transition {
        NumberAnimation { property: "opacity"; from: 1.0; to: 0.0; duration: 200 }
    }
}
