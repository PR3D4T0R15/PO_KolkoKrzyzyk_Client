import QtQuick 2.15
import "../sounds"

LoginPanelForm {
    logInButton {
        onClicked: {
            var userName = loginField.text;
            var pass = passField.text;
            sound.buttonClickSound.play();
            homeView.homeViewControl.login = loginField.text;
            homeView.homeViewControl.password = passField.text;
            homeView.homeViewControl.logInButtonClicked();
        }
    }

    newAccountButton {
        onClicked: {
            sound.buttonClickSound.play()
            homeView.homeViewControl.newAccountButtonClicked();
        }
    }

    SoundsControls {
        id: sound
    }
}
