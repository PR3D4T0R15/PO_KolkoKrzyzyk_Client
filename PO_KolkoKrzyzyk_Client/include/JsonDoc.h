#pragma once

#include <QJsonDocument>
#include <QString>
#include <QByteArray>
#include <QCryptographicHash>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

namespace jsonDoc
{
	class JsonDoc
	{
	public:
		static QString getAction(const QJsonDocument& jsonDoc);
		static QJsonArray getData(const QJsonDocument& jsonDoc);
		static QByteArray toBytes(const QJsonDocument& jsonDoc);
		static QJsonDocument toJson(const QByteArray& jsonByte);

	protected:
		static QString hashData(const QString& data);
		static QJsonObject createData(const QString& username, const QString& password);
		static QJsonObject createData(const QString& username);
		static QJsonObject createData(const QString& username, const bool& status);
	};

	class AccountDoc : JsonDoc
	{
	public:
		static QJsonDocument logIn(const QString& username, const QString& password);
		static QJsonDocument newAccount(const QString& username, const QString& password);
		static QJsonDocument logOut(const QString& username);		
	};

	class MatchDoc : JsonDoc
	{
	public:
		static QJsonDocument joinMatchmaking(const QString& username, const bool& status);
	};

}