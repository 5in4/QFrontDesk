#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <QObject>
#include <QList>
#include <QString>
#include <QVariant>

struct args{
    QString variable;
    QVariant value;
};


class Arguments : public QObject
{
    Q_OBJECT
public:
    explicit Arguments(QObject *parent = 0);
    
    QVariant get(QString var);
    void set(QString var, QVariant val);
    int length();
    QVariant at(int pos);

private:
    QList<args> *arguments;

signals:
    
public slots:
    
};

#endif // ARGUMENTS_H
