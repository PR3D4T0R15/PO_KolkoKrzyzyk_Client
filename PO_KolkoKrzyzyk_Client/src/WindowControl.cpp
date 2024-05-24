#include "include/WindowControl.h"

WindowControl::WindowControl(QObject* parent) : QObject(parent)
{
	_errInfo = "";
}

WindowControl::~WindowControl()
{
}

QString WindowControl::getErrInfo()
{
	return _errInfo;
}

//get button id from QML and send with signal to other class in cpp
void WindowControl::uiButtonClicked(QObject* obj)
{
	QString cppId = obj->property("cppId").toString();

	qDebug() << "Button" << cppId;
	setErrInfo("test");
}

void WindowControl::setErrInfo(const QString& newErrInfo)
{
	_errInfo = newErrInfo;
	emit errInfoChanged();
}
