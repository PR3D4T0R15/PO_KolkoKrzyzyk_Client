#include "include/EndGameViewControl.h"

EndGameViewControl::EndGameViewControl()
{
	setPanel(_status);
}

EndGameViewControl::~EndGameViewControl()
{
}

QString EndGameViewControl::_status = "draw";


void EndGameViewControl::setStatus(const QString& status)
{
	_status = status;
}

QString EndGameViewControl::getPanel()
{
	return _panel;
}

void EndGameViewControl::setPanel(const QString& panel)
{
	_panel = panel;
}


void EndGameViewControl::playAgainButtonClicked()
{
	emit changeView("MatchmakingView");
}

void EndGameViewControl::goToMenuButtonClicked()
{
	emit changeView("HomeView");
}

void EndGameViewControl::windowReady()
{
	emit panelChanged();
}
