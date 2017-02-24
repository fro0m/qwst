#ifndef REMOTEWORKERTHREAD_H
#define REMOTEWORKERTHREAD_H

#include <QObject>
#include <QThread>


class RemoteWorkerThread : public QThread
{
public:
    RemoteWorkerThread() = delete;
    RemoteWorkerThread(int *t_externalData);

    ~RemoteWorkerThread();
    void stopThread() {
        m_running = false;
    }

protected:
    void run() override;
private:
    bool m_running;
    int *externalData;
};

#endif // REMOTEWORKERTHREAD_H
