#pragma once

#include <QObject>
#include <QQuickView>
#include <QDebug>

class MainWindowControl : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString popupMessage READ getPopupMessage WRITE setPopupMessage NOTIFY popupMessageChanged)

public:
	explicit MainWindowControl(QObject *parent = nullptr);
	~MainWindowControl();

	//Q_PROPERTY
	void setPopupMessage(const QString& popupMessage);
	QString getPopupMessage();


public slots:
	void aboutButtonClicked();
	void settingsButtonClicked();
	void soundButtonClicked();

private slots:

signals:
	//Q_PROPERTY
	void popupMessageChanged();

private:
	//Q_PROPERTY
	QString _popupMessage;

	QQuickView* _aboutWindow;
};
