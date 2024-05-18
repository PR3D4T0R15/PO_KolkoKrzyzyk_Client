#include "include/WindowViews.h"

WindowViews::WindowViews(QObject *parent): QObject(parent)
{
	//state machine object
	_windowView = new QStateMachine();

	//state objects
	_startView = new QState();
	_loginView = new QState();
	_newAccount = new QState();
	_homeView = new QState();
	_matchmakingView = new QState();
	_gameView = new QState();
	_endgameView = new QState();
	_exit = new QFinalState();

	//adding states to machine
	_windowView->addState(_startView);
	_windowView->addState(_loginView);
	_windowView->addState(_newAccount);
	_windowView->addState(_homeView);
	_windowView->addState(_matchmakingView);
	_windowView->addState(_gameView);
	_windowView->addState(_endgameView);

	//initial state
	_windowView->setInitialState(_startView);

	//transitions
	_startView->addTransition(this, &WindowViews::goToLoginView, _loginView);
	_loginView->addTransition(this, &WindowViews::goToNewAccountView, _newAccount);
	_loginView->addTransition(this, &WindowViews::goToHomeView, _homeView);
	_newAccount->addTransition(this, &WindowViews::goToLoginView, _loginView);
	_homeView->addTransition(this, &WindowViews::goToMatchmakingView, _matchmakingView);
	_homeView->addTransition(this, &WindowViews::goToExit, _exit);
	_homeView->addTransition(this, &WindowViews::goToStartView, _startView);
	_matchmakingView->addTransition(this, &WindowViews::goToHomeView, _homeView);
	_matchmakingView->addTransition(this, &WindowViews::goToGameView, _gameView);
	_gameView->addTransition(this, &WindowViews::goToEndgameView, _endgameView);
	_endgameView->addTransition(this, &WindowViews::goToMatchmakingView, _matchmakingView);
	_endgameView->addTransition(this, &WindowViews::goToHomeView, _homeView);


	//entered signals
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

void WindowViews::goToLoginView()
{
}

void WindowViews::goToNewAccountView()
{
}

void WindowViews::goToHomeView()
{
}

void WindowViews::goToMatchmakingView()
{
}

void WindowViews::goToGameView()
{
}

void WindowViews::goToEndgameView()
{
}

void WindowViews::goToExit()
{
}

void WindowViews::goToStartView()
{
}
