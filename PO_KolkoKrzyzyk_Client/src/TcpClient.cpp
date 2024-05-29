#include "include/TcpClient.h"

TcpClient::TcpClient(QObject *parent): QObject(parent)
{
	_socket = new QTcpSocket(this);
}

TcpClient::~TcpClient()
{
	_socket->deleteLater();
}

void TcpClient::connect(QHostAddress address, quint8 port)
{
	_socket->connectToHost(address, port);

	QObject::connect(_socket, &QAbstractSocket::stateChanged, this, &TcpClient::onSocketStateChanged);
}

void TcpClient::disconnect()
{
	_socket->disconnectFromHost();
}

void TcpClient::sendData(const QByteArray& data)
{
}

void TcpClient::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
	switch (socketState)
	{
	case QAbstractSocket::UnconnectedState:
		qDebug() << "socket: UnconnectedState";
		break;
	case QAbstractSocket::HostLookupState:
		qDebug() << "socket: HostLookupState";
		break;
	case QAbstractSocket::ConnectingState:
		qDebug() << "socket: ConnectingState";
		break;
	case QAbstractSocket::ConnectedState:
		qDebug() << "socket: ConnectedState";
		break;
	case QAbstractSocket::BoundState:
		qDebug() << "socket: BoundState";
		break;
	case QAbstractSocket::ClosingState:
		qDebug() << "socket: ClosingState";
		break;
	case QAbstractSocket::ListeningState:
		qDebug() << "socket: ListeningState";
		break;
	}
}

void TcpClient::connected()
{
}

void TcpClient::disconected()
{
}
