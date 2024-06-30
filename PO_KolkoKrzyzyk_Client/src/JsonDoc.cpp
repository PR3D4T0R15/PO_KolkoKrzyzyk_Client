#include "include/JsonDoc.h"

//JsonDoc class
jsonDoc::JsonDoc::JsonDoc()
{
	QJsonObject dataObj;
	_rootObj["data"] = dataObj;
}

QString jsonDoc::JsonDoc::getAction(const QJsonDocument& jsonDoc)
{
	QString action;

	if (!jsonDoc.isNull())
	{
		QJsonObject jsonObj = jsonDoc.object();
		action = jsonObj["action"].toString();
	}

	return action;
}

void jsonDoc::JsonDoc::setAction(const QString& action)
{
	_rootObj["action"] = action;
}

QJsonObject jsonDoc::JsonDoc::getData(const QJsonDocument& jsonDoc)
{
	QJsonObject array;

	if (!jsonDoc.isNull())
	{
		QJsonObject jsonObj = jsonDoc.object();
		array = jsonObj["data"].toObject();
	}

	return array;
}

QJsonObject jsonDoc::JsonDoc::getData()
{
	return _rootObj["data"].toObject();
}

QByteArray jsonDoc::JsonDoc::toBytes(const QJsonDocument& jsonDoc)
{
	return jsonDoc.toJson(QJsonDocument::Compact);
}

QJsonDocument jsonDoc::JsonDoc::toJson(const QByteArray& jsonByte)
{
	return QJsonDocument::fromJson(jsonByte);
}

QString jsonDoc::JsonDoc::hashData(const QString& data)
{
	QByteArray dataByte = data.toUtf8();

	return QCryptographicHash::hash(dataByte, QCryptographicHash::Sha256).toHex();
}

void jsonDoc::JsonDoc::setJson(const QJsonDocument& jsonDoc)
{
	_rootObj = jsonDoc.object();
}

void jsonDoc::JsonDoc::setJson(const QJsonObject& jsonObj)
{
	_rootObj = jsonObj;
}

QJsonDocument jsonDoc::JsonDoc::getJsonDoc()
{
	QJsonDocument jsonDoc(_rootObj);

	return jsonDoc;
}

QJsonObject jsonDoc::JsonDoc::getJsonObj()
{
	return _rootObj;
}

void jsonDoc::JsonDoc::setDataObject(const QString& objName, const QString& objValue)
{
	QJsonObject dataObj = _rootObj["data"].toObject();

	dataObj[objName] = objValue;

	_rootObj["data"] = dataObj;
}

void jsonDoc::JsonDoc::setDataObject(const QString& objName, const bool& objValue)
{
	QJsonObject dataObj = _rootObj["data"].toObject();

	dataObj[objName] = objValue;

	_rootObj["data"] = dataObj;
}

void jsonDoc::JsonDoc::setDataObject(const QString& objName, const int& objValue)
{
	QJsonObject dataObj = _rootObj["data"].toObject();

	dataObj[objName] = objValue;

	_rootObj["data"] = dataObj;
}

void jsonDoc::JsonDoc::setDataObject(const QString& objName, const QJsonArray& objValue)
{
	QJsonObject dataObj = _rootObj["data"].toObject();

	dataObj[objName] = objValue;

	_rootObj["data"] = dataObj;
}

void jsonDoc::JsonDoc::setDataObject(const QString& objName, const QJsonObject& objValue)
{
	QJsonObject dataObj = _rootObj["data"].toObject();

	dataObj[objName] = objValue;

	_rootObj["data"] = dataObj;
}

QString jsonDoc::JsonDoc::getDataObjectStr(const QString& objName)
{
	QJsonObject dataObj = _rootObj["data"].toObject();

	return dataObj[objName].toString();
}

int jsonDoc::JsonDoc::getDataObjectInt(const QString& objName)
{
	QJsonObject dataObj = _rootObj["data"].toObject();
	return dataObj[objName].toInt();
}

bool jsonDoc::JsonDoc::getDataObjectBool(const QString& objName)
{
	QJsonObject dataObj = _rootObj["data"].toObject();

	return dataObj[objName].toBool();
}

QJsonArray jsonDoc::JsonDoc::getDataObjectArray(const QString& objName)
{
	QJsonObject dataObj = _rootObj["data"].toObject();

	return dataObj[objName].toArray();
}

QJsonObject jsonDoc::JsonDoc::getDataObjectJsonObj(const QString& objName)
{
	QJsonObject dataObj = _rootObj["data"].toObject();

	return dataObj[objName].toObject();
}


//Conn class
jsonDoc::Conn::Conn() : JsonDoc()
{
	_rootObj["action"] = "connection";
}

void jsonDoc::Conn::setConnId(const QString& connId)
{
	JsonDoc::setDataObject("connId", connId);
}

QString jsonDoc::Conn::getConnId()
{
	return JsonDoc::getDataObjectStr("connId");
}



//Account class
jsonDoc::Account::Account() : JsonDoc()
{
	_rootObj["action"] = "";
}

void jsonDoc::Account::setLogin()
{
	_rootObj["action"] = "login";
}

void jsonDoc::Account::setLogout()
{
	_rootObj["action"] = "logout";
}

void jsonDoc::Account::setNewaccount()
{
	_rootObj["action"] = "newAccount";
}

void jsonDoc::Account::setUsername(const QString& username)
{
	JsonDoc::setDataObject("username", username);
}

QString jsonDoc::Account::getUsername()
{
	return JsonDoc::getDataObjectStr("username");
}

void jsonDoc::Account::setPassword(const QString& password)
{
	QString passHash = hashData(password);
	JsonDoc::setDataObject("password", passHash);
}

QString jsonDoc::Account::getPassword()
{
	return JsonDoc::getDataObjectStr("password");
}

void jsonDoc::Account::setResult(const bool& result)
{
	JsonDoc::setDataObject("result", result);
}

bool jsonDoc::Account::getResult()
{
	return JsonDoc::getDataObjectBool("result");
}



//Ranking class
jsonDoc::Ranking::Ranking()
{
	_rootObj["action"] = "rankingUpdate";
}

void jsonDoc::Ranking::setRankning(const QJsonDocument& jsonDoc)
{
	QJsonArray rankingArr;
	QJsonArray jsonArr;
	int count = 0;

	foreach(const QJsonValue & value, jsonArr)
	{
		QJsonObject jsonObj = value.toObject();
		QJsonObject jsonObjStats = jsonObj["stats"].toObject();

		QJsonObject arrObj;

		arrObj["lp"] = ++count;
		arrObj["user"] = jsonObj["username"];
		arrObj["win"] = jsonObjStats["win"];
		arrObj["lost"] = jsonObjStats["lost"];

		rankingArr.append(arrObj);
	}

	_rootObj["data"] = rankingArr;
}

QJsonDocument jsonDoc::Ranking::getRanking()
{
	QJsonArray jsonArr = _rootObj["data"].toArray();

	QJsonDocument jsonDoc(jsonArr);

	return jsonDoc;
}



//Matchmaking class
jsonDoc::Matchmaking::Matchmaking() : JsonDoc()
{
	_rootObj["action"] = "";
}

void jsonDoc::Matchmaking::setJoin()
{
	_rootObj["action"] = "matchmakingJoin";
}

void jsonDoc::Matchmaking::setLeave()
{
	_rootObj["action"] = "matchmakingLeave";
}

void jsonDoc::Matchmaking::setUpdateInfo()
{
	_rootObj["action"] = "matchmakingUpdate";
}

void jsonDoc::Matchmaking::setConnId(const QString& connId)
{
	JsonDoc::setDataObject("connId", connId);
}

QString jsonDoc::Matchmaking::getConnId()
{
	return JsonDoc::getDataObjectStr("connId");
}

void jsonDoc::Matchmaking::setPlayerName(const QString& username)
{
	JsonDoc::setDataObject("username", username);
}

QString jsonDoc::Matchmaking::getPlayerName()
{
	return JsonDoc::getDataObjectStr("username");
}

void jsonDoc::Matchmaking::setPlayersInQueueCount(const int& count)
{
	JsonDoc::setDataObject("count", count);
}

int jsonDoc::Matchmaking::getPlayersInQueueCount()
{
	return JsonDoc::getDataObjectInt("count");
}



//Game class
jsonDoc::Game::Game() : JsonDoc()
{
	_rootObj["action"] = "game";
}

QJsonArray jsonDoc::Game::getGameField()
{
	return JsonDoc::getDataObjectArray("gameField");
}

void jsonDoc::Game::setGameField(const QJsonArray& gameField)
{
	JsonDoc::setDataObject("gameField", gameField);
}

int jsonDoc::Game::getRoundCount()
{
	return JsonDoc::getDataObjectInt("round");
}

bool jsonDoc::Game::checkGameTurn()
{
	return JsonDoc::getDataObjectBool("gameTurn");
}

QString jsonDoc::Game::getPlayerPawn()
{
	return JsonDoc::getDataObjectStr("pawn");
}

QString jsonDoc::Game::getWinner()
{
	return JsonDoc::getDataObjectStr("winner");
}
