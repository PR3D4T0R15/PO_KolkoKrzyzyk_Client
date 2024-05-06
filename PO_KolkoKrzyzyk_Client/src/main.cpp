#include "include/main.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char* argv[])
{
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;

	QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
		QCoreApplication::instance(), QCoreApplication::quit,
		Qt::QueuedConnection);

	engine.load(QUrl("qrc:/content/MainWindow.qml"));



	return app.exec();
}