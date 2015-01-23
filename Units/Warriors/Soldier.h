#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "../Unit.h"

class Soldier : public Unit {
    public:
        Soldier(const std::string& name="Soldier", int hitPoints=150, int damage=20, int speed=3);
        ~Soldier();
        void attack(Unit* enemy);
};

#endif //SOLDIER_H
