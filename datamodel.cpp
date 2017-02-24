#include "datamodel.h"
#include "StateMachine.h"
#include "statestringgenerator.h"
#include <QCoreApplication>

// testing
#include <QDebug>
//~

DataModel * DataModel::m_instance = nullptr;

DataModel::DataModel(QObject *parent)
    : QObject(parent)
{
    connect(&m_titleGenerator, &StateStringGenerator::titleChanged, this, &DataModel::titleGeneratorChanged);
    m_stateMachine.connectToState("State1On", [=](bool t_state) {
        qDebug() << m_stateMachine.activeStateNames() << "State1On is " << t_state;
        m_titleGenerator.setFirstState(QString("banana is %1").arg(t_state));
    });
    m_stateMachine.connectToState("State2On", [=](bool t_state) {
        qDebug() << m_stateMachine.activeStateNames() << "State2On is" << t_state;
        m_titleGenerator.setSecondState(QString("kiwi is %1").arg(t_state));
    });
    m_stateMachine.connectToState("State3On", [=](bool t_state) {
        qDebug() << m_stateMachine.activeStateNames() << "State3On is" << t_state;
        m_titleGenerator.setThirdState(QString("apple is %1").arg(t_state));
    });
    m_stateMachine.submitEvent(std::move("Transition_2"));
    m_stateMachine.start();
    m_remoteWorkerThread.start(QThread::LowPriority);
    //connect(qApp, &QCoreApplication::aboutToQuit, &m_remoteWorkerThread, &QThread::quit);
    //keeping address of itself
    m_instance = this;
}

StateMachine * DataModel::stateMachine()
{
    return &m_stateMachine;
}

void DataModel::stopRemoteThread()
{
    m_remoteWorkerThread.stopThread();
}


