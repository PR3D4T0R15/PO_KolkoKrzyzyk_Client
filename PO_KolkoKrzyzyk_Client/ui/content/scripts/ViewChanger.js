function changeView(view) {

    var urlString = "views/";
    var extensionString = ".qml";

    return urlString + view + extensionString;
}

function changeState(state) {
    var extensionString = ".qml";

    return state + extensionString;
}