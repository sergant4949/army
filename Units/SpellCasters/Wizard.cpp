#include "Wizard.h"

Wizard::Wizard(const std::string& name, int hitPoints, int damage, int speed, int mana):
    SpellCaster(name, hitPoints, damage, speed, mana) {
        type = wizard;
        ability = NULL;
        spellBook->addSpell(new Lightning());
        spell = new FireBall();
        spellBook->addSpell(spell);
    }

Wizard::~Wizard() {}
