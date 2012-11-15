#include "requestmanager.h"

RequestManager::RequestManager(int slots_max = 10, QObject *parent = 0) :
    QObject(parent)
{
    this->slots_max = slots_max;
}


Request* RequestManager::getFreeSlot() {
    for(int i=0; i<requests.length(); i++) {
        if(requests.at(i)->isFree()) {
            requests.at(i)->deleteLater();
            requests.removeAt(i);
        }
    }

    // create and return new request
    if(requests.length() < slots_max) {
        requests.append(new Request(this));
        return requests.last();
    }
    return 0;
}
