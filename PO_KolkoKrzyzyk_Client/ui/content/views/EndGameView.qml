import QtQuick 2.15
import "../sounds"

EndGameViewForm {
    goToMenuButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.goToMenuButtonClicked();
        }
    }

    playAgainButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.playAgainButtonClicked();
        }
    }

    SoundsControls {
        id: sound
    }
}
