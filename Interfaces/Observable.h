#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <iostream>
#include <set>
#include "Observer.h"
#include "../exceptions.h"

class Observer;

class Observable {
    protected:
        std::set<Observer*> observers;

    public:
        Observable();
        ~Observable();

        const std::set<Observer*>& getObservers() const;

        void addObserver(Observer* observer);
        void removeObserver(Observer* observer);
        virtual void notify() = 0;
};

#endif //OBSERVABLE_H
