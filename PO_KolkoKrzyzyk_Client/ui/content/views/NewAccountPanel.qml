import QtQuick
import "../sounds"
import "../scripts/CheckUsername.js" as CheckUsername
import "../scripts/CheckPass.js" as CheckPass

NewAccountPanelForm{
    logInButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.goToLoginButtonClicked();
        }
    }

    newAccountButton {
        onClicked: {
            sound.buttonClickSound.play()
            windowControl.createNewAccountButtonClicked();
        }
    }

    loginField {
        onTextEdited: {
            var userName = loginField.text;
            var result = CheckUsername.validateUsername(userName);
            
            if (result.valid) {
                loginField.state = "ok";
                errorText.text = "";
            } else {
                loginField.state = "error";
                errorText.text = result.message;
            }
        }
    }

    passField{
        onTextEdited: {
            var pass1 = passField.text;
            var pass2 = pass2Field.text;
            var result = CheckPass.validatePass(pass1)
            if (result.valid) {
                passField.state = "ok";
                errorText.text = "";
            } else {
                passField.state = "error";
                errorText.text = result.message;
            }
        }
    }

    pass2Field{
        onTextEdited: {
            var pass1 = passField.text;
            var pass2 = pass2Field.text;
            var result = CheckPass.checkIfEqual(pass1, pass2)
            if (result.valid) {
                pass2Field.state = "ok";
                errorText.text = "";
            } else {
                pass2Field.state = "error";
                errorText.text = result.message;
            }
        }
    }

    SoundsControls {
        id: sound
    }
}
