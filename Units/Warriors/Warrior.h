#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include "../Unit.h"

class Warrior: public Unit {
    protected:
        int strength;
        int maxStrength;
        Weapon* weapon;
        
    public:
        Warrior(const std::string& name, int hitPoints, int damage, int maxStrength);
        ~Warrior();

};

#endif // WARRIOR_H