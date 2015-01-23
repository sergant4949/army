#ifndef NECROMANCER_H
#define NECROMANCER_H 

#include <iostream>
#include "SpellCaster.h"
#include "../../Spells/FireBall.h"

class Necromancer : public SpellCaster {
    public:
        Necromancer(const std::string& name="Necromancer", int hitPoints=90, int damage=10, int speed=3, int mana=150);
        ~Necromancer();

        void takeDamage(int dmg);
        void cast(Unit* target);
};

#endif //NECROMANCER_H