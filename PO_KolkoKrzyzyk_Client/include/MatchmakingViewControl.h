#pragma once

#include <QObject>

class MatchmakingViewControl : public QObject
{
	Q_OBJECT

public:
	MatchmakingViewControl(QObject *parent = nullptr);
	~MatchmakingViewControl();
};
