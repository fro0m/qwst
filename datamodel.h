#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>
#include <QAbstractItemModel>
#include "StateMachine.h"
#include "statestringgenerator.h"

class DataModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(StateMachine * stateMachine READ stateMachine NOTIFY stateMachineChanged)
    Q_PROPERTY(StateStringGenerator * titleGenerator READ titleGenerator NOTIFY titleGeneratorChanged)
public:
    explicit DataModel(QObject * parent = nullptr);
    StateMachine * stateMachine();


    StateStringGenerator * titleGenerator()
    {
        return &m_titleGenerator;
    }

signals:
    void stateMachineChanged(StateMachine * stateMachine);
    void titleGeneratorChanged(StateStringGenerator * titleGenerator);
private:
    StateMachine m_stateMachine {this};
    StateStringGenerator m_titleGenerator {this};
    QString m_title;
};

#endif // DATAMODEL_H
