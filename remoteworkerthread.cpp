#include "remoteworkerthread.h"
#include <QMutex>
#include <QWaitCondition>

// testing
#include <QDebug>
//~

RemoteWorkerThread::RemoteWorkerThread(int *t_externalData)
    : externalData(t_externalData){

    m_running = true;

}

RemoteWorkerThread::~RemoteWorkerThread()
{
    m_running = false;
    wait();
}

void RemoteWorkerThread::run()
{
    while(m_running) {
        static quint64 counter = 0;
#ifdef MAKE_DEADLOCK
        qDebug() << "about to deadlock";
        *externalData = *externalData * 2;
#endif
        qDebug() << counter++;
    }
}
