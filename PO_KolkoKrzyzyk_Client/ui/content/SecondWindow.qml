import QtQuick
import QtQuick.Controls
import "controls"
import "views"
import "sounds"
import QtQuick.Layouts

Window {
    id: secondWindow
    width: 700
    height: 700
    maximumWidth: 700
    maximumHeight: 700
    minimumWidth: 700
    minimumHeight: 700
    modality: Qt.ApplicationModal
    color: "#ffcf99"

    Image {
        id: about_info
        anchors.fill: parent
        source: "images/about_info.png"
        fillMode: Image.PreserveAspectFit
    }
}
