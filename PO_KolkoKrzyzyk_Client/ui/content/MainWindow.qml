import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "controls"
import "views"
import "sounds"
import "popups"

Window {
	id: mainWindow

	property string cppId: "mainWindow"

	color: "#ffcf99"
	height: 720
	minimumHeight: 480
	minimumWidth: 720
	//visibility: Window.Maximized
	visible: true
	width: 1280

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
				windowControl.soundButtonClicked();
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
				windowControl.aboutButtonClicked();
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
				windowControl.settingsButtonClicked();
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
		initialItem: ""
	}
	GameInfoPopup {
        id: gameInfoPopup
        visible: false
    }
	
	//sound manager
	SoundsControls {
		id: sound

	}

	//CppQML integration
	Connections {
		function onPopupMessageChanged() {
			gameInfoPopup.textMessage = windowControl.popupMessage;
			gameInfoPopup.open();
		}

		function onInLoginView() {
			var view = stackView.currentItem;
			if (view.cppId == "homeView") {
				view.state = "loginAccount";
			} else {
				stackView.replace("views/HomeView.qml");
				var view = stackView.currentItem;
				view.state = "loginAccount";
			}
		}
		function onInNewAccountView() {
			var view = stackView.currentItem;
			if (view.cppId == "homeView") {
				view.state = "newAccount";
			} else {
				stackView.replace("views/HomeView.qml");
				var view = stackView.currentItem;
				view.state = "newAccount";
			}
		}
		function onInStartView() {
			stackView.replace("views/StartView.qml");
		}

		target: windowControl
	}
}
