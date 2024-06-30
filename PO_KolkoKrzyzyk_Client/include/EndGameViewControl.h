#pragma once

#include <QObject>

class EndGameViewControl : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString panel READ getPanel WRITE setPanel NOTIFY panelChanged)

public:
	EndGameViewControl();
	~EndGameViewControl();

	static void setStatus(const QString& status);

	QString getPanel();
	void setPanel(const QString& panel);

public slots:
	void playAgainButtonClicked();
	void goToMenuButtonClicked();
	void windowReady();

private slots:

signals:
	void panelChanged();
	void changeView(QString view);

private:

private:
	static QString _status;
	QString _panel;
};
