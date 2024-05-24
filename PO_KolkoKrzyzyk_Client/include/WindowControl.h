#pragma once

#include <QObject>
#include <QDebug>
#include <QQuickItem>
#include <QMetaObject>

class WindowControl : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString errInfo READ getErrInfo WRITE setErrInfo NOTIFY errInfoChanged)

public:
	WindowControl(QObject* parent = nullptr);
	~WindowControl();

	//Q_PROPERTY
	void setErrInfo(const QString& newErrInfo);
	QString getErrInfo();

public slots:
	//QML
	void uiButtonClicked(QObject* obj);		//message from QML

	

signals:
	//QML
	void uiChangeView(QString view);		//message to QML
	void uiChangeState(QString state);		//message to QML

	//Q_PROPERTY
	void errInfoChanged();

private:
	QString _errInfo;
};
