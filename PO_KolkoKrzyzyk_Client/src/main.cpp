#include "include/main.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include <QResource>
#include "include/WindowControl.h"
#include "include/GameControl.h"
#include "include/WindowViews.h"


int main(int argc, char* argv[])
{
	//load resource file
	QResource::registerResource("ui/PO_KolkoKrzyzyk_GUI.rcc");

	//default setup
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;

	//classes for QML signals and slots
	WindowControl* windowControl = new WindowControl(&app);
	GameControl* gameControl = new GameControl(&app);
	WindowViews* viewsControl = new WindowViews(&app);

	//views signal exit to close app
	QObject::connect(viewsControl, &WindowViews::inExit, &app, &QGuiApplication::quit);

	//classes register in QML
	engine.rootContext()->setContextProperty("windowControl", windowControl);
	engine.rootContext()->setContextProperty("gameControl", gameControl);

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
