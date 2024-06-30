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
            endGameViewForm.goToMenuButtonClicked();
        }
    }

    playAgainButton {
        onClicked: {
            sound.buttonClickSound.play()
            endGameViewForm.playAgainButtonClicked();
        }
    }

    SoundsControls {
        id: sound
    }

    Component.onCompleted: {
        endGameViewForm.changeView.connect(mainWindow.windowControl.changeView);
    }
}
