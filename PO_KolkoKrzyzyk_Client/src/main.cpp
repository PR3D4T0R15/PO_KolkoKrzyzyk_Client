
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include <QIcon>
#include <QResource>

#include "include/ConnectionManager.h"
#include "include/WindowControl.h"
#include "include/MainWindowControl.h"
#include "include/StartViewControl.h"


int main(int argc, char* argv[])
{
	//load resource file
	QResource::registerResource("ui/PO_KolkoKrzyzyk_GUI.rcc");

	//default setup
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;

	//Connection manager
	ConnectionManager* connManager = new ConnectionManager(&app);

	//Cpp classes in QML
	qmlRegisterType<WindowControl>("backend.WindowControl", 1, 0, "WindowControl");
	qmlRegisterType<MainWindowControl>("backend.MainWindowControl", 1, 0, "MainWindowControl");
	qmlRegisterType<StartViewControl>("backend.StartViewControl", 1, 0, "StartViewControl");

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

	QObject* rootQml = engine.rootObjects().first();

	//find WindowControl
	WindowControl* windowControl = rootQml->findChild<WindowControl*>("windowControl");
	if (windowControl)
	{
		
	}


	return app.exec();
}
