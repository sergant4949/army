#ifndef PRIEST_H
#define PRIEST_H 

#include <iostream>
#include "SpellCaster.h"
#include "../../Spells/Heal.h"

class Priest : public SpellCaster {
    public:
        Priest(const std::string& name="Priest", int hitPoints=120, int damage=10, int speed=4, int mana=200);
        ~Priest();
};

#endif //PRIEST_H