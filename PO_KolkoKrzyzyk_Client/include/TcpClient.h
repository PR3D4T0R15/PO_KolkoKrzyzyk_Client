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
	//wyslij dane
	void sendData(const QByteArray& data);

private slots:
	//dane odebrane
	void receiveData();

signals:
	//polacz i odlacz
	void connect();
	void disconnect();

	//polaczono i odlaczono do serwera
	void connected();
	void disconnected();

	//odebrano dane
	void receivedData(const QByteArray& data);

private:
	QTcpSocket* _socket;
};
