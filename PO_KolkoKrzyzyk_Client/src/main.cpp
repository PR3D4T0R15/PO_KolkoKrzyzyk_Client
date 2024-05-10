#include "include/main.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>


int main(int argc, char* argv[])
{
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;

	QGuiApplication::setWindowIcon(QIcon(":/content/images/ico256x256.png"));
	
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
		QCoreApplication::instance(), QCoreApplication::quit,
		Qt::QueuedConnection);

	engine.load(QUrl("qrc:/content/MainWindow.qml"));



	return QGuiApplication::exec();
}