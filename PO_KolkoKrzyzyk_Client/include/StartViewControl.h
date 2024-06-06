#pragma once

#include <QObject>

class StartViewControl : public QObject
{
	Q_OBJECT

public:
	explicit StartViewControl(QObject *parent = nullptr);
	~StartViewControl();

public slots:
	void welcomeButtonClicked();

private slots:

signals:
	void changeView(QString view);

private:
};
