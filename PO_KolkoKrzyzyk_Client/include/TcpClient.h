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
	void connect(QHostAddress address, quint8 port);
	void disconnect();
	void sendData(const QByteArray& data);

private slots:
	void onSocketStateChanged(QAbstractSocket::SocketState socketState);
	void connected();
	void disconected();

signals:
	void dataReceived(const QByteArray& data);


private:
	QTcpSocket* _socket;
};
