import QtQuick 2.15
import "../sounds"
import backend.EndGameViewControl

EndGameViewForm {
    
    EndGameViewControl {
        id: endGameViewControl
        onPanelChanged: {
            endGameView.state = endGameViewControl.panel;
            console.log(endGameViewControl.panel);
            endSound.play();
        }
    }


    goToMenuButton {
        onClicked: {
            sound.buttonClickSound.play()
            endGameViewControl.goToMenuButtonClicked();
        }
    }

    playAgainButton {
        onClicked: {
            sound.buttonClickSound.play()
            endGameViewControl.playAgainButtonClicked();
        }
    }

    SoundsControls {
        id: sound
    }

    Component.onCompleted: {
        endGameViewControl.changeView.connect(mainWindow.windowControl.changeView);
        endGameViewControl.windowReady();
    }
}
