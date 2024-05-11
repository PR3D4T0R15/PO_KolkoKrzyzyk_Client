import QtQuick

Item {
    id: gameControl
    width: 170
    height: 160

    property string imagePath: ""
    property string controlLocation: "A1"

    Image {
        id: image
        anchors.fill: parent
        source: ""
        fillMode: Image.PreserveAspectFit
        opacity: 1.0
        visible: true
    }
    MouseArea {
        id: mouseArea
        visible: true
        anchors.fill: parent
        hoverEnabled: true

        onEntered: {
            image.source = gameControl.imagePath
            image.opacity = 0.1
        }
        onExited: {
            image.source = ""
        }
        onClicked: {

        }
    }

    states: [
        State {
            name: "circle_notSet"
            PropertyChanges {
                target: gameControl
                imagePath: "../images/o.png"
            }
        },
        State {
            name: "cross_notSet"
            PropertyChanges {
                target: gameControl
                imagePath: "../images/x.png"
            }
        },
        State {
            name: "circle_set"
            PropertyChanges {
                target: mouseArea
                visible: false
            }
            PropertyChanges {
                target: image
                source: "../images/o.png"
            }
        },
        State {
            name: "cross_set"
            PropertyChanges {
                target: mouseArea
                visible: false
            }
            PropertyChanges {
                target: image
                source: "../images/x.png"
            }
        },
        State {
            name: "circle_win"
            PropertyChanges {
                target: mouseArea
                visible: false
            }
            PropertyChanges {
                target: image
                source: "../images/o.png"
            }
        },
        State {
            name: "cross_win"
            PropertyChanges {
                target: mouseArea
                visible: false
            }
            PropertyChanges {
                target: image
                source: "../images/x.png"
            }
        },
        State {
            name: "circle_fail"
            PropertyChanges {
                target: mouseArea
                visible: false
            }
            PropertyChanges {
                target: image
                source: "../images/o.png"
            }
            PropertyChanges {
                target: image
                opacity: 0.3
            }
        },
        State {
            name: "cross_fail"
            PropertyChanges {
                target: mouseArea
                visible: false
            }
            PropertyChanges {
                target: image
                source: "../images/x.png"
            }
            PropertyChanges {
                target: image
                opacity: 0.3
            }
        }
    ]
}
