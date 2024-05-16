#include "include/WindowViews.h"

WindowViews::WindowViews(QObject *parent): QObject(parent)
{
	_windowView = new QStateMachine();

	_startView = new QState();
	_loginView = new QState();
	_newAccount = new QState();
	_homeView = new QState();
	_matchmakingView = new QState();
	_gameView = new QState();
	_endgameView = new QState();
	_exit = new QFinalState();

	_windowView->addState(_startView);
	_windowView->addState(_loginView);
	_windowView->addState(_newAccount);
	_windowView->addState(_homeView);
	_windowView->addState(_matchmakingView);
	_windowView->addState(_gameView);
	_windowView->addState(_endgameView);

	_windowView->setInitialState(_startView);

	_startView->addTransition(this, WindowViews::goToLoginView, _loginView);
	_loginView->addTransition(this, WindowViews::goToNewAccount, _newAccount);

	QObject::connect(_startView, &QState::entered, this, &WindowViews::inStartView);
	QObject::connect(_loginView, &QState::entered, this, &WindowViews::inLoginView);
	QObject::connect(_newAccount, &QState::entered, this, &WindowViews::inNewAccount);
	QObject::connect(_homeView, &QState::entered, this, &WindowViews::inHomeView);
	QObject::connect(_matchmakingView, &QState::entered, this, &WindowViews::inMatchmakingView);
	QObject::connect(_gameView, &QState::entered, this, &WindowViews::inGameView);
	QObject::connect(_endgameView, &QState::entered, this, &WindowViews::inEndgameView);
	QObject::connect(_windowView, &QState::finished, this, &WindowViews::inExit);



	_windowView->start();
}

WindowViews::~WindowViews()
{
	delete _windowView;
}
