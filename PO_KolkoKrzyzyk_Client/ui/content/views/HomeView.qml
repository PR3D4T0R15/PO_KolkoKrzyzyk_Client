import QtQuick
import backend.HomeViewControl 1.0

HomeViewForm {
	property alias homeViewControl: homeViewControl

	HomeViewControl {
		id: homeViewControl
		onChangeState: function(stateStr) { homeView.state = stateStr }

		onPlayerRankingChanged: {
			playerListModel.clear();
			playerListModel.append(homeViewControl.playerRanking);
		}

		Component.onCompleted: {
			connManager.sendDataToQml.connect(homeViewControl.receiveData);
			homeViewControl.sendData.connect(connManager.sendDataFromQml);
			homeViewControl.windowReady();
			homeViewControl.queryPlayerRanking();
		}
	}
}