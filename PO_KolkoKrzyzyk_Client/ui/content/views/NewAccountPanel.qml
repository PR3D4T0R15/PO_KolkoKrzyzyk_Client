import QtQuick
import "../sounds"
import "../scripts/CheckUsername.js" as CheckUsername
import "../scripts/CheckPass.js" as CheckPass

NewAccountPanelForm{
    logInButton {
        onClicked: {
            sound.buttonClickSound.play()
            homeView.homeViewControl.goToLoginButtonClicked();
        }
    }

    newAccountButton {
        onClicked: {
            sound.buttonClickSound.play()
            var userName = loginField.text;
            var pass1 = passField.text;
            var pass2 = pass2Field.text;
            var result1 = CheckUsername.validateUsername(userName);
            var result2 = CheckPass.validatePass(pass1)
            var result3 = CheckPass.checkIfEqual(pass1, pass2)

            if (result1.valid && result2.valid && result1.valid) {
                homeView.homeViewControl.login = userName;
                homeView.homeViewControl.password = pass1;
                homeView.homeViewControl.createNewAccountButtonClicked();
            }
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
