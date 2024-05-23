import QtQuick
import "../scripts/PanelChanger.js" as ViewSettings

LoginViewForm {
	Connections {
        target: windowControl

        function onUiChangePanel(page) {
            stackView.replace(ViewSettings.changePanel(page));
        }
    }   
}