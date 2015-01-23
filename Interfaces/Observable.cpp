#include "Observable.h"

Observable::Observable() {}

Observable::~Observable() {
    std::set<Observer*>::iterator it = observers.begin();

    for ( ; it != observers.end(); it++ ) {
        (*it)->removeObservable(this);
    }
}

const std::set<Observer*>& Observable::getObservers() const {
    return observers;
}

void Observable::addObserver(Observer* observer) {
    observers.insert(observer);
}

void Observable::removeObserver(Observer* observer) {
    observers.erase(observer);
}
