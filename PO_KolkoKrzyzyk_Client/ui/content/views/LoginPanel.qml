import QtQuick 2.15
import "../sounds"

LoginPanelForm {
    logInButton {
        onClicked: {
            var userName = loginField.text;
            var pass = passField.text;
            sound.buttonClickSound.play();
            windowControl.logInButtonClicked();
            windowControl.sendLoginCred(userName, pass);
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
