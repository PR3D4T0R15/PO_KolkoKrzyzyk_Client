

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
    id: startView
    property string cppId: "startView"
    width: 1280
    height: 720
    anchors.fill: parent
    property alias errorText: errorText
    property alias welcomeButton: welcomeButton

    GridLayout {
        id: mainLayout
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.margins: 20
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.topMargin: 0
        anchors.bottomMargin: 0
        rowSpacing: 0
        columnSpacing: 0
        rows: 1
        columns: 2

        Item {
            id: textButtonItem
            implicitWidth: 450
            implicitHeight: 400
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            ColumnLayout {
                id: columnLayout
                anchors.fill: parent
                Text {
                    id: text1
                    text: qsTr("WITAJ W GRZE")
                    font.pixelSize: 60
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                Text {
                    id: text2
                    text: qsTr("KÓŁKO I KRZYŻYK!")
                    font.pixelSize: 50
                    font.bold: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                BigButton {
                    id: welcomeButton
                    property string cppId: "welcomeButton"
                    hoverEnabled: false
                    implicitWidth: 240
                    implicitHeight: 110
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                Text {
                    id: errorText
                    color: "#920014"
                    text: startViewControl.errorString
                    font.pixelSize: 14
                    font.bold: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }
            }
        }

        Item {
            id: iconItem
            implicitWidth: 450
            implicitHeight: 450
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Image {
                id: game_field
                anchors.fill: parent
                source: "../images/game_field.svg"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: o1
                width: 127
                height: 127
                opacity: 0
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 8
                anchors.topMargin: 159
                source: "../images/o.png"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: o2
                width: 127
                height: 127
                opacity: 0
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 157
                anchors.topMargin: 301
                source: "../images/o.png"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: o3
                width: 127
                height: 127
                opacity: 0
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 157
                anchors.topMargin: 18
                source: "../images/o.png"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: x1
                width: 127
                height: 127
                opacity: 0
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 310
                anchors.topMargin: 301
                source: "../images/x.png"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: x2
                width: 127
                height: 127
                opacity: 0
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 157
                anchors.topMargin: 159
                source: "../images/x.png"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: x3
                width: 127
                height: 127
                opacity: 0
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 8
                anchors.topMargin: 18
                source: "../images/x.png"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: line
                opacity: 0
                anchors.fill: parent
                source: "../images/linia.png"
                fillMode: Image.PreserveAspectFit
            }
            SequentialAnimation {
                running: true
                loops: Animation.Infinite
                //symbols
                OpacityAnimator {
                    target: o1
                    from: 0
                    to: 1
                    duration: 750
                }
                OpacityAnimator {
                    target: x2
                    from: 0
                    to: 1
                    duration: 750
                }
                OpacityAnimator {
                    target: o2
                    from: 0
                    to: 1
                    duration: 750
                }
                OpacityAnimator {
                    target: x1
                    from: 0
                    to: 1
                    duration: 750
                }
                OpacityAnimator {
                    target: o3
                    from: 0
                    to: 1
                    duration: 750
                }
                OpacityAnimator {
                    target: x3
                    from: 0
                    to: 1
                    duration: 750
                }

                //line
                OpacityAnimator {
                    target: line
                    from: 0
                    to: 1
                    duration: 1000
                }
                OpacityAnimator {
                    target: line
                    from: 1
                    to: 0
                    duration: 1000
                }
                //go back
                //6
                OpacityAnimator {
                    target: x3
                    from: 1
                    to: 0
                    duration: 750
                }
                //5
                OpacityAnimator {
                    target: o3
                    from: 1
                    to: 0
                    duration: 750
                }
                //4
                OpacityAnimator {
                    target: x1
                    from: 1
                    to: 0
                    duration: 750
                }
                //3
                OpacityAnimator {
                    target: o2
                    from: 1
                    to: 0
                    duration: 750
                }
                //2
                OpacityAnimator {
                    target: x2
                    from: 1
                    to: 0
                    duration: 750
                }
                //1
                OpacityAnimator {
                    target: o1
                    from: 1
                    to: 0
                    duration: 750
                }
            }
        }
    }
}
