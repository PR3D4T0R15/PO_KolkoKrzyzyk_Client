#pragma once

#include <QObject>
#include <QDebug>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTcpSocket>
#include "include/TcpClient.h"
#include "include/JsonDoc.h"

class ConnectionManager  : public QObject
{
	Q_OBJECT

public:
	ConnectionManager(QObject *parent = nullptr);
	~ConnectionManager();

	static bool getLoginStatus();
	static void setLoginStatus(const bool& status);

public slots:
	//odbierz dane z ui
	void sendDataFromQml(const QJsonDocument& jsonDoc);
private slots:
	//odbierz dane z serwera
	void receivedData(const QByteArray& data);

	//polaczono i odlaczono do serwera
	void stateChanged(const QAbstractSocket::SocketState& state);

signals:
	//polacz i odlacz
	void connect();
	void disconnect();

	//wyslij dane do serwera
	void sendData(QByteArray data);

	//wyslij dane do ui
	void sendDataToQml(const QJsonDocument& data);

	void socketConnStatus(const bool& status);

private:
	void setConnectionId(const QString& connId);
	QString getConnectionId();

	void setClientId(const QString& clientId);
	QString getClientId();

private:
	TcpClient* _client;
	QString _connectionId;
	QString _clientId;

	bool _connectionStatus;
	static bool _loginStatus;
};