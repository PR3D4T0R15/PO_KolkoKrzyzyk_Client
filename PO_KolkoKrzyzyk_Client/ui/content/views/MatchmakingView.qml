import QtQuick 2.15
import "../sounds"

MatchmakingViewForm {
    exitMatchmakingButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.uiButtonClicked(exitMatchmakingButton);
        }
    }

    SoundsControls {
        id: sound
    }
}