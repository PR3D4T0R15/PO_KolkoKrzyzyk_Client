function changeView(page) {

    var urlString = "views/";
    var extensionString = ".qml";
    var fileNameString = "";

    switch (page) {
        case 1:
            fileNameString = "StartView";
            break;

        case 2:
            fileNameString = "LoginView";
            break;

        case 3:
            fileNameString = "MatchmakingView";
            break;

        case 4:
            fileNameString = "GameView";
            break;

        case 5:
            fileNameString = "EndGameView";
            break;

        default:
            fileNameString = "StartView";
            break;
    }

    return urlString + fileNameString + extensionString;
}