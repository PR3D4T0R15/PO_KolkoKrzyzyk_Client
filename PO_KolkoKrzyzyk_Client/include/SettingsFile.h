#pragma once

#include <QObject>
#include <QSettings>
#include <QFile>
#include <QString>
#include <QDebug>

class SettingsFile : public QObject
{
	Q_OBJECT

public:
	SettingsFile(QObject *parent = nullptr);
	~SettingsFile();

	QString getServerAddress();
	QString getServerPort();

private:
	QSettings* _settings;
};
