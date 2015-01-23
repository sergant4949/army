#ifndef ROGUE_H
#define ROGUE_H

#include <iostream>
#include "../Unit.h"

class Rogue : public Unit {
    public:
        Rogue(const std::string& name="Rogue", int hitPoints=100, int damage=30, int speed=5);
        ~Rogue();
        void attack(Unit* enemy);
};

#endif //ROGUE_H
