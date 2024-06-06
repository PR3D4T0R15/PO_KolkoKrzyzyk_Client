#include "include/ConnectionManager.h"
//konstruktor
ConnectionManager::ConnectionManager(QObject *parent): QObject(parent)
{
	_client = new TcpClient;

	QObject::connect(this, &ConnectionManager::connect, _client, &TcpClient::connect);
	QObject::connect(this, &ConnectionManager::disconnect, _client, &TcpClient::disconnect);
	QObject::connect(_client, &TcpClient::connected, this, &ConnectionManager::connected);
	QObject::connect(_client, &TcpClient::disconnected, this, &ConnectionManager::disconnected);
	QObject::connect(this, &ConnectionManager::sendData, _client, &TcpClient::sendData);
	QObject::connect(_client, &TcpClient::receivedData, this, &ConnectionManager::receivedData);
}

//destruktor
ConnectionManager::~ConnectionManager()
{
	_client->disconnect();
	_client->deleteLater();
}



void ConnectionManager::receivedData(const QByteArray& data)
{
	//TODO received data process
	qDebug() << data;
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

void ConnectionManager::connected()
{
}

void ConnectionManager::disconnected()
{
}
