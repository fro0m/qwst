#include "resourceblockerhthread.h"

ResourceBlockerHThread::ResourceBlockerHThread()
{
    mutex.lock();
}

int* ResourceBlockerHThread::getBlockedData()
{
    return &blockedData;
}

void ResourceBlockerHThread::setBlockedData(int value)
{
    blockedData = value;
}

void ResourceBlockerHThread::run()
{
    forever {}
}
