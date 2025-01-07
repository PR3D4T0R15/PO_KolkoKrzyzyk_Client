#include "include/MatchmakingViewControl.h"

//kontruktor
MatchmakingViewControl::MatchmakingViewControl(QObject *parent): QObject(parent)
{
	_playersInQueue = 0;
}

//destruktor
MatchmakingViewControl::~MatchmakingViewControl()
{

}



//QPROPERTY playersInQueue
void MatchmakingViewControl::setPlayersInQueue(const int& count)
{
	_playersInQueue = count;
	emit playersInQueueChanged();
}

int MatchmakingViewControl::getPlayersInQueue()
{
	return _playersInQueue;
}

void MatchmakingViewControl::exitMatchmakingButtonClicked()
{
	leaveMatchmaking();
	emit changeView("HomeView");
}

void MatchmakingViewControl::joinMatchmaking()
{
	jsonDoc::Matchmaking matchmakingJson;
	matchmakingJson.setJoin();

	emit sendData(matchmakingJson.getJsonDoc());
}

void MatchmakingViewControl::leaveMatchmaking()
{
	jsonDoc::Matchmaking matchmakingJson;
	matchmakingJson.setLeave();

	emit sendData(matchmakingJson.getJsonDoc());
}

void MatchmakingViewControl::receiveData(const QJsonDocument& data)
{
	QString action = jsonDoc::JsonDoc::getAction(data);

	if (action == "matchmakingUpdate")
	{
		jsonDoc::Matchmaking matchmakingJson;
		matchmakingJson.setJson(data);
		int playersCount = matchmakingJson.getPlayersInQueueCount();
		setPlayersInQueue(playersCount);
	}
}
