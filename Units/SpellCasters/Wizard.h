#ifndef WIZARD_H
#define WIZARD_H 

#include <iostream>
#include "SpellCaster.h"
#include "../../Spells/FireBall.h"
#include "../../Spells/Lightning.h"

class Wizard : public SpellCaster {
    public:
        Wizard(const std::string& name="Wizard", int hitPoints=100, int damage=10, int speed=3, int mana=150);
        ~Wizard();
};

#endif //WIZARD_H