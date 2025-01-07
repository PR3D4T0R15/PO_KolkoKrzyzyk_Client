import QtQuick
import QtQuick.Controls
import "controls"
import "views"
import "sounds"
import QtQuick.Layouts
import QtQuick.Effects

Rectangle {
    id: aboutWindow
    property string cppId: "aboutWindow"
    width: 700
    height: 700
    //maximumWidth: 700
    //maximumHeight: 700
    //minimumWidth: 700
    //minimumHeight: 700
    color: "#ffcf99"

    Rectangle {
        id: rectangle
        width: 688
        height: 688
        color: "#ffcf99"
        radius: 20
        border.color: "#dd5746"
        border.width: 4
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Column {
        id: column
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.topMargin: 0
        anchors.bottomMargin: 0

        Row {
            id: row
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.topMargin: 0
            anchors.bottomMargin: 430
            spacing: 0

            Item {
                id: item1
                anchors.left: parent.left
                anchors.right: parent.horizontalCenter
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.leftMargin: 0
                anchors.rightMargin: 65
                anchors.topMargin: 0
                anchors.bottomMargin: 0

                Image {
                    id: game_logo
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.leftMargin: 60
                    anchors.topMargin: 0
                    anchors.bottomMargin: 0
                    source: "images/game_logo.png"
                    fillMode: Image.PreserveAspectFit
                }
            }

            Item {
                id: item2
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.leftMargin: 260
                anchors.rightMargin: 0
                anchors.topMargin: 0
                anchors.bottomMargin: 0

                MultiEffect {
                    x: 0
                    y: 0
                    source: rectangle_namegame
                    anchors.fill: rectangle_namegame
                    shadowBlur: 0.8
                    shadowEnabled: true
                    shadowColor: "#6e6e6e"
                    shadowVerticalOffset: 8
                }

                Image {
                    id: rectangle_namegame
                    anchors.verticalCenter: parent.verticalCenter
                    source: "images/namegame.svg"
                    anchors.horizontalCenter: parent.horizontalCenter
                    fillMode: Image.PreserveAspectFit
                }

                Text {
                    id: text1
                    text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt; font-weight:700;\">KÓŁKO I KRZYŻYK</span></p>\n<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">Wersja 1.0.0.</span></p></body></html>"
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 12
                    lineHeight: 1
                    font.wordSpacing: 0
                    anchors.verticalCenterOffset: -4
                    anchors.horizontalCenterOffset: 0
                    anchors.horizontalCenter: parent.horizontalCenter
                    textFormat: Text.RichText
                }
            }
        }

        Item {
            id: item3
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.topMargin: 270
            anchors.bottomMargin: 180

            MultiEffect {
                x: 0
                y: 0
                source: gameinforectangle
                anchors.fill: gameinforectangle
                shadowBlur: 0.8
                shadowEnabled: true
                shadowColor: "#6e6e6e"
                shadowVerticalOffset: 8
            }

            Image {
                id: gameinforectangle
                width: 615
                height: 200
                anchors.verticalCenter: parent.verticalCenter
                source: "images/gameinforectangle.svg"
                anchors.horizontalCenter: parent.horizontalCenter
                fillMode: Image.PreserveAspectFit
            }

            Text {
                id: text2
                text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\nhr { height: 1px; border-width: 0; }\nli.unchecked::marker { content: \"\\2610\"; }\nli.checked::marker { content: \"\\2612\"; }\n</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:17pt;\">Program stworzony na potrzeby zaliczenia kursu <br />“Programowanie Obiektowe”.<br />Napisany w języku </span><span style=\" font-size:17pt; font-weight:700;\">C++</span><span style=\" font-size:17pt;\"> z wykorzystaniem </span><span style=\" font-size:17pt; font-weight:700;\">bibliotek Qt</span><span style=\" font-size:17pt;\">.</span></p>\n<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:17pt; font-weight:700;\">Autorzy programu: </span><span style=\" font-size:17pt;\"><br />Mateusz Mang, Julia Czaplińska</span></p></body></html>"
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 12
                textFormat: Text.RichText
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Image {
            id: pwr_logo
            width: 430
            height: 90
            anchors.verticalCenter: parent.verticalCenter
            source: "images/pwr_logo.png"
            anchors.verticalCenterOffset: 270
            anchors.horizontalCenter: parent.horizontalCenter
            fillMode: Image.PreserveAspectFit
        }
    }
}
