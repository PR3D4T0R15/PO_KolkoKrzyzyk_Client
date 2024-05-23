#pragma once

#include <QObject>
#include <QDebug>
#include <QQuickItem>
#include <QMetaObject>

class WindowControl : public QObject
{
	Q_OBJECT

public:
	WindowControl(QObject* parent = nullptr);
	~WindowControl();

public slots:
	//QML
	void uiButtonClicked(QObject* obj);

	//C++
	void goToStartView();
	void goToLoginView();
	void goToNewAccountView();
	void goToHomeView();
	void goToMatchmakingView();
	void goToGameView();
	void goToEndgameView();

signals:
	//QML
	void uiChangeView(QString view);
	void uiChangeState(QString state);

	//C++
	void welcomeButtonClicked();
	void newAccountButtonClicked();
	void logInButtonClicked();
	void createNewAccountButtonClicked();
	void goToLoginButtonClicked();
	void playButtonClicked();
	void logOutButtonClicked();
	void exitButtonClicked();
	void exitMatchmakingButtonClicked();
	void gameLeaveButtonClicked();
	void playAgainButtonClicked();
	void goToMenuButtonClicked();

private:
};
