#include "include/HomeViewControl.h"
#include "include/JsonDoc.h"
//konstruktor
HomeViewControl::HomeViewControl(QObject *parent): QObject(parent)
{
	_rankingUpdateTimer = new QTimer(this);
	QObject::connect(_rankingUpdateTimer, &QTimer::timeout, this, &HomeViewControl::queryPlayerRanking);
	_rankingUpdateTimer->start(60000);
}

//destruktor
HomeViewControl::~HomeViewControl()
{
}



//QPROPERTY login
void HomeViewControl::setLogin(const QString& login)
{
	_login = login;
	emit loginChanged();
}

QString HomeViewControl::getLogin()
{
	return _login;
}




//QPROPERTY password
void HomeViewControl::setPassword(const QString& password)
{
	_password = password;
	emit passwordChanged();
}

QString HomeViewControl::getPassword()
{
	return _password;
}



//QPROPERTY playerRanking
void HomeViewControl::setPlayerRanking(const QJsonArray& playerRanking)
{
	_playerRanking = playerRanking;
	emit playerRankingChanged();
}

QJsonArray HomeViewControl::getPlayerRanking()
{
	return _playerRanking;
}



//QPROPERTY loginInfoString
void HomeViewControl::setLoginInfoString(const QString& infoString)
{
	_loginInfoString = infoString;
	emit loginInfoStringChanged();
}

QString HomeViewControl::getLoginInfoString()
{
	return _loginInfoString;
}


//przyciski
void HomeViewControl::newAccountButtonClicked()
{
	emit changeState("newAccount");
}

void HomeViewControl::createNewAccountButtonClicked()
{
	jsonDoc::Account accountJson;
	accountJson.setNewaccount();
	accountJson.setUsername(_login);
	accountJson.setPassword(_password);

	emit sendData(accountJson.getJsonDoc());
}

void HomeViewControl::goToLoginButtonClicked()
{
	emit changeState("loginAccount");
}

void HomeViewControl::logInButtonClicked()
{
	jsonDoc::Account accountJson;
	accountJson.setLogin();
	accountJson.setUsername(_login);
	accountJson.setPassword(_password);

	emit sendData(accountJson.getJsonDoc());
}

void HomeViewControl::playButtonClicked()
{
	emit changeView("MatchmakingView");
}

void HomeViewControl::logOutButtonClicked()
{
	_login = "";
	_password = "";

	emit changeState("loginAccount");
}

void HomeViewControl::exitButtonClicked()
{
	emit changeView("StartView");
}


//odbieranie danych
void HomeViewControl::receiveData(const QJsonDocument& data)
{
	QString action = jsonDoc::JsonDoc::getAction(data);

	if (action == "rankingUpdate")
	{
		jsonDoc::Ranking rankingJson;
		rankingJson.setJson(data);
		QJsonDocument rankingArr = rankingJson.getRanking();

		emit setPlayerRanking(rankingArr.array());
	}
	if (action == "login")
	{
		jsonDoc::Account accountJson;
		accountJson.setJson(data);

		if (accountJson.getResult())
		{
			emit changeState("home");
			ConnectionManager::setLoginStatus(true);
		}
		else
		{
			setLoginInfoString(QString::fromUtf8("Nieprawidłowa nazwa użytkownika lub hasło"));
			ConnectionManager::setLoginStatus(false);
		}
		
	}
}


//wysylanie zapytania o ranking
void HomeViewControl::queryPlayerRanking()
{
	jsonDoc::Ranking ranking;
	emit sendData(ranking.getJsonDoc());
}

void HomeViewControl::windowReady()
{
	if (ConnectionManager::getLoginStatus())
	{
		emit changeState("home");
	}
	else
	{
		emit changeState("loginAccount");
	}
}
