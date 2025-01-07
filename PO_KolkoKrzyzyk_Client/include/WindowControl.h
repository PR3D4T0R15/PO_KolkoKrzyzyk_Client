#pragma once

#include <QObject>

class WindowControl : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString view READ getView WRITE setView NOTIFY viewChanged)

public:
	explicit WindowControl(QObject* parent = nullptr);
	~WindowControl();

	//Q_PROPERTY
	void setView(const QString& view);
	QString getView();

public slots:
	void changeView(const QString& view);

private slots:

signals:
	//Q_PROPERTY
	void viewChanged();

private:
	QString _view;
};