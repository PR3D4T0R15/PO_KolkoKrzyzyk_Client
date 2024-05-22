import QtQuick 2.15
import "../sounds"

EndGameViewForm {
    goToMenuButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.uiButtonClicked(goToMenuButton);
        }
    }

    playAgainButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.uiButtonClicked(playAgainButton);
        }
    }

    SoundsControls {
        id: sound
    }
}
