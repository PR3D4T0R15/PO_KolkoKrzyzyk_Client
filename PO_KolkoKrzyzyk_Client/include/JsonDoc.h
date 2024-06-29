#pragma once

#include <QString>
#include <QByteArray>
#include <QCryptographicHash>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QRandomGenerator>
#include <QDateTime>

namespace jsonDoc
{
	class JsonDoc
	{
	public:
		JsonDoc();
		static QString getAction(const QJsonDocument& jsonDoc);
		static QJsonObject getData(const QJsonDocument& jsonDoc);
		QJsonObject getData();

		static QByteArray toBytes(const QJsonDocument& jsonDoc);
		static QJsonDocument toJson(const QByteArray& jsonByte);

		static QString hashData(const QString& data);

		void setJson(const QJsonDocument& jsonDoc);
		void setJson(const QJsonObject& jsonObj);

		QJsonDocument getJsonDoc();
		QJsonObject getJsonObj();

	protected:
		void setDataObject(const QString& objName, const QString& objValue);
		void setDataObject(const QString& objName, const bool& objValue);
		void setDataObject(const QString& objName, const int& objValue);
		void setDataObject(const QString& objName, const QJsonArray& objValue);
		void setDataObject(const QString& objName, const QJsonObject& objValue);

		QString getDataObjectStr(const QString& objName);
		int getDataObjectInt(const QString& objName);
		bool getDataObjectBool(const QString& objName);
		QJsonArray getDataObjectArray(const QString& objName);
		QJsonObject getDataObjectJsonObj(const QString& objName);

	protected:
		QJsonObject _rootObj;
	};

	class Conn : public JsonDoc
	{
	public:
		Conn();
		void setConnId(const QString& connId);
		QString getConnId();
	};

	class Account : public JsonDoc
	{
	public:
		Account();
		void setLogin();
		void setLogout();
		void setNewaccount();

		void setUsername(const QString& username);
		QString getUsername();

		void setPassword(const QString& password);
		QString getPassword();

		void setResult(const bool& result);
		bool getResult();
	};

	class Ranking : public JsonDoc
	{
	public:
		Ranking();
		void setRankning(const QJsonDocument& jsonDoc);
		QJsonDocument getRanking();

	};

	class Matchmaking : public JsonDoc
	{
	public:
		Matchmaking();

		void setJoin();
		void setLeave();
		void setUpdateInfo();

		void setConnId(const QString& connId);
		QString getConnId();

		void setPlayerName(const QString& username);
		QString getPlayerName();

		void setPlayersInQueueCount(const int& count);
		int getPlayersInQueueCount();
		
	};

	class Game : public JsonDoc
	{
	public:
		Game();

		QJsonArray getGameField();
		void setGameField(const QJsonArray& gameField);

		QString getStartingPawn();
		QString getPlayerPawn(const QString& playerName);
		int getRoundCount();

	private:
		
	};
}
