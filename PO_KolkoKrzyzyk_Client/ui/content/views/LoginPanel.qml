import QtQuick 2.15
import "../sounds"

LoginPanelForm {
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
