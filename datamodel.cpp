#include "datamodel.h"
#include "StateMachine.h"
#include "statestringgenerator.h"


// testing
#include <QDebug>
//~


DataModel::DataModel(QObject *parent)
    : QObject(parent)
{
    connect(&m_titleGenerator, &StateStringGenerator::titleChanged, this, &DataModel::titleGeneratorChanged);
    m_stateMachine.connectToState("State1On", [=](bool t_state) {
        qDebug() << m_stateMachine.activeStateNames() << "State1On is " << t_state;
        m_titleGenerator.setFirstState(QString("banana is%1").arg(t_state));
    });
    m_stateMachine.connectToState("State2On", [=](bool t_state) {
        qDebug() << m_stateMachine.activeStateNames() << "State2On is" << t_state;
        m_titleGenerator.setSecondState(QString("kiwi is%1").arg(t_state));
    });
    m_stateMachine.connectToState("State3On", [=](bool t_state) {
        qDebug() << m_stateMachine.activeStateNames() << "State3On is" << t_state;
        m_titleGenerator.setThirdState(QString("apple is %1").arg(t_state));
    });
    m_stateMachine.submitEvent(std::move("Transition_2"));
    m_stateMachine.connectToEvent("Transition_3", [=](const QScxmlEvent &event){
        qDebug("Transition_3 event is raised");
    });
    m_stateMachine.start();
}

StateMachine * DataModel::stateMachine()
{
    return &m_stateMachine;
}


