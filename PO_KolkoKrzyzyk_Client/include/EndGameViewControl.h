#pragma once

#include <QObject>

class EndGameViewControl : public QObject
{
	Q_OBJECT

public:
	EndGameViewControl();
	~EndGameViewControl();

	static void setStatus(const QString& status);

public slots:
	void playAgainButtonClicked();
	void goToMenuButtonClicked();

private slots:

signals:
	void changePanel(const QString& panel);
	void changeView(QString view);

private:

private:
	static QString _status;
};
