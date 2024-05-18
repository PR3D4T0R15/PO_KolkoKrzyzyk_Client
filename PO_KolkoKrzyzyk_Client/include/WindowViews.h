#pragma once

#include <QObject>
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QList>

class WindowViews : public QObject
{
	Q_OBJECT

public:
	WindowViews(QObject *parent = nullptr);
	~WindowViews();

public slots:
	// void callMe();
	void goToStartView();
	void goToLoginView();
	void goToNewAccountView();
	void goToHomeView();
	void goToMatchmakingView();
	void goToGameView();
	void goToEndgameView();
	void goToExit();
signals:
	// void IWillCallSth()
	void inStartView();
	void inLoginView();
	void inNewAccount();
	void inHomeView();
	void inMatchmakingView();
	void inGameView();
	void inEndgameView();
	void inExit();
	

private:
	QStateMachine* _windowView;
	QState* _startView;
	QState* _loginView;
	QState* _newAccount;
	QState* _homeView;
	QState* _matchmakingView;
	QState* _gameView;
	QState* _endgameView;
	QFinalState* _exit;
};
