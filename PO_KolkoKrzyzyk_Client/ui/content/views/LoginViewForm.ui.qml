

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
    property alias ranksItem: ranksItem
    property alias stackView: stackView

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
            id: loginItem
            implicitWidth: 450
            implicitHeight: 370
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Rectangle {
                id: loginBackground
                color: "#ffffff"
                radius: 50
                anchors.fill: parent
            }

            StackView {
                id: stackView
                anchors.fill: parent

                initialItem: loginPanel
            }
        }

        Item {
            id: ranksItem

            implicitWidth: 650
            implicitHeight: 470
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Rectangle {
                id: ranksBackground
                color: "#ffffff"
                radius: 50
                anchors.fill: parent
            }

            TableView {
                anchors.fill: parent
            }

            Row {
                id: row
                anchors.top: parent.top
                anchors.topMargin: 25
                spacing: 15
                anchors.horizontalCenter: parent.horizontalCenter

                Image {
                    id: table_image
                    source: "../images/table_image.png"
                    fillMode: Image.PreserveAspectFit
                }

                Text {
                    id: text1
                    height: 49
                    text: qsTr("Lista rankingowa")
                    font.pixelSize: 24
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                Image {
                    id: table_image1
                    source: "../images/table_image.png"
                    fillMode: Image.PreserveAspectFit
                }
            }
        }
        columns: 2
        columnSpacing: 0
    }
    LoginPanel {
        id: loginPanel
        visible: false
    }
    NewAccountPanel {
        id: newAccountPanel
        visible: false
    }
}
