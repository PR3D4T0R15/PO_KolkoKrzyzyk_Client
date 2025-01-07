#include "include/StartViewControl.h"

//konsttruktor
StartViewControl::StartViewControl(QObject *parent): QObject(parent)
{
	_errorString = "";
}

//destruktor
StartViewControl::~StartViewControl()
{
}

void StartViewControl::setErrorString(const QString& errorString)
{
	_errorString = errorString;
	emit errorStringChanged();
}

QString StartViewControl::getErrorString()
{
	return _errorString;
}


//public slot
void StartViewControl::welcomeButtonClicked()
{
	emit changeView("HomeView");
}