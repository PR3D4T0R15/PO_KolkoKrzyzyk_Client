#pragma once

#include <QObject>
#include "include/JsonDoc.h"

class MatchmakingViewControl : public QObject
{
	Q_OBJECT
	Q_PROPERTY(int playersInQueue READ getPlayersInQueue WRITE setPlayersInQueue NOTIFY playersInQueueChanged)

public:
	MatchmakingViewControl(QObject *parent = nullptr);
	~MatchmakingViewControl();

	//Q_PROPERTY
	void setPlayersInQueue(const int& count);
	int getPlayersInQueue();

public slots:
	void exitMatchmakingButtonClicked();
	void joinMatchmaking();
	void leaveMatchmaking();
	//odbierz dane z serwera
	void receiveData(const QJsonDocument& data);

private slots:

signals:
	void changeView(QString view);
	void playersInQueueChanged();

	//wyslij dane do sewera
	void sendData(const QJsonDocument& data);

private:
	int _playersInQueue;
};
