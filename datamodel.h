#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>
#include <QAbstractItemModel>
#include "StateMachine.h"
#include "statestringgenerator.h"
#include "remoteworkerthread.h"
#include "resourceblockerhthread.h"

#include <QMutex>


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

public: // instance
    static DataModel * instance() {
        Q_ASSERT_X(DataModel::m_instance, Q_FUNC_INFO, "No instances of DataModel");
        return m_instance;
    }
signals:
    void stateMachineChanged(StateMachine * stateMachine);
    void titleGeneratorChanged(StateStringGenerator * titleGenerator);
public slots:
    void stopRemoteThread();
private:
    StateMachine m_stateMachine {this};
    StateStringGenerator m_titleGenerator {this};
    ResourceBlockerHThread m_blockerThread;
    RemoteWorkerThread m_remoteWorkerThread {m_blockerThread.getBlockedData()};
    static DataModel *m_instance;

private:
};

#endif // DATAMODEL_H
