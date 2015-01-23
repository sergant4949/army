#include "Observer.h"

Observer::Observer() {}

Observer::~Observer() {
    std::set<Observable*>::iterator it = observables.begin();

    for ( ; it != observables.end(); it++ ) {
        (*it)->removeObserver(this);
    }
}

const std::set<Observable*>& Observer::getObservables() const {
    return observables;
}

void Observer::addObservable(Observable* observable) {
    observables.insert(observable);
    observable->addObserver(this);
}

void Observer::removeObservable(Observable* observable) {
    observables.erase(observable);
}
