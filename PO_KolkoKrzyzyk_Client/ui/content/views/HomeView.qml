import QtQuick

HomeViewForm {
	Connections {
		target: windowControl

		function onPlayerRankingChanged(data) {
			playerListModel.clear();
			playerListModel.apped(data);
		}
	}
}