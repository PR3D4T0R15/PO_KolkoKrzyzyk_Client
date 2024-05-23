import QtQuick
import "../sounds"
import "../scripts/CheckUsername.js" as CheckUsername
import "../scripts/CheckPass.js" as CheckPass

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

    loginField {
        onTextEdited: {
            var userName = loginField.text;
            var result = CheckUsername.validateUsername(userName);
            console.log(result);
        }
    }

    passField{
    }

    pass2Field{
    }

    SoundsControls {
        id: sound
    }
}
