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
}