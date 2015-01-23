#ifndef LIGHTNING_H
#define LIGHTNING_H

#include <iostream>
#include "Spell.h"
#include "../Units/Unit.h"

class Lightning: public Spell {
    public:
        Lightning(int spellCost = 20, int actionPoints = 20);
        virtual ~Lightning();
        virtual void action(Unit* target);
};

#endif //LIGHTNING_H