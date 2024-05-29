import QtQuick 2.15
import "../sounds"

LoginPanelForm {
    logInButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.logInButtonClicked();
        }
    }

    newAccountButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.newAccountButtonClicked();
        }
    }

    SoundsControls {
        id: sound
    }
}
