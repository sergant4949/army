#ifndef FIRE_BALL_H
#define FIRE_BALL_H

#include <iostream>
#include "Spell.h"
#include "../Units/Unit.h"

class FireBall : public Spell {
    public:
        FireBall(int spellCost = 30, int actionPoints = 30);
        virtual ~FireBall();
        virtual void action(Unit* target);
};

#endif //FIRE_BALL_H