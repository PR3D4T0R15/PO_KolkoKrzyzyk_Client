import QtQuick
import "../sounds"

StartViewForm {
    welcomeButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.welcomeButtonClicked();
        }
    }

    SoundsControls {
        id: sound
    }
}
