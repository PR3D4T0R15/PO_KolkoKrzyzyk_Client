#pragma once

#include <QObject>
#include <QTcpSocket>
#include <QByteArray>
#include <Qdebug>

class TcpClient : public QObject
{
	Q_OBJECT

public:
	TcpClient(QObject *parent = nullptr);
	~TcpClient();

public slots:
	void connect();
	void disconnect();

	void sendData(QByteArray data);

private slots:
	void receiveData();

signals:
	void receivedData(const QByteArray& data);

	void connectionOk();
	void connectionNotOk();


private:
	QTcpSocket* _socket;
};
