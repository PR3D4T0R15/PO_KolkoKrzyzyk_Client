import QtQuick

Item {
    id: gameControl
    width: 170
    height: 160

    signal clickedButton();

    state: "circle_notSet"

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
            gameControl.clickedButton();
        }
    }

    states: [
        State {
            name: "wait"
            PropertyChanges {
                target: gameControl
                imagePath: ""
            }
            PropertyChanges {
                target: image
                opacity: 0.0
            }
            PropertyChanges {
                target: mouseArea
                visible: false
            }
        },
        State {
            name: "circle_notSet"
            PropertyChanges {
                target: gameControl
                imagePath: "../images/o.png"
            }
            PropertyChanges {
                target: image
                opacity: 1.0
            }
        },
        State {
            name: "cross_notSet"
            PropertyChanges {
                target: gameControl
                imagePath: "../images/x.png"
            }
            PropertyChanges {
                target: image
                opacity: 1.0
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
            PropertyChanges {
                target: image
                opacity: 1.0
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
            PropertyChanges {
                target: image
                opacity: 1.0
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
            PropertyChanges {
                target: image
                opacity: 1.0
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
            PropertyChanges {
                target: image
                opacity: 1.0
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
