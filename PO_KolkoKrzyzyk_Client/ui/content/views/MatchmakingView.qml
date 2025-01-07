import QtQuick
import "../sounds"
import backend.MatchmakingViewControl

MatchmakingViewForm {
    MatchmakingViewControl {
        id: matchmakingViewControl
    }

    exitMatchmakingButton {
        onClicked: {
            sound.buttonClickSound.play();
            matchmakingViewControl.exitMatchmakingButtonClicked();
        }
    }

    SoundsControls {
        id: sound
    }

    Component.onCompleted: {
        matchmakingViewControl.changeView.connect(mainWindow.windowControl.changeView);
        matchmakingViewControl.sendData.connect(connManager.sendDataFromQml);
        connManager.sendDataToQml.connect(matchmakingViewControl.receiveData);
        matchmakingViewControl.joinMatchmaking();
    }
}