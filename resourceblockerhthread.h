#ifndef RESOURCEBLOCKERHTHREAD_H
#define RESOURCEBLOCKERHTHREAD_H

#include <QObject>
#include <QThread>
#include <QMutex>

class ResourceBlockerHThread : public QThread
{
    Q_OBJECT
public:
    ResourceBlockerHThread();
    int* getBlockedData();
    void setBlockedData(int value);
    void run() override;

private:
    int blockedData;
    QMutex mutex;
};

#endif // RESOURCEBLOCKERHTHREAD_H
