#include "include/ConnectionManager.h"
//konstruktor
ConnectionManager::ConnectionManager(QObject *parent): QObject(parent)
{
	_client = new TcpClient;

	QObject::connect(this, &ConnectionManager::connect, _client, &TcpClient::connect);
	QObject::connect(this, &ConnectionManager::disconnect, _client, &TcpClient::disconnect);
	QObject::connect(this, &ConnectionManager::connected, _client, &TcpClient::connected);
	QObject::connect(this, &ConnectionManager::disconnected, _client, &TcpClient::disconnected);
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