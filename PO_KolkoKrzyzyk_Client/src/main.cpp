#include "include/main.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include "include/WindowControl.h"
#include "include/GameControl.h"


int main(int argc, char* argv[])
{
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;

	WindowControl uiControl;
	GameControl gameControl;


	QGuiApplication::setWindowIcon(QIcon(":/content/images/ico256x256.png"));
	
	const QUrl url(u"qrc:/content/MainWindow.qml"_qs);

	QObject::connect(
		&engine, &QQmlApplicationEngine::objectCreated, &app,
		[url](QObject* obj, const QUrl& objUrl) {
			if (!obj && url == objUrl)
				QCoreApplication::exit(-1);
		},
		Qt::QueuedConnection);

	engine.load(url);

	if (engine.rootObjects().isEmpty()) {
		return -1;
	}

	return app.exec();
}