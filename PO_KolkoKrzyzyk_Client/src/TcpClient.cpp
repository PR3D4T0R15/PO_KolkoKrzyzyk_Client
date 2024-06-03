#include "include/TcpClient.h"


// definicja klasy TcpClient, która jest klientem TCP w aplikacji Qt.
TcpClient::TcpClient(QObject *parent): QObject(parent)
{
	_socket = new QTcpSocket(this);				// Tworzenie obiektu QTcpSocket i przypisanie go do zmiennej _socket
}

// Destruktor klasy TcpClient (zwolnienie pamiêci)
TcpClient::~TcpClient()
{
	_socket->deleteLater();						// Planuje usuniêcie obiektu _socket z pamiêci w bezpieczny sposób
}



// Metoda connect() klasy TcpClient, odpowiedzialna za nawi¹zywanie po³¹czenia z serwerem
void TcpClient::connect()
{   
	// Nawi¹zanie po³¹czenia z serwerem o podanym adresie IP(127.0.0.1) i numerze portu(4242)
	_socket->connectToHost("127.0.0.1", 4242);		
    
	// Sprawdzenie, czy uda³o siê nawi¹zaæ po³¹czenie w ci¹gu 2000 milisekund
	if (_socket->waitForConnected(2000))
	{
		// Po³¹czenie sygna³u readyRead obiektu _socket z metod¹ receiveData klasy TcpClient
		QObject::connect(_socket, &QAbstractSocket::readyRead, this, &TcpClient::receiveData);

		// Emitowanie sygna³u connectionOk(), informuj¹cego o powodzeniu nawi¹zania po³¹czenia
		emit connectionOk();
	}
	else
	{
		// Emitowanie sygna³u connectionNotOk(), informuj¹cego o niepowodzeniu nawi¹zania po³¹czenia
		emit connectionNotOk();
	}
}




// Metoda disconnect() klasy TcpClient, odpowiedzialna za roz³¹czanie z serwerem
void TcpClient::disconnect()
{
	_socket->disconnectFromHost();			// Roz³¹czenie z serwerem
}




// Metoda sendData() klasy TcpClient, s³u¿¹ca do wysy³ania danych do serwera
void TcpClient::sendData(QByteArray data)
{
	_socket->write(data);					// Zapisanie danych do gniazda (_socket) i ich wys³anie
}




// Metoda receiveData() klasy TcpClient, wywo³ywana przy otrzymaniu danych od serwera
void TcpClient::receiveData()
{
	// Odczytanie wszystkich dostêpnych danych z gniazda (_socket)
	QByteArray data = _socket->readAll();

	// Emitowanie sygna³u receivedData() z otrzymanymi danymi jako argumentem
	emit receivedData(data);
}
