import QtQuick
import "../sounds"

StartViewForm {
    bigButton {
        onClicked: {
            sound.buttonClickSound.play()
            uiControl.enterGameButton();
        }
    }

    SoundsControls {
        id: sound
    }
}
