#include "include/WindowControl.h"

WindowControl::WindowControl(QObject* parent) : QObject(parent)
{
}

WindowControl::~WindowControl()
{
}

void WindowControl::enterGameButton()
{
	qDebug() << "Big Button was clicked!";
	emit goToLoginWindow();
}

