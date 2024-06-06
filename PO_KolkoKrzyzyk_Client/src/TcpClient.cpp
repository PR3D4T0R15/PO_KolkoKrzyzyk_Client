#include "include/TcpClient.h"

TcpClient::TcpClient(QObject *parent): QObject(parent)
{
	_socket = new QTcpSocket(this);
}

TcpClient::~TcpClient()
{
	_socket->deleteLater();
}



void TcpClient::connect()
{   
	_socket->connectToHost("127.0.0.1", 4242);		

	if (_socket->waitForConnected(2000))
	{
		QObject::connect(_socket, &QAbstractSocket::readyRead, this, &TcpClient::receiveData);
		QObject::connect(_socket, &QAbstractSocket::connected, this, &TcpClient::connected);
		QObject::connect(_socket, &QAbstractSocket::disconnected, this, &TcpClient::disconnected);
	}
}

void TcpClient::disconnect()
{
	_socket->disconnectFromHost();
}

void TcpClient::sendData(const QByteArray& data)
{
	_socket->write(data);
}

void TcpClient::receiveData()
{
	QByteArray data = _socket->readAll();

	emit receivedData(data);
}
