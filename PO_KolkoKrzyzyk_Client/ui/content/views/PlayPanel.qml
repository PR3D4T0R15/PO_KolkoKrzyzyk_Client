import QtQuick
import "../sounds"

PlayPanelForm {
    playButton {
        onClicked: {
            sound.buttonClickSound.play();
            windowControl.playButtonClicked();
        }
    }
    logOutButton {
        onClicked: {
            sound.buttonClickSound.play();
            windowControl.logOutButtonClicked();
        }
    }
    exitButton {
        onClicked: {
            sound.buttonClickSound.play();
            windowControl.exitButtonClicked();
        }
    }

    SoundsControls {
        id: sound
    }
}
