#include "include/TcpClient.h"


// definicja klasy TcpClient, kt�ra jest klientem TCP w aplikacji Qt.
TcpClient::TcpClient(QObject *parent): QObject(parent)
{
	_socket = new QTcpSocket(this);				// Tworzenie obiektu QTcpSocket i przypisanie go do zmiennej _socket
}

// Destruktor klasy TcpClient (zwolnienie pami�ci)
TcpClient::~TcpClient()
{
	_socket->deleteLater();						// Planuje usuni�cie obiektu _socket z pami�ci w bezpieczny spos�b
}



// Metoda connect() klasy TcpClient, odpowiedzialna za nawi�zywanie po��czenia z serwerem
void TcpClient::connect()
{   
	// Nawi�zanie po��czenia z serwerem o podanym adresie IP(127.0.0.1) i numerze portu(4242)
	_socket->connectToHost("127.0.0.1", 4242);		
    
	// Sprawdzenie, czy uda�o si� nawi�za� po��czenie w ci�gu 2000 milisekund
	if (_socket->waitForConnected(2000))
	{
		// Po��czenie sygna�u readyRead obiektu _socket z metod� receiveData klasy TcpClient
		QObject::connect(_socket, &QAbstractSocket::readyRead, this, &TcpClient::receiveData);

		// Emitowanie sygna�u connectionOk(), informuj�cego o powodzeniu nawi�zania po��czenia
		emit connectionOk();
	}
	else
	{
		// Emitowanie sygna�u connectionNotOk(), informuj�cego o niepowodzeniu nawi�zania po��czenia
		emit connectionNotOk();
	}
}




// Metoda disconnect() klasy TcpClient, odpowiedzialna za roz��czanie z serwerem
void TcpClient::disconnect()
{
	_socket->disconnectFromHost();			// Roz��czenie z serwerem
}




// Metoda sendData() klasy TcpClient, s�u��ca do wysy�ania danych do serwera
void TcpClient::sendData(QByteArray data)
{
	_socket->write(data);					// Zapisanie danych do gniazda (_socket) i ich wys�anie
}




// Metoda receiveData() klasy TcpClient, wywo�ywana przy otrzymaniu danych od serwera
void TcpClient::receiveData()
{
	// Odczytanie wszystkich dost�pnych danych z gniazda (_socket)
	QByteArray data = _socket->readAll();

	// Emitowanie sygna�u receivedData() z otrzymanymi danymi jako argumentem
	emit receivedData(data);
}
