#include "include/main.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include <QResource>

#include "include/ConnectionManager.h"
#include "include/WindowControl.h"
#include "include/GameControl.h"
#include "include/TcpClient.h"


int main(int argc, char* argv[])
{
	//load resource file
	QResource::registerResource("ui/PO_KolkoKrzyzyk_GUI.rcc");

	//default setup
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;

	//Connection manager
	ConnectionManager* connManager = new ConnectionManager(&app);

	//classes for QML signals and slots
	WindowControl* windowControl = new WindowControl(&app);

	QObject::connect(connManager, &ConnectionManager::connectionOk, windowControl, &WindowControl::connectionOk);
	QObject::connect(connManager, &ConnectionManager::connectionNotOk, windowControl, &WindowControl::connectionNotOk);
	QObject::connect(windowControl, &WindowControl::inConnectToServer, connManager, &ConnectionManager::connect);
	QObject::connect(connManager, &ConnectionManager::updatePlayerRanking, windowControl, &WindowControl::updatePlayerRanking);
	QObject::connect(windowControl, &WindowControl::sendNewAccountCred, connManager, &ConnectionManager::newAccountCredReceived);
	QObject::connect(windowControl, &WindowControl::sendLoginCred, connManager, &ConnectionManager::loginCredReceived);

	//classes register in QML
	engine.rootContext()->setContextProperty("windowControl", windowControl);

	//default setup
	QGuiApplication::setWindowIcon(QIcon(":/content/images/ico256x256.png"));

	const QUrl url(u"qrc:/content/MainWindow.qml"_qs);

	QObject::connect(
		&engine, &QQmlApplicationEngine::objectCreated, &app,
		[url](QObject* obj, const QUrl& objUrl)
		{
			if (!obj && url == objUrl)
				QCoreApplication::exit(-1);
		},
		Qt::QueuedConnection);

	engine.load(url);

	if (engine.rootObjects().isEmpty())
	{
		return -1;
	}


	return app.exec();
}
