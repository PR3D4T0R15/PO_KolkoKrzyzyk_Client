import QtQuick
import "../scripts/PanelChanger.js" as ViewSettings

HomeViewForm {
	Connections {
        target: windowControl

        function onUiChangePanel(page) {
            stackView.replace(ViewSettings.changePanel(page));
        }
    }   
}