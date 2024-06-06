#include "include/StartViewControl.h"

//konsttruktor
StartViewControl::StartViewControl(QObject *parent): QObject(parent)
{
}

//destruktor
StartViewControl::~StartViewControl()
{
}



//public slot
void StartViewControl::welcomeButtonClicked()
{
	emit changeView("HomeView");
}
