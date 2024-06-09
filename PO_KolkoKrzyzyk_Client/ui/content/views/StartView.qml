import QtQuick
import backend.StartViewControl 1.0
import "../sounds"

StartViewForm {
    welcomeButton {
        onClicked: {
            sound.buttonClickSound.play();
            startViewControl.welcomeButtonClicked();
        }
    }
    
    StartViewControl {
        id: startViewControl
       
    }

    SoundsControls {
        id: sound
    }

    Component.onCompleted: {
        startViewControl.changeView.connect(mainWindow.windowControl.changeView);
    }
}
