#include "statestringgenerator.h"

StateStringGenerator::StateStringGenerator(QObject *parent) : QObject(parent)
{

}

QString StateStringGenerator::getFirstState() const
{
    return firstState;
}

void StateStringGenerator::setFirstState(const QString &value)
{
    firstState = value;
    emit titleChanged(this);
}

QString StateStringGenerator::getSecondState() const
{
    return secondState;
}

void StateStringGenerator::setSecondState(const QString &value)
{
    secondState = value;
    emit titleChanged(this);
}

QString StateStringGenerator::getThirdState() const
{
    return thirdState;
}

void StateStringGenerator::setThirdState(const QString &value)
{
    thirdState = value;
    emit titleChanged(this);
}

QString StateStringGenerator::title() const
{
    return firstState + " " + secondState + " " + thirdState ;
}
