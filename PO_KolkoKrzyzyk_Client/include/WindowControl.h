#pragma once

#include <QObject>
#include <QDebug>
#include <QQuickItem>

class WindowControl : public QObject
{
	Q_OBJECT

public:
	WindowControl(QObject* parent = nullptr);
	~WindowControl();

public slots:
	// void callMe();
	// implement - do sth
	void uiButtonClicked(QObject* obj);

signals:
	// void IWillCallSlotToDoSth()
	// not implement - emit signal
	void uiChangeView(int page);

private:
};
