#include "include/WindowControl.h"

//konstruktor klasy
WindowControl::WindowControl(QObject* parent) : QObject(parent)
{
}

//destruktor klasy
WindowControl::~WindowControl()
{
}



//Q_PROPERTY - popupMessage
void WindowControl::setView(const QString& view)
{
	_view = view;
	emit viewChanged();
}

QString WindowControl::getView()
{
	return _view;
}



//public slot
void WindowControl::changeView(const QString& view)
{
	QString viewString = "views/%1.qml";
	viewString = viewString.arg(view);
	setView(viewString);
}