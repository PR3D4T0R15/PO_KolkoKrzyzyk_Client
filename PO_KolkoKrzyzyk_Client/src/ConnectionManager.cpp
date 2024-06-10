#include "include/ConnectionManager.h"
//konstruktor
ConnectionManager::ConnectionManager(QObject *parent): QObject(parent)
{
	_client = new TcpClient;

	QObject::connect(this, &ConnectionManager::connect, _client, &TcpClient::connect);
	QObject::connect(this, &ConnectionManager::disconnect, _client, &TcpClient::disconnect);
	QObject::connect(_client, &TcpClient::stateChanged, this, &ConnectionManager::stateChanged);
	QObject::connect(this, &ConnectionManager::sendData, _client, &TcpClient::sendData);
	QObject::connect(_client, &TcpClient::receivedData, this, &ConnectionManager::receivedData);

	_connectionId = "";
	_clientId = "";

	connect();
}

//destruktor
ConnectionManager::~ConnectionManager()
{
	_client->disconnect();
	_client->deleteLater();
}

void ConnectionManager::sendDataFromQml(const QJsonDocument& jsonDoc)
{
	QString action = jsonDoc::JsonDoc::getAction(jsonDoc);
	QByteArray data;

	data = jsonDoc::JsonDoc::toBytes(jsonDoc);

	if (action.contains("matchmaking"))
	{
		jsonDoc::Matchmaking matchmakingJson;
		matchmakingJson.setJson(jsonDoc);
		matchmakingJson.setConnId(_connectionId);
		matchmakingJson.setPlayerName(_clientId);
		data = jsonDoc::JsonDoc::toBytes(matchmakingJson.getJsonDoc());
	}

	emit sendData(data);
}


void ConnectionManager::receivedData(const QByteArray& data)
{
	//TODO received data process
	QJsonDocument requestJsonDoc = jsonDoc::JsonDoc::toJson(data);
	QString action = jsonDoc::JsonDoc::getAction(requestJsonDoc);

	if (action == "connection")
	{
		jsonDoc::Conn conn;
		conn.setJson(requestJsonDoc);

		QString connId = conn.getConnId();
		setConnectionId(connId);
	}
	if (action == "login")
	{
		jsonDoc::Account accountJson;
		accountJson.setJson(requestJsonDoc);
		QString username = accountJson.getUsername();

		setClientId(username);

	}

	emit sendDataToQml(requestJsonDoc);
}

void ConnectionManager::stateChanged(const QAbstractSocket::SocketState& state)
{
	if (state == QAbstractSocket::ConnectedState)
	{
		emit socketConnStatus(true);
	}
	if (state == QAbstractSocket::UnconnectedState)
	{
		emit socketConnStatus(false);
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