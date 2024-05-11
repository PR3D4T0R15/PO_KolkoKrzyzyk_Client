

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 2.15

Item {
    id: cross
    width: 170
    height: 160

    Image {
        id: crossImage
        width: 170
        height: 160
        anchors.verticalCenter: parent.verticalCenter
        source: "../images/x.png"
        anchors.horizontalCenter: parent.horizontalCenter
        fillMode: Image.PreserveAspectFit

        opacity: 0.3
    }
}
