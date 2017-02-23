#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "StateMachine.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    StateMachine stateMachine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    stateMachine.start();
    return app.exec();
}

