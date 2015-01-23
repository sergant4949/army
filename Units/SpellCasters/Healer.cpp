#include "Healer.h"

Healer::Healer(const std::string& name, int hitPoints, int damage, int speed, int mana):
    SpellCaster(name, hitPoints, damage, speed, mana) {
        type = healer;
        ability = NULL;
        spell = new Heal(30, 30);
        spellBook->addSpell(spell);
    }

Healer::~Healer() {}
