import QtQuick
import "../sounds"

StartViewForm {
    bigButton {
        onClicked: {
            sound.buttonClickSound.play()
        }
    }

    SoundsControls {
        id: sound
    }
}
