#include "include/SettingsFile.h"

SettingsFile::SettingsFile(QObject *parent): QObject(parent)
{
	QString filePath = "config.ini";

	QFile file(filePath);

	if (file.exists())
	{
		_settings = new QSettings(filePath, QSettings::IniFormat);
	}
	else
	{
		qCritical() << "Settings file " << filePath << " not found";
		exit(-1);
	}
}

SettingsFile::~SettingsFile()
{
	_settings->deleteLater();
}

QString SettingsFile::getServerAddress()
{
	return _settings->value("Server/host").toString();
}

QString SettingsFile::getServerPort()
{
	return _settings->value("Server/port").toString();
}