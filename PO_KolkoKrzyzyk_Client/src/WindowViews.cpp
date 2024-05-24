#include "include/WindowViews.h"

WindowViews::WindowViews(QObject *parent): QObject(parent)
{
	//state machine object
	_windowView = new QStateMachine();

	//state objects
	_startView = new QState();
	_connectToServer = new QState();
	_loginView = new QState();
	_newAccount = new QState();
	_homeView = new QState();
	_matchmakingView = new QState();
	_gameView = new QState();
	_endgameView = new QState();
	_exit = new QFinalState();

	//add names
	_startView->setObjectName("_startView");
	_connectToServer->setObjectName("_connectToServer");
	_loginView->setObjectName("_loginView");
	_newAccount->setObjectName("_newAccount");
	_homeView->setObjectName("_homeView");
	_matchmakingView->setObjectName("_matchmakingView");
	_gameView->setObjectName("_gameView");
	_endgameView->setObjectName("_endgameView");
	_exit->setObjectName("_exit");

	//adding states to machine
	_windowView->addState(_startView);
	_windowView->addState(_connectToServer);
	_windowView->addState(_loginView);
	_windowView->addState(_newAccount);
	_windowView->addState(_homeView);
	_windowView->addState(_matchmakingView);
	_windowView->addState(_gameView);
	_windowView->addState(_endgameView);

	//initial state
	_windowView->setInitialState(_startView);

	//transitions
	_startView->addTransition(this, &WindowViews::goToLoginView, _connectToServer);
	_connectToServer->addTransition(this, &WindowViews::connectionReady, _loginView);
	_connectToServer->addTransition(this, &WindowViews::connectionNotReady, _startView);
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
	QObject::connect(_startView, &QState::entered, this, &WindowViews::stateChanged);
	QObject::connect(_connectToServer, &QState::entered, this, &WindowViews::stateChanged);
	QObject::connect(_loginView, &QState::entered, this, &WindowViews::stateChanged);
	QObject::connect(_newAccount, &QState::entered, this, &WindowViews::stateChanged);
	QObject::connect(_homeView, &QState::entered, this, &WindowViews::stateChanged);
	QObject::connect(_matchmakingView, &QState::entered, this, &WindowViews::stateChanged);
	QObject::connect(_gameView, &QState::entered, this, &WindowViews::stateChanged);
	QObject::connect(_endgameView, &QState::entered, this, &WindowViews::stateChanged);

	QObject::connect(_windowView, &QState::finished, this, &WindowViews::inExit);

	_windowView->start();

	_buttons = { "welcomeButton",
					"newAccountButton",
					"logInButton",
					"createNewAccountButton",
					"goToLoginButton",
					"playButton",
					"logOutButton",
					"exitButton",
					"exitMatchmakingButton",
					"gameLeaveButton",
					"playAgainButton",
					"goToMenuButton"};
}

WindowViews::~WindowViews()
{
	_startView->deleteLater();
	_loginView->deleteLater();
	_newAccount->deleteLater();
	_homeView->deleteLater();
	_matchmakingView->deleteLater();
	_gameView->deleteLater();
	_endgameView->deleteLater();
	_exit->deleteLater();

	_windowView->deleteLater();
}

void WindowViews::buttonClicked(QString buttonId)
{
	int buttonIndex = _buttons.indexOf(buttonId);

	switch (buttonIndex)
	{
	case 0:
		emit goToLoginView();
		break;
	case 1:
		emit goToNewAccountView();
		break;
	case 2:
		emit goToLoginView();
		break;
	case 3:
		emit goToLoginView();
		break;
	case 4:
		emit goToLoginView();
		break;
	case 5:
		emit goToLoginView();
		break;
	case 6:
		emit goToLoginView();
		break;
	case 7:
		emit goToLoginView();
		break;
	case 8:
		emit goToLoginView();
		break;
	case 9:
		emit goToLoginView();
		break;
	case 10:
		emit goToLoginView();
		break;
	case 11:
		emit goToLoginView();
		break;
	}
}

void WindowViews::connectionStatus(bool status)
{
	if (status)
	{
		emit connectionReady();
	}
	else
	{
		emit connectionNotReady();
	}
	
}

void WindowViews::stateChanged()
{
	QState* state = qobject_cast<QState*>(sender());
	QString name = state->objectName();
	qDebug() << "state:" << name;
	if (state) {
		if (name == "_startView")
		{
			emit inStartView();
		}
		if (name == "_connectToServer")
		{
			emit connectionCheck();
		}
		if (name == "_loginView")
		{
			emit inLoginView();
		}
		if (name == "_newAccount")
		{
			emit inNewAccount();
		}
		if (name == "_homeView")
		{
			emit inHomeView();
		}
		if (name == "_matchmakingView")
		{
			emit inMatchmakingView();
		}
		if (name == "_gameView")
		{
			emit inGameView();
		}
		if (name == "_endgameView")
		{
			emit inEndgameView();
		}
		if (name == "_exit")
		{
			emit inExit();
		}
	}
}
