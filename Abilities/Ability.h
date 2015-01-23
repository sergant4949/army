#ifndef ABILITY_H
#define ABILITY_H

#include <iostream>
#include "../Units/Unit.h"

class Unit;

class Ability {
    protected:
        std::string name;
        Unit* owner;

    public:
        Ability(Unit* owner, const std::string& name);
        ~Ability();

        std::string getName() const;
        virtual void action(Unit* target);
};

#endif // ABILITY_H