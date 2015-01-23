#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <iostream>
#include "../Unit.h"
#include "../../Abilities/Ability.h"
#include "../../Abilities/Vampirism.h"

class Vampire : public Unit {
    public:
        Vampire(const std::string& name="Vampire", int hitPoints=200, int damage=20, int speed=4);
        ~Vampire();
        
        void attack(Unit* enemy);
        void counterAttack(Unit* enemy);
};

#endif //VAMPIRE_H
