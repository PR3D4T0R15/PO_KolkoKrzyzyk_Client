#include "include/GameViewControl.h"

#include <QJsonDocument>

GameViewControl::GameViewControl()
{
	_counterTimer = new QTimer();
	_counterTimer->setInterval(1000);
	_counterTimer->stop();
	QObject::connect(_counterTimer, &QTimer::timeout, this, &GameViewControl::timerShot);
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
}

void GameViewControl::buttonA2Clicked()
{
	qDebug() << "Button A2";
	
}

void GameViewControl::buttonA3Clicked()
{
	qDebug() << "Button A3";
}

void GameViewControl::buttonB1Clicked()
{
	qDebug() << "Button B1";
}

void GameViewControl::buttonB2Clicked()
{
	qDebug() << "Button B2";
}

void GameViewControl::buttonB3Clicked()
{
	qDebug() << "Button B3";
}

void GameViewControl::buttonC1Clicked()
{
	qDebug() << "Button C1";
}

void GameViewControl::buttonC2Clicked()
{
	qDebug() << "Button C2";
}

void GameViewControl::buttonC3Clicked()
{
	qDebug() << "Button C3";
}

void GameViewControl::gameLeaveButton()
{
	qDebug() << "Exit";
}

void GameViewControl::uiReady()
{
}

void GameViewControl::receiveData(const QJsonDocument& data)
{
	
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
		emit timerStart();
	}
	setCountdown(QString::number(_counter));
}
