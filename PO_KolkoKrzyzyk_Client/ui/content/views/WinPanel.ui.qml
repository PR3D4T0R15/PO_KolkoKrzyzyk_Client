

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick

Item {
    id: winPanel
    width: 480
    height: 400

    Text {
        id: text1
        text: qsTr("GRATULACJE!")
        anchors.top: parent.top
        anchors.topMargin: 25
        font.pixelSize: 32
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: text2
        text: qsTr("WYGRANA!")
        anchors.top: text1.bottom
        anchors.topMargin: 5
        font.pixelSize: 32
        anchors.horizontalCenter: parent.horizontalCenter
    }

    AnimatedImage {
        id: animatedImage
        width: 330
        height: 190
        anchors.top: text2.bottom
        anchors.topMargin: 40
        source: "../images/win.gif"
        fillMode: Image.PreserveAspectFit
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
