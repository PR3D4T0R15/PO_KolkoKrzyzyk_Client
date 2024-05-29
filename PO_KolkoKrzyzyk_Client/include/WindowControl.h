#pragma once

#include <QObject>
#include <QDebug>
#include <QQuickItem>
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QStringList>

class WindowControl : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString errInfo READ getErrInfo WRITE setErrInfo NOTIFY errInfoChanged)

public:
	WindowControl(QObject* parent = nullptr);
	~WindowControl();

	//Q_PROPERTY
	void setErrInfo(const QString& newErrInfo);
	QString getErrInfo();

public slots:

private slots:
	void stateInfo();

signals:
	//Q_PROPERTY
	void errInfoChanged();

	//transitions buttons
	void welcomeButtonClicked();
	void newAccountButtonClicked();
	void createNewAccountButtonClicked();
	void goToLoginButtonClicked();
	void logInButtonClicked();
	void logOutButtonClicked();
	void exitButtonClicked();
	void playButtonClicked();
	void gameLeaveButtonClicked();
	void playAgainButtonClicked();
	void goToMenuButtonClicked();

	void aboutButtonClicked();
	void settingsButtonClicked();
	void soundButtonClicked();

	void connectionOk();
	void connectionNotOk();
	void accountCreated();
	void accountNotCreated();
	void loginOk();
	void loginNotOk();
	void logoutOk();
	void matchmakingNotOk();
	void matchmakingOk();
	void exitMatchmakingOk();
	void exitMatchmakingNotOk();

	
	void exitMatchmaking();
	void gameReady();
	void gameStarted();
	void gameEnd();
	

	//state entered signals
	void inStartView();
	void inConnectedToServer();
	void inLoginView();
	void inLogin();
	void inLogout();
	void inNewAccountView();
	void inCreateAccount();
	void inHomeView();
	void inStartMatchmaking();
	void inStopMatchmaking();
	void inMatchmakingView();
	void inStartGame();
	void inEndGame();
	void inGameView();
	void inEndGameView();
	void inExit();


private:
	//Q_PROPERTY
	QString _errInfo;

	//fsm
	QStateMachine* _windowView;
	QState* _startView;
	QState* _connectToServer;
	QState* _loginView;
	QState* _login;
	QState* _logout;
	QState* _newAccountView;
	QState* _createAccount;
	QState* _homeView;
	QState* _startMatchmaking;
	QState* _stopMatchmaking;
	QState* _matchmakingView;
	QState* _startGame;
	QState* _endGame;
	QState* _gameView;
	QState* _endgameView;
	QFinalState* _exit;

	//lists
	QStringList _buttons;
};