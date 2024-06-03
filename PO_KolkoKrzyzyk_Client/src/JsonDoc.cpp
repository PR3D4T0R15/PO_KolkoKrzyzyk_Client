#include "include/JsonDoc.h"

QString jsonDoc::JsonDoc::getAction(const QJsonDocument& jsonDoc)
{
	if (!jsonDoc.isNull())
	{
		QJsonObject jsonObj = jsonDoc.object();
		QString action = jsonObj["action"].toString();

		return action;
	}
	return nullptr;
}

QJsonArray jsonDoc::JsonDoc::getData(const QJsonDocument& jsonDoc)
{
	QJsonArray array;

	if (!jsonDoc.isNull())
	{
		QJsonObject jsonObj = jsonDoc.object();
		array = jsonObj["data"].toArray();
	}

	return array;
}

QByteArray jsonDoc::JsonDoc::toBytes(const QJsonDocument& jsonDoc)
{
	return jsonDoc.toJson();
}

QJsonDocument jsonDoc::JsonDoc::toJson(const QByteArray& jsonByte)
{
	return QJsonDocument::fromJson(jsonByte);
}

//jsonDoc - private
QString jsonDoc::JsonDoc::hashData(const QString& data)
{
	QByteArray dataByte = data.toUtf8();

	return QCryptographicHash::hash(dataByte, QCryptographicHash::Sha256).toHex();
}

QJsonObject jsonDoc::JsonDoc::createData(const QString& username, const QString& password)
{
	QJsonObject dataObject;
	dataObject["username"] = username;
	dataObject["password"] = jsonDoc::JsonDoc::hashData(password);

	return dataObject;
}

QJsonObject jsonDoc::JsonDoc::createData(const QString& username)
{
	QJsonObject dataObject;
	dataObject["username"] = username;

	return dataObject;
}

QJsonObject jsonDoc::JsonDoc::createData(const QString& username, const bool& status)
{
	QJsonObject dataObject;
	dataObject["username"] = username;
	if (status)
	{
		dataObject["action"] = "join";
	}
	else
	{
		dataObject["action"] = "leave";
	}

	return dataObject;
}


//accountDoc - public
QJsonDocument jsonDoc::AccountDoc::logIn(const QString& username, const QString& password)
{
	QJsonObject rootObject;
	rootObject["action"] = "login";
	rootObject["data"] = jsonDoc::JsonDoc::createData(username, password);

	QJsonDocument jsonDoc(rootObject);

	return jsonDoc;
}

QJsonDocument jsonDoc::AccountDoc::newAccount(const QString& username, const QString& password)
{
	QJsonObject rootObject;
	rootObject["action"] = "newAccount";
	rootObject["data"] = jsonDoc::JsonDoc::createData(username, password);

	QJsonDocument jsonDoc(rootObject);

	return jsonDoc;
}

QJsonDocument jsonDoc::AccountDoc::logOut(const QString& username)
{
	QJsonObject rootObject;
	rootObject["action"] = "logout";
	rootObject["data"] = jsonDoc::JsonDoc::createData(username);

	QJsonDocument jsonDoc(rootObject);

	return jsonDoc;
}


//matchDoc - public
QJsonDocument jsonDoc::MatchDoc::joinMatchmaking(const QString& username, const bool& status)
{
	QJsonObject rootObject;
	rootObject["action"] = "matchmaking";

	rootObject["data"] = jsonDoc::JsonDoc::createData(username, status);

	QJsonDocument jsonDoc(rootObject);

	return jsonDoc;
}
