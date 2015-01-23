#ifndef BERSERKER_H
#define BERSERKER_H

#include <iostream>
#include "../Unit.h"

class Berserker : public Unit {
    public:
        Berserker(const std::string& name="Berserker", int hitPoints=200, int damage=20, int speed=4);
        ~Berserker();
        void attack(Unit* enemy);
        void takeMagicDamage(int dmg);
};

#endif //BERSERKER_H
