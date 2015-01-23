#ifndef HEAL_H
#define HEAL_H

#include <iostream>
#include "Spell.h"
#include "../Units/Unit.h"

class Heal : public Spell {
    public:
        Heal(int spellCost = 30, int actionPoints = 30);
        virtual ~Heal();
        virtual void action(Unit* target);
};

#endif //HEAL_H