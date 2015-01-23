#ifndef HEALER_H
#define HEALER_H 

#include <iostream>
#include "SpellCaster.h"
#include "../../Spells/Heal.h"

class Healer : public SpellCaster {
    public:
        Healer(const std::string& name="Healer", int hitPoints=100, int damage=10, int speed=3, int mana=150);
        ~Healer();
};

#endif //HEALER_H