#ifndef STATESTRINGGENERATOR_H
#define STATESTRINGGENERATOR_H

#include <QObject>

class StateStringGenerator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title NOTIFY titleChanged)
public:
    explicit StateStringGenerator(QObject *parent = 0);

    QString getFirstState() const;
    void setFirstState(const QString &value);

    QString getSecondState() const;
    void setSecondState(const QString &value);

    QString getThirdState() const;
    void setThirdState(const QString &value);

    Q_INVOKABLE QString title() const;

signals:
    //void titleChanged(QString title);
    void titleChanged(StateStringGenerator * t_titleGenerator);

public slots:

private:
    QString firstState;
    QString secondState;
    QString thirdState;
};

#endif // STATESTRINGGENERATOR_H
