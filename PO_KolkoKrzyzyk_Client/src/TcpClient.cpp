#include "include/TcpClient.h"

TcpClient::TcpClient(QObject *parent): QObject(parent)
{
	_socket = new QTcpSocket(this);
}

TcpClient::~TcpClient()
{
	_socket->deleteLater();
}

bool TcpClient::getState()
{
	QAbstractSocket::SocketState state = _socket->state();

	if (state == QAbstractSocket::ConnectedState)
	{
		return true;
	}
	return false;
}


void TcpClient::connect()
{   
	_socket->connectToHost("192.168.244.131", 2390);		

	if (_socket->waitForConnected(1))
	{
		QObject::connect(_socket, &QAbstractSocket::readyRead, this, &TcpClient::receiveData);
		QObject::connect(_socket, &QAbstractSocket::stateChanged, this, &TcpClient::stateChanged);
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
