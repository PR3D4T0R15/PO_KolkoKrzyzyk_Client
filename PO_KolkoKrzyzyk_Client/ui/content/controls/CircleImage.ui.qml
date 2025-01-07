

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick

Item {
    id: circle
    width: 170
    height: 160
    property alias circleImage: circleImage

    Image {
        id: circleImage
        width: 170
        height: 160
        anchors.verticalCenter: parent.verticalCenter
        source: "../images/o.png"
        anchors.horizontalCenter: parent.horizontalCenter
        fillMode: Image.PreserveAspectFit

        opacity: 1
    }
}
