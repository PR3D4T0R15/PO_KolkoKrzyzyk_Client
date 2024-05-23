function changePanel(panel) {

    var extensionString = ".qml";
    var fileNameString = "";

    switch (panel) {
        case 1:
            fileNameString = "LoginPanel";
            break;

        case 2:
            fileNameString = "NewAccountPanel";
            break;

        case 3:
            fileNameString = "PlayPanel";
            break;

        default:
            fileNameString = "LoginPanel";
            break;
    }

    return fileNameString + extensionString;
}