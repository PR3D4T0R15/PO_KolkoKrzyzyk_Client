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
    visibility: Window.Maximized

    color: "#ffcf99"

    ColumnLayout {
        id: buttonBar

        anchors.left: parent.left
        //anchors.top: parent.top
        anchors.bottom: parent.bottom
        layoutDirection: Qt.RightToLeft
        spacing: 5
        width: 39

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

        initialItem: startView
    }
    //stackedView views
    StartView {
        id: startView
        visible: false
        bigButton {
            onClicked: {
                stackView.replace(loginView)
            }
        }
    }
    LoginView {
        id: loginView
        visible: false
    }

    //sound manager
    SoundsControls {
        id: sound
    }
}
