import QtQuick
import "../sounds"

GameViewForm {
    gameLeaveButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.gameLeaveButtonClicked();
        }
    }

    SoundsControls {
        id: sound
    }
}

