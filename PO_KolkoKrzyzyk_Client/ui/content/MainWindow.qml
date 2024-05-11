import QtQuick
import QtQuick.Controls
import "controls"
import "views"
import "sounds"
import QtQuick.Layouts

Window {
    id: mainWindow
    width: 1280
    height: 720
    minimumWidth: 720
    minimumHeight: 480
    //visibility: Window.Maximized
    visible: true

    color: "#ffcf99"

    ColumnLayout {
        id: buttonBar

        anchors.left: parent.left
        //anchors.top: parent.top
        anchors.bottom: parent.bottom
        layoutDirection: Qt.RightToLeft
        spacing: 0
        width: 39

        SoundControl {
            id: soundControl
            implicitWidth: 39
            implicitHeight: 39
            Layout.fillHeight: false
            Layout.fillWidth: false
            Layout.alignment: Qt.AlignBottom
            onClicked: {
                sound.buttonClickSound.play()
            }
        }

        AboutButton {
            id: aboutButton
            Layout.fillHeight: false
            Layout.fillWidth: false
            Layout.alignment: Qt.AlignBottom
            onClicked: {
                sound.buttonClickSound.play()
            }
        }

        SettingsButton {
            id: settingsButton
            Layout.fillHeight: false
            Layout.fillWidth: false
            Layout.alignment: Qt.AlignBottom
            onClicked: {
                sound.buttonClickSound.play()
            }
        }
    }

    StackView {
        id: stackView

        anchors.left: buttonBar.right
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.leftMargin: 20
        anchors.rightMargin: 20
        anchors.topMargin: 20
        anchors.bottomMargin: 20

        initialItem: gameView
    }
    //stackedView views
    StartView {
        id: startView
        visible: false
    }
    LoginView {
        id: loginView
        visible: false
    }
    MatchmakingView {
        id: matchmakingView
        visible: false
    }
    GameView {
        id: gameView
        visible: false
    }
    EndGameView {
        id: endGameView
        visible: false
    }

    //sound manager
    SoundsControls {
        id: sound
    }
}