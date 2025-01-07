#pragma once

#include <QObject>
#include <QDebug>

class StartViewControl : public QObject
{
	Q_OBJECT
		Q_PROPERTY(QString errorString READ getErrorString WRITE setErrorString NOTIFY errorStringChanged)

public:
	explicit StartViewControl(QObject *parent = nullptr);
	~StartViewControl();

	//Q_PROPERTY
	void setErrorString(const QString& errorString);
	QString getErrorString();

public slots:
	void welcomeButtonClicked();

private slots:

signals:
	void changeView(QString view);
	//Q_PROPERTY
	void errorStringChanged();

private:
	bool _conectionStatus;
	QString _errorString;
};
