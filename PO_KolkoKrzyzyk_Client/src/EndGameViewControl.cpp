#include "include/EndGameViewControl.h"

EndGameViewControl::EndGameViewControl()
{
}

EndGameViewControl::~EndGameViewControl()
{
}

QString EndGameViewControl::_status = "draw";


void EndGameViewControl::setStatus(const QString& status)
{
	_status = status;
}




void EndGameViewControl::playAgainButtonClicked()
{
	emit changeView("MatchmakingView");
}

void EndGameViewControl::goToMenuButtonClicked()
{
	emit changeView("HomeView");
}
