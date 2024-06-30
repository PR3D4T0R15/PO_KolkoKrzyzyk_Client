import QtQuick
import "../sounds"
import backend.GameViewControl

GameViewForm {
    GameViewControl {
        id: gameViewControl

        onButtonA1Changed: {
            gameControlA1.state = gameViewControl.buttonA1state;
        }
        onButtonA2Changed: {
            gameControlA2.state = gameViewControl.buttonA2state;
        }
        onButtonA3Changed: {
            gameControlA3.state = gameViewControl.buttonA3state;
        }
        onButtonB1Changed: {
            gameControlB1.state = gameViewControl.buttonB1state;
        }
        onButtonB2Changed: {
            gameControlB2.state = gameViewControl.buttonB2state;
        }
        onButtonB3Changed: {
            gameControlB3.state = gameViewControl.buttonB3state;
        }
        onButtonC1Changed: {
            gameControlC1.state = gameViewControl.buttonC1state;
        }
        onButtonC2Changed: {
            gameControlC2.state = gameViewControl.buttonC2state;
        }
        onButtonC3Changed: {
            gameControlC3.state = gameViewControl.buttonC3state;
        }

        onRoundTitleChanged: {
            roundText.text = gameViewControl.roundTitle
        }
        onRoundIcoChanged: {
            roundImage.source = gameViewControl.roundIco
        }
        onCountdownChanged: {
            timeLeftValue.text = gameViewControl.countdown
        }

        Component.onCompleted: {
            gameViewControl.uiReady();
        }
    }  

    gameLeaveButton {
        onClicked: {
            sound.buttonClickSound.play()
            gameViewControl.gameLeaveButton();
        }
    }

    gameControlA1{
        onClickedButton: {
            gameViewControl.buttonA1Clicked();
        }
    }
    gameControlA2{
        onClickedButton: {
            gameViewControl.buttonA2Clicked();
        }
    }
    gameControlA3{
        onClickedButton: {
            gameViewControl.buttonA3Clicked();
        }
    }
    gameControlB1{
        onClickedButton: {
            gameViewControl.buttonB1Clicked();
        }
    }
    gameControlB2{
        onClickedButton: {
            gameViewControl.buttonB2Clicked();
        }
    }
    gameControlB3{
        onClickedButton: {
            gameViewControl.buttonB3Clicked();
        }
    }
    gameControlC1{
        onClickedButton: {
            gameViewControl.buttonC1Clicked();
        }
    }
    gameControlC2{
        onClickedButton: {
            gameViewControl.buttonC2Clicked();
        }
    }
    gameControlC3{
        onClickedButton: {
            gameViewControl.buttonC3Clicked();
        }
    }

    SoundsControls {
        id: sound
    }

    Component.onCompleted: {
		connManager.sendDataToQml.connect(gameViewControl.receiveData);
        connManager.changeView.connect(mainWindow.windowControl.changeView);
	}
}

