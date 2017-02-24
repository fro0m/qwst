#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "StateMachine.h"
#include "datamodel.h"


//#define MAKE_DEADLOCK

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<DataModel>("quest.model", 1, 0, "DataModel");
    qmlRegisterUncreatableType<StateMachine>("quest.model", 1, 0, "StateMachine", "StateMachine is creatable only from C++");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    QObject::connect(&engine, &QQmlApplicationEngine::quit, DataModel::instance(), &DataModel::stopRemoteThread);
    return app.exec();
}

