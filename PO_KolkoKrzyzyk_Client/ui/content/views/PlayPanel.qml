import QtQuick
import "../sounds"

PlayPanelForm {
    playButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.uiButtonClicked(playButton)
        }
    }
    logOutButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.uiButtonClicked(logOutButton)
        }
    }
    exitButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.uiButtonClicked(exitButton)
        }
    }

    SoundsControls {
        id: sound
    }
}
