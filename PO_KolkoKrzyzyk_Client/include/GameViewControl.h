#pragma once

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include "include/JsonDoc.h"
#include "include/ConnectionManager.h"

class GameViewControl : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString buttonA1state READ getButtonA1 WRITE setButtonA1 NOTIFY buttonA1Changed)
	Q_PROPERTY(QString buttonA2state READ getButtonA2 WRITE setButtonA2 NOTIFY buttonA2Changed)
	Q_PROPERTY(QString buttonA3state READ getButtonA3 WRITE setButtonA3 NOTIFY buttonA3Changed)

	Q_PROPERTY(QString buttonB1state READ getButtonB1 WRITE setButtonB1 NOTIFY buttonB1Changed)
	Q_PROPERTY(QString buttonB2state READ getButtonB2 WRITE setButtonB2 NOTIFY buttonB2Changed)
	Q_PROPERTY(QString buttonB3state READ getButtonB3 WRITE setButtonB3 NOTIFY buttonB3Changed)

	Q_PROPERTY(QString buttonC1state READ getButtonC1 WRITE setButtonC1 NOTIFY buttonC1Changed)
	Q_PROPERTY(QString buttonC2state READ getButtonC2 WRITE setButtonC2 NOTIFY buttonC2Changed)
	Q_PROPERTY(QString buttonC3state READ getButtonC3 WRITE setButtonC3 NOTIFY buttonC3Changed)

	Q_PROPERTY(QString roundTitle READ getRoundTitle WRITE setRoundTitle NOTIFY roundTitleChanged)
	Q_PROPERTY(QString roundIco READ getRoundIco WRITE setRoundIco NOTIFY roundIcoChanged)
	Q_PROPERTY(QString countdown READ getCountdown WRITE setCountdown NOTIFY countdownChanged)

public:
	GameViewControl();
	~GameViewControl();

public slots:
	//Q_PROPERTY
	void setButtonA1(const QString& state);
	QString getButtonA1();
	void setButtonA2(const QString& state);
	QString getButtonA2();
	void setButtonA3(const QString& state);
	QString getButtonA3();
	void setButtonB1(const QString& state);
	QString getButtonB1();
	void setButtonB2(const QString& state);
	QString getButtonB2();
	void setButtonB3(const QString& state);
	QString getButtonB3();
	void setButtonC1(const QString& state);
	QString getButtonC1();
	void setButtonC2(const QString& state);
	QString getButtonC2();
	void setButtonC3(const QString& state);
	QString getButtonC3();

	void setRoundTitle(const QString& title);
	QString getRoundTitle();
	void setRoundIco(const QString& ico);
	QString getRoundIco();
	void setCountdown(const QString& countdown);
	QString getCountdown();

	//GameControls clicked
	void buttonA1Clicked();
	void buttonA2Clicked();
	void buttonA3Clicked();
	void buttonB1Clicked();
	void buttonB2Clicked();
	void buttonB3Clicked();
	void buttonC1Clicked();
	void buttonC2Clicked();
	void buttonC3Clicked();

	//leave button
	void gameLeaveButton();

	//ui loaded
	void uiReady();

	//odbierz dane z serwera
	void receiveData(const QJsonDocument& data);

private slots:
	void timerStart();
	void timerStop();
	void timerShot();

signals:
	//Q_PROPERTY
	void buttonA1Changed();
	void buttonA2Changed();
	void buttonA3Changed();
	void buttonB1Changed();
	void buttonB2Changed();
	void buttonB3Changed();
	void buttonC1Changed();
	void buttonC2Changed();
	void buttonC3Changed();

	void roundTitleChanged();
	void roundIcoChanged();
	void countdownChanged();

	void changeView(QString view);

	//wyslij dane do sewera
	void sendData(const QJsonDocument& data);

private:
	void setGameField(const QJsonArray& gameField);
	QString setGameControlState(const QString& state);
	void setGameInfo();

	void updateGameFieldPawn(int row, int column);
	void sendReply();

private:
	//Q_PROPERTY
	QString _buttonA1state;
	QString _buttonA2state;
	QString _buttonA3state;
	QString _buttonB1state;
	QString _buttonB2state;
	QString _buttonB3state;
	QString _buttonC1state;
	QString _buttonC2state;
	QString _buttonC3state;
	QString _roundTitle;
	QString _roundIco;
	QString _countdown;

	QTimer* _counterTimer;
	int _counter;

	QString _playerPawn;
	QJsonArray _gameField;
	bool _playerTurn;
	jsonDoc::Game _gameData;
};
