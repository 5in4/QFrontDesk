#ifndef REQUESTMANAGER_H
#define REQUESTMANAGER_H

#include <QObject>
#include <QList>

#include <request.h>

class RequestManager : public QObject
{
    Q_OBJECT
public:
    explicit RequestManager(int slots_max, QObject *parent);

    Request *getFreeSlot();

private:
   QList<Request*> requests;
   int slots_max;
signals:
    
public slots:
    
};

#endif // REQUESTMANAGER_H
