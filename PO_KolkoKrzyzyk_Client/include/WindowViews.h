#pragma once

#include <QObject>
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QStringList>

class WindowViews : public QObject
{
	Q_OBJECT

public:
	WindowViews(QObject *parent = nullptr);
	~WindowViews();

public slots:

	void buttonClicked(QString buttonId);
	void connectionStatus(bool status);
	
private slots:
	void stateChanged();

signals:
	void changeUiView(QString view);
	void changeUiState(QString state);

	void goToStartView();
	void connectionReady();
	void connectionNotReady();
	void goToLoginView();
	void goToNewAccountView();
	void goToHomeView();
	void goToMatchmakingView();
	void goToGameView();
	void goToEndgameView();
	void goToExit();

	void inStartView();
	void connectionCheck();
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
	QState* _connectToServer;
	QState* _loginView;
	QState* _newAccount;
	QState* _homeView;
	QState* _matchmakingView;
	QState* _gameView;
	QState* _endgameView;
	QFinalState* _exit;
	QStringList _buttons;
};
