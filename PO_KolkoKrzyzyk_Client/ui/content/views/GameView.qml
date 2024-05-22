import QtQuick
import "../sounds"

GameViewForm {
    gameLeaveButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.uiButtonClicked(gameLeaveButton);
        }
    }

    SoundsControls {
        id: sound
    }
}

