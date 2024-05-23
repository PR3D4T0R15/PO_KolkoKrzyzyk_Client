import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "controls"
import "views"
import "sounds"
import "scripts/ViewChanger.js" as ViewSettings

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
            property string cppId: "soundControl"
            implicitWidth: 39
            implicitHeight: 39
            Layout.fillHeight: false
            Layout.fillWidth: false
            Layout.alignment: Qt.AlignBottom
            onClicked: {
                sound.buttonClickSound.play()
                windowControl.uiButtonClicked(soundControl);
            }
        }

        AboutButton {
            id: aboutButton
            property string cppId: "aboutButton"
            Layout.fillHeight: false
            Layout.fillWidth: false
            Layout.alignment: Qt.AlignBottom
            onClicked: {
                sound.buttonClickSound.play()
                windowControl.uiButtonClicked(aboutButton);
            }
        }

        SettingsButton {
            id: settingsButton
            property string cppId: "settingsButton"
            Layout.fillHeight: false
            Layout.fillWidth: false
            Layout.alignment: Qt.AlignBottom
            onClicked: {
                sound.buttonClickSound.play()
                windowControl.uiButtonClicked(settingsButton);
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

        initialItem: "views/StartView.qml"
    }
    //sound manager
    SoundsControls {
        id: sound
    }

    //CppQML integration
    Connections {
        target: windowControl

        function onUiChangeView(panel) {
            stackView.replace(ViewSettings.changeView(panel))
        }
    }
}
