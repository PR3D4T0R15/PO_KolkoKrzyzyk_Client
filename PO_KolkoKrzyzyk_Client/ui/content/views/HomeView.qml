import QtQuick

HomeViewForm {
	Connections {
		target: windowControl

		function onPlayerRankingChanged() {
			playerListModel.clear();
			playerListModel.append(windowControl.playerRanking);
		}
	}
}