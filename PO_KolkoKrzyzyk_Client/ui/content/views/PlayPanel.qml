import QtQuick
import "../sounds"

PlayPanelForm {
    playButton {
        onClicked: {
            sound.buttonClickSound.play();
            homeView.homeViewControl.playButtonClicked();
        }
    }
    logOutButton {
        onClicked: {
            sound.buttonClickSound.play();
            homeView.homeViewControl.logOutButtonClicked();
        }
    }
    exitButton {
        onClicked: {
            sound.buttonClickSound.play();
            homeView.homeViewControl.exitButtonClicked();
        }
    }

    SoundsControls {
        id: sound
    }

    Component.onCompleted: {
        homeView.homeViewControl.changeView.connect(mainWindow.windowControl.changeView);
    }
}
