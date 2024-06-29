import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "controls"
import "views"
import "sounds"
import "popups"
import backend.WindowControl 1.0
import backend.MainWindowControl 1.0

Window {
	id: mainWindow

	property string cppId: "mainWindow"
	property alias windowControl: windowControl
	property alias mainWindowControl: mainWindowControl

	color: "#ffcf99"
	height: 720
	minimumHeight: 480
	minimumWidth: 720
	//visibility: Window.Maximized
	visible: true
	width: 1280

	WindowControl {
		id: windowControl

		onViewChanged: {
			stackView.replace(windowControl.view);
		}
	}

	MainWindowControl {
		id: mainWindowControl

		onPopupMessageChanged: {
			gameInfoPopup.textMessage = mainWindowControl.popupMessage;
			gameInfoPopup.open();
		}
	}

	ColumnLayout {
		id: buttonBar

		//anchors.top: parent.top
		anchors.bottom: parent.bottom
		anchors.left: parent.left
		layoutDirection: Qt.RightToLeft
		spacing: 0
		width: 39

		SoundControl {
			id: soundControl

			property string cppId: "soundControlButton"

			Layout.alignment: Qt.AlignBottom
			Layout.fillHeight: false
			Layout.fillWidth: false
			implicitHeight: 39
			implicitWidth: 39

			onClicked: {
				sound.buttonClickSound.play();
				mainWindowControl.soundButtonClicked();
			}
		}
		AboutButton {
			id: aboutButton

			property string cppId: "aboutButton"

			Layout.alignment: Qt.AlignBottom
			Layout.fillHeight: false
			Layout.fillWidth: false

			onClicked: {
				sound.buttonClickSound.play();
				mainWindowControl.aboutButtonClicked();
			}
		}
		SettingsButton {
			id: settingsButton

			property string cppId: "settingsButton"

			Layout.alignment: Qt.AlignBottom
			Layout.fillHeight: false
			Layout.fillWidth: false

			onClicked: {
				sound.buttonClickSound.play();
				mainWindowControl.settingsButtonClicked();
			}
		}
	}
	StackView {
		id: stackView

		anchors.bottom: parent.bottom
		anchors.bottomMargin: 20
		anchors.left: buttonBar.right
		anchors.leftMargin: 20
		anchors.right: parent.right
		anchors.rightMargin: 20
		anchors.top: parent.top
		anchors.topMargin: 20
		//initialItem: "views/StartView.qml"
		initialItem: "views/GameView.qml"
	}
	GameInfoPopup {
		id: gameInfoPopup

		visible: false
	}

	//sound manager
	SoundsControls {
		id: sound
	}
	SoundsControls {
		id: soundBackground
	}

	Component.onCompleted: {
		connManager.changeView.connect(windowControl.changeView);
	}
}