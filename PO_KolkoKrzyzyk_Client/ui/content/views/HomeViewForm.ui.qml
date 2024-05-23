

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
    id: item1
    width: 1280
    height: 720

    anchors.fill: parent
    state: "loginAccount"
    property alias rankingList: rankingList
    property alias playerRanking: playerRanking
    property alias loader: loader

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
            clip: true

            Rectangle {
                id: loginBackground
                color: "#ffffff"
                radius: 50
                anchors.fill: parent
            }

            Loader {
                id: loader
                anchors.fill: parent
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

            Item {
                id: playerRanking
                width: 592
                height: 250
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter

                ListModel {
                    id: playerListModel
                    ListElement {
                        lp: "1"
                        user: "User1"
                        win: "64"
                        lost: "21"
                    }
                    ListElement {
                        lp: "2"
                        user: "User2"
                        win: "73"
                        lost: "8"
                    }
                    ListElement {
                        lp: "3"
                        user: "User3"
                        win: "567"
                        lost: "2234"
                    }
                    ListElement {
                        lp: "4"
                        user: "User4"
                        win: "236"
                        lost: "243"
                    }
                    ListElement {
                        lp: "5"
                        user: "User5"
                        win: "876"
                        lost: "24"
                    }
                }

                Component {
                    id: playerDelegate
                    Item {
                        width: parent.width
                        height: 40

                        Rectangle {
                            id: textLp
                            width: 40
                            height: 40
                            color: "#ffffff"
                            border.width: 1
                            anchors.left: parent.left
                            anchors.top: parent.top
                            anchors.leftMargin: 0
                            anchors.topMargin: 0
                            Text {
                                text: lp
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                            }
                        }

                        Rectangle {
                            id: textUser
                            width: 185
                            height: 40
                            color: "#ffffff"
                            border.width: 1
                            anchors.left: textLp.right
                            anchors.top: parent.top
                            anchors.leftMargin: -1
                            anchors.topMargin: 0
                            Text {
                                text: user
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                            }
                        }

                        Rectangle {
                            id: textWin
                            width: 185
                            height: 40
                            color: "#ffffff"
                            border.width: 1
                            anchors.left: textUser.right
                            anchors.top: parent.top
                            anchors.leftMargin: -1
                            anchors.topMargin: 0
                            Text {
                                text: win
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                            }
                        }

                        Rectangle {
                            id: textLost
                            width: 185
                            height: 40
                            color: "#ffffff"
                            border.width: 1
                            anchors.left: textWin.right
                            anchors.top: parent.top
                            anchors.leftMargin: -1
                            anchors.topMargin: 0
                            Text {
                                text: lost
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                            }
                        }
                    }
                }

                ListView {
                    id: rankingList
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: listBanner.bottom
                    anchors.bottom: parent.bottom
                    anchors.leftMargin: 0
                    anchors.rightMargin: 0
                    anchors.topMargin: 0
                    anchors.bottomMargin: 0
                    interactive: false
                    clip: true
                    model: playerListModel
                    delegate: playerDelegate
                }

                Item {
                    id: listBanner
                    width: parent.width
                    height: 40
                    anchors.top: parent.top
                    anchors.topMargin: 0
                    anchors.horizontalCenter: parent.horizontalCenter

                    Rectangle {
                        id: textLp
                        width: 40
                        height: 40
                        color: "#ffcf99"
                        border.width: 1
                        anchors.left: parent.left
                        anchors.top: parent.top
                        anchors.leftMargin: 0
                        anchors.topMargin: 0

                        Text {
                            anchors.fill: parent
                            text: "Lp."
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            font.pointSize: 12
                        }
                    }
                    Rectangle {
                        id: textUser
                        width: 185
                        height: 40
                        color: "#ffcf99"
                        border.width: 1
                        anchors.left: textLp.right
                        anchors.top: parent.top
                        anchors.leftMargin: -1
                        anchors.topMargin: 0

                        Text {
                            anchors.fill: parent
                            text: "Użytkownik"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            font.pointSize: 12
                        }
                    }
                    Rectangle {
                        id: textWin
                        width: 185
                        height: 40
                        color: "#ffcf99"
                        border.width: 1
                        anchors.left: textUser.right
                        anchors.top: parent.top
                        anchors.leftMargin: -1
                        anchors.topMargin: 0

                        Text {
                            anchors.fill: parent
                            text: "Wygrane"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            font.pointSize: 12
                        }
                    }
                    Rectangle {
                        id: textLost
                        width: 185
                        height: 40
                        color: "#ffcf99"
                        border.width: 1
                        anchors.left: textWin.right
                        anchors.top: parent.top
                        anchors.leftMargin: -1
                        anchors.topMargin: 0

                        Text {
                            anchors.fill: parent
                            text: "Przegrane"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            font.pointSize: 12
                        }
                    }
                }
            }
        }
        columns: 2
        columnSpacing: 0
    }
    states: [
        State {
            name: "loginAccount"
            PropertyChanges {
                target: loader
                source: "LoginPanel.qml"
            }
        },
        State {
            name: "newAccount"
            PropertyChanges {
                target: loader
                source: "NewAccountPanel.qml"
            }
        },
        State {
            name: "home"
            PropertyChanges {
                target: loader
                source: "PlayPanel.qml"
            }
        }
    ]
}
