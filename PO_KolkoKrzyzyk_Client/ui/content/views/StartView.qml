import QtQuick
import "../sounds"

StartViewForm {
    welcomeButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.uiButtonClicked(welcomeButton);
        }
    }

    SoundsControls {
        id: sound
    }
}
