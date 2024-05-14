#pragma once

#include <QObject>
#include <QDebug>

class WindowControl : public QObject
{
	Q_OBJECT

public:
	WindowControl(QObject* parent = nullptr);
	~WindowControl();

public slots:
	// void callMe();
	//void settingsButton();
	//void aboutButton();
	//void volumeButton();

	void enterGameButton();
	//void logInButton();
	//void newAccountButton();
	//void logOutButton();
	//void exitButton();
	//void playButton();
	//void exitQueueButton();
	//void leaveMatchButton();
	//void playAgainButton();
	//void goToMenuButton();


signals:
	// void IWillCallSth()
	//void goToStartWindow();
	void goToLoginWindow();

private:
};
