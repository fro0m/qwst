#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "StateMachine.h"
#include "datamodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<DataModel>("quest.model", 1, 0, "DataModel");
    qmlRegisterUncreatableType<StateMachine>("quest.model", 1, 0, "StateMachine", "nope");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    return app.exec();
}

