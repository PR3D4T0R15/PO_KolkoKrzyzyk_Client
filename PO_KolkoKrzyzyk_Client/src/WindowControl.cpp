#include "include/WindowControl.h"

WindowControl::WindowControl(QObject* parent) : QObject(parent)
{
}

WindowControl::~WindowControl()
{
}

void WindowControl::uiButtonClicked(QObject* obj)
{
	QString cppId = obj->property("cppId").toString();

	qDebug() << "Button" << cppId;

	if (cppId == "welcomeButton")
	{
		emit uiChangeView(2);
	}
	if (cppId == "logInButton")
	{
		
	}
	if (cppId == "newAccountButton")
	{
		emit uiChangePanel(2);
	}
	if (cppId == "goToLoginButton")
	{
		emit uiChangePanel(1);
	}
}