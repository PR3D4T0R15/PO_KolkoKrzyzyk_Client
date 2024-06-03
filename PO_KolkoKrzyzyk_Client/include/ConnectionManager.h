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
	void newAccountCredReceived(const QString& username, const QString& pass);
	void loginCredReceived(QString username, QString pass);

private slots:
	void receivedData(const QByteArray& data);

signals:
	void connect();

	void connectionOk();
	void connectionNotOk();

	void sendData(QByteArray data);

	void updatePlayerRanking(const QJsonArray& data);

private:
	void setConnectionId(const QString& connId);
	QString getConnectionId();

	void setClientId(const QString& clientId);
	QString getClientId();


private:
	TcpClient* _client;
	QString _connectionId;
	QString _clientId;
};