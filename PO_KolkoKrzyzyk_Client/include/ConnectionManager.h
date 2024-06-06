#pragma once

#include <QObject>
#include <QDebug>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonArray>
#include "include/TcpClient.h"
#include "include/JsonDoc.h"

class ConnectionManager  : public QObject
{
	Q_OBJECT

public:
	ConnectionManager(QObject *parent = nullptr);
	~ConnectionManager();

public slots:

private slots:
	void receivedData(const QByteArray& data);

	//polaczono i odlaczono do serwera
	void connected();
	void disconnected();

signals:
	//polacz i odlacz
	void connect();
	void disconnect();

	void sendData(QByteArray data);

private:
	void setConnectionId(const QString& connId);
	QString getConnectionId();

	void setClientId(const QString& clientId);
	QString getClientId();

private:
	TcpClient* _client;
	QString _connectionId;
	QString _clientId;
	bool _connStatus;
};