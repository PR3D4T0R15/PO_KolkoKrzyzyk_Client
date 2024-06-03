#include "include/ConnectionManager.h"

ConnectionManager::ConnectionManager(QObject *parent): QObject(parent)
{
	_client = new TcpClient;

	QObject::connect(_client, &TcpClient::connectionOk, this, &ConnectionManager::connectionOk);
	QObject::connect(_client, &TcpClient::connectionNotOk, this, &ConnectionManager::connectionNotOk);
	QObject::connect(this, &ConnectionManager::connect, _client, &TcpClient::connect);
	QObject::connect(_client, &TcpClient::receivedData, this, &ConnectionManager::receivedData);
	QObject::connect(this, &ConnectionManager::sendData, _client, &TcpClient::sendData);
}

ConnectionManager::~ConnectionManager()
{
	_client->disconnect();
	_client->deleteLater();
}

void ConnectionManager::newAccountCredReceived(const QString& username, const QString& pass)
{
	QJsonDocument jsonDoc = jsonDoc::AccountDoc::newAccount(username, pass);
	QByteArray jsonByte = jsonDoc::JsonDoc::toBytes(jsonDoc);

	emit sendData(jsonByte);
}

void ConnectionManager::loginCredReceived(QString username, QString pass)
{
	QJsonDocument jsonDoc = jsonDoc::AccountDoc::logIn(username, pass);
	QByteArray jsonByte = jsonDoc::JsonDoc::toBytes(jsonDoc);

	emit sendData(jsonByte);
}

void ConnectionManager::receivedData(const QByteArray& data)
{
	QJsonDocument jsonDoc = jsonDoc::JsonDoc::toJson(data);

	QString action = jsonDoc::JsonDoc::getAction(jsonDoc);

	if (action == "rankingUpdate")
	{
		QJsonArray data = jsonDoc::JsonDoc::getData(jsonDoc);
		emit updatePlayerRanking(data);
	}
}

void ConnectionManager::setConnectionId(const QString& connId)
{
	_connectionId = connId;
}
QString ConnectionManager::getConnectionId()
{
	return _connectionId;
}

void ConnectionManager::setClientId(const QString& clientId)
{
	_clientId = clientId;
}
QString ConnectionManager::getClientId()
{
	return _clientId;
}