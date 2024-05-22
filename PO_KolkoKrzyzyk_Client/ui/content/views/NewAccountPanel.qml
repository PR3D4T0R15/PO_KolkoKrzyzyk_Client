import QtQuick
import "../sounds"

NewAccountPanelForm{
    logInButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.uiButtonClicked(logInButton);
        }
    }

    newAccountButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.uiButtonClicked(newAccountButton);
        }
    }

    SoundsControls {
        id: sound
    }
}
