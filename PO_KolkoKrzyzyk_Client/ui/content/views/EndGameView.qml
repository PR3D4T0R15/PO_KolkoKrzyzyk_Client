import QtQuick 2.15
import "../sounds"
import backend.EndGameViewControl

EndGameViewForm {
    
    EndGameViewControl {
        id: endGameViewControl
        onChangePanel: function(panel) { endGameView.state = panel }
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
    }
}
