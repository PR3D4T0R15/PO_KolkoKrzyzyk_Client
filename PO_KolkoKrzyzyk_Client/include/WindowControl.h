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
	void uiButtonClicked(QObject* obj);

signals:
	void uiChangeView(QString view);
	void uiChangeState(QString state);

private:
};
