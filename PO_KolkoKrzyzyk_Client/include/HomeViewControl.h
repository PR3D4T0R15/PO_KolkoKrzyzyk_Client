#pragma once

#include <QObject>
#include <QTimer>
#include <QJsonArray>
#include "include/ConnectionManager.h"

class HomeViewControl : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString login READ getLogin WRITE setLogin NOTIFY loginChanged)
	Q_PROPERTY(QString password READ getPassword WRITE setPassword NOTIFY passwordChanged)
	Q_PROPERTY(QJsonArray playerRanking READ getPlayerRanking WRITE setPlayerRanking NOTIFY playerRankingChanged)
	Q_PROPERTY(QString loginInfoString READ getLoginInfoString WRITE setLoginInfoString NOTIFY loginInfoStringChanged)

public:
	HomeViewControl(QObject *parent = nullptr);
	~HomeViewControl();

	//Q_PROPERTY
	void setLogin(const QString& login);
	QString getLogin();
	void setPassword(const QString& password);
	QString getPassword();
	void setPlayerRanking(const QJsonArray& playerRanking);
	QJsonArray getPlayerRanking();
	void setLoginInfoString(const QString& infoString);
	QString getLoginInfoString();

public slots:
	//kontrola przyciskow
	void newAccountButtonClicked();
	void createNewAccountButtonClicked();
	void goToLoginButtonClicked();
	void logInButtonClicked();
	void playButtonClicked();
	void logOutButtonClicked();
	void exitButtonClicked();

	//odbierz dane z serwera
	void receiveData(const QJsonDocument& data);

	//wyslij zapytanie o ranking 
	void queryPlayerRanking();

	//zaladowane okno
	void windowReady();

private slots:

signals:
	//zmien stan ui
	void changeView(QString view);
	void changeState(QString stateStr);

	//Q_PROPERTY
	void loginChanged();
	void passwordChanged();
	void playerRankingChanged();
	void loginInfoStringChanged();

	//wyslij dane do sewera
	void sendData(const QJsonDocument& data);

private:
	QString _login;
	QString _password;
	QJsonArray _playerRanking;
	QString _loginInfoString;

	QTimer* _rankingUpdateTimer;
};