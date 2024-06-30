#include "include/GameViewControl.h"

GameViewControl::GameViewControl()
{
	_counterTimer = new QTimer();
	_counterTimer->setInterval(1000);
	_counterTimer->stop();
	QObject::connect(_counterTimer, &QTimer::timeout, this, &GameViewControl::timerShot);

	_playerPawn = "";
	_counter = 15;
}

GameViewControl::~GameViewControl()
{
	_counterTimer->deleteLater();
}



//Q_PROPERTY
void GameViewControl::setButtonA1(const QString& state)
{
	_buttonA1state = state;
	emit buttonA1Changed();
}

QString GameViewControl::getButtonA1()
{
	return _buttonA1state;
}

void GameViewControl::setButtonA2(const QString& state)
{
	_buttonA2state = state;
	emit buttonA2Changed();
}

QString GameViewControl::getButtonA2()
{
	return _buttonA2state;
}

void GameViewControl::setButtonA3(const QString& state)
{
	_buttonA3state = state;
	emit buttonA3Changed();
}

QString GameViewControl::getButtonA3()
{
	return _buttonA3state;
}

void GameViewControl::setButtonB1(const QString& state)
{
	_buttonB1state = state;
	emit buttonB1Changed();
}

QString GameViewControl::getButtonB1()
{
	return _buttonB1state;
}

void GameViewControl::setButtonB2(const QString& state)
{
	_buttonB2state = state;
	emit buttonB2Changed();
}

QString GameViewControl::getButtonB2()
{
	return _buttonB2state;
}

void GameViewControl::setButtonB3(const QString& state)
{
	_buttonB3state = state;
	emit buttonB3Changed();
}

QString GameViewControl::getButtonB3()
{
	return _buttonB3state;
}

void GameViewControl::setButtonC1(const QString& state)
{
	_buttonC1state = state;
	emit buttonC1Changed();
}

QString GameViewControl::getButtonC1()
{
	return _buttonC1state;
}

void GameViewControl::setButtonC2(const QString& state)
{
	_buttonC2state = state;
	emit buttonC2Changed();
}

QString GameViewControl::getButtonC2()
{
	return _buttonC2state;
}

void GameViewControl::setButtonC3(const QString& state)
{
	_buttonC3state = state;
	emit buttonC3Changed();
}

QString GameViewControl::getButtonC3()
{
	return _buttonC3state;
}

void GameViewControl::setRoundTitle(const QString& title)
{
	_roundTitle = title;
	emit roundTitleChanged();
}

QString GameViewControl::getRoundTitle()
{
	return _roundTitle;
}

void GameViewControl::setRoundIco(const QString& ico)
{
	_roundIco = ico;
	emit roundIcoChanged();
}

QString GameViewControl::getRoundIco()
{
	return _roundIco;
}

void GameViewControl::setCountdown(const QString& countdown)
{
	_countdown = countdown;
	emit countdownChanged();
}

QString GameViewControl::getCountdown()
{
	return _countdown;
}



//GameControl clicked
void GameViewControl::buttonA1Clicked()
{
	qDebug() << "Button A1";
	updateGameFieldPawn(0,0);
	setButtonA1(setGameControlState(_playerPawn));
	sendReply();
}

void GameViewControl::buttonA2Clicked()
{
	qDebug() << "Button A2";
	updateGameFieldPawn(0, 1);
	setButtonA2(setGameControlState(_playerPawn));
	sendReply();
}

void GameViewControl::buttonA3Clicked()
{
	qDebug() << "Button A3";
	updateGameFieldPawn(0, 2);
	setButtonA3(setGameControlState(_playerPawn));
	sendReply();
}

void GameViewControl::buttonB1Clicked()
{
	qDebug() << "Button B1";
	updateGameFieldPawn(1, 0);
	setButtonB1(setGameControlState(_playerPawn));
	sendReply();
}

void GameViewControl::buttonB2Clicked()
{
	qDebug() << "Button B2";
	updateGameFieldPawn(1, 1);
	setButtonB2(setGameControlState(_playerPawn));
	sendReply();
}

void GameViewControl::buttonB3Clicked()
{
	qDebug() << "Button B3";
	updateGameFieldPawn(1, 2);
	setButtonB3(setGameControlState(_playerPawn));
	sendReply();
}

void GameViewControl::buttonC1Clicked()
{
	qDebug() << "Button C1";
	updateGameFieldPawn(2, 0);
	setButtonC1(setGameControlState(_playerPawn));
	sendReply();
}

void GameViewControl::buttonC2Clicked()
{
	qDebug() << "Button C2";
	updateGameFieldPawn(2, 1);
	setButtonC2(setGameControlState(_playerPawn));
	sendReply();
}

void GameViewControl::buttonC3Clicked()
{
	qDebug() << "Button C3";
	updateGameFieldPawn(2, 2);
	setButtonC3(setGameControlState(_playerPawn));
	sendReply();
}

void GameViewControl::gameLeaveButton()
{
	qDebug() << "Exit";
	changeView("HomeView");
}

void GameViewControl::uiReady()
{
}

void GameViewControl::receiveData(const QJsonDocument& data)
{
	QString action = jsonDoc::JsonDoc::getAction(data);
	_gameData.setJson(data);

	if (action == "gameInit")
	{
		_playerPawn = _gameData.getPlayerPawn();
	}

	if (!_gameData.getWinner().isEmpty())
	{
		QString winner = _gameData.getWinner();

		if (winner == "n")
		{
			EndGameViewControl::setStatus("draw");
		}
		if (winner == _playerPawn)
		{
			EndGameViewControl::setStatus("win");
		}
		EndGameViewControl::setStatus("lost");

		changeView("EndGameView");
	}

	_gameField = _gameData.getGameField();
	_playerTurn = _gameData.checkGameTurn();
	timerStart();
	setGameInfo();
	setGameField(_gameData.getGameField());
}

void GameViewControl::timerStart()
{
	_counterTimer->start();
}

void GameViewControl::timerStop()
{
	_counterTimer->stop();
}

void GameViewControl::timerShot()
{
	if (_counter > 0)
	{
		_counter--;
	}
	else
	{
		_counter = 15;
		timerStop();
	}
	setCountdown(QString::number(_counter));
}

void GameViewControl::setGameField(const QJsonArray& gameField)
{
	if (gameField.isEmpty())
	{
		return;
	}

	setButtonA1(setGameControlState(gameField[0].toArray()[0].toString()));
	setButtonA2(setGameControlState(gameField[0].toArray()[1].toString()));
	setButtonA3(setGameControlState(gameField[0].toArray()[2].toString()));
	setButtonB1(setGameControlState(gameField[1].toArray()[0].toString()));
	setButtonB2(setGameControlState(gameField[1].toArray()[1].toString()));
	setButtonB3(setGameControlState(gameField[1].toArray()[2].toString()));
	setButtonC1(setGameControlState(gameField[2].toArray()[0].toString()));
	setButtonC2(setGameControlState(gameField[2].toArray()[1].toString()));
	setButtonC3(setGameControlState(gameField[2].toArray()[2].toString()));
}

QString GameViewControl::setGameControlState(const QString& state)
{
	//state n x o
	if (state == "n")
	{
		if (!_playerTurn)
		{
			return QString("wait");
		}

		if (_playerPawn == "x")
		{
			return QString("cross") + QString("_notSet");
		}
		else
		{
			return QString("circle") + QString("_notSet");
		}
	}
	if (state == "x")
	{
		return "cross_set";
	}
	if (state == "o")
	{
		return "circle_set";
	}

	return "default";
}

void GameViewControl::setGameInfo()
{
	if (_playerTurn)
	{
		if (_playerPawn == "x")
		{
			setRoundIco("../images/x.png");
		}
		else
		{
			setRoundIco("../images/o.png");
		}
		setRoundTitle("Twoja \n kolej!");
	}
	else
	{
		
		if (_playerPawn == "x")
		{
			setRoundIco("../images/o.png");
		}
		else
		{
			setRoundIco("../images/x.png");
		}
		setRoundTitle("Ruch \n przeciwnika!");
	}

}

void GameViewControl::updateGameFieldPawn(int row, int column)
{
	QJsonArray rowArray = _gameField[row].toArray();

	if (_playerPawn == "x")
	{
		rowArray[column] = "x";
	}
	else
	{
		rowArray[column] = "o";
	}

	_gameField[row] = rowArray;

	QJsonDocument jsonDoc(_gameField);
	qDebug() << jsonDoc.toJson(QJsonDocument::Compact);
}

void GameViewControl::sendReply()
{
	_gameData.setGameField(_gameField);
	_gameData.setAction("game");
	sendData(_gameData.getJsonDoc());
}
