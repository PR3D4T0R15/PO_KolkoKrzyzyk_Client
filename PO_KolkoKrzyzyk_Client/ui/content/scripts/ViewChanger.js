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

        

        default:
            fileNameString = "StartView";
            break;
    }

    return urlString + fileNameString + extensionString;
}