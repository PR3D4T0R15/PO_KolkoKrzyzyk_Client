#include "include/MainWindowControl.h"
//konstruktor
MainWindowControl::MainWindowControl(QObject *parent): QObject(parent)
{
	_popupMessage = "";
}

//destruktor
MainWindowControl::~MainWindowControl()
{
}



//przyciski
void MainWindowControl::aboutButtonClicked()
{
	_aboutWindow = new QQuickView();
	_aboutWindow->setSource(QUrl(QStringLiteral("qrc:/content/AboutWindow.qml")));
	_aboutWindow->show();
	//TODO memoryleak!
	QObject::connect(_aboutWindow, &QQuickView::closing, this, [this]() {_aboutWindow->deleteLater(); });
}

void MainWindowControl::settingsButtonClicked()
{
}

void MainWindowControl::soundButtonClicked()
{
}



//Q_PROPERTY - popupMessage
QString MainWindowControl::getPopupMessage()
{
	return _popupMessage;
}

void MainWindowControl::setPopupMessage(const QString& popupMessage)
{
	_popupMessage = popupMessage;
	emit popupMessageChanged();
}