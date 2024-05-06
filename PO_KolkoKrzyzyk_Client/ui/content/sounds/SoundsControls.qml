import QtQuick
import QtMultimedia

Item {
    property alias buttonClickSound: buttonClickSound
    property alias gameFieldClickSound: gameFieldClickSound
    property alias backgroundSound: backgroundSound
    property alias gameDefeat: gameDefeat
    property alias gameWin: gameWin

    //buttons
    SoundEffect {
        id: buttonClickSound
        source: "buttonClicked1.wav"
    }
    SoundEffect {
        id: gameFieldClickSound
        source: "buttonClicked_gameField.wav"
    }

    //background
    SoundEffect {
        id: backgroundSound
        loops: SoundEffect.Infinite
        source: "background1.wav"
    }

    //game
    SoundEffect {
        id: gameDefeat
        source: "defeat.wav"
    }
    SoundEffect {
        id: gameWin
        source: "win.wav"
    }
}
