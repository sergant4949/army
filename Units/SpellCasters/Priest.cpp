#include "Priest.h"

Priest::Priest(const std::string& name, int hitPoints, int damage, int speed, int mana):
    SpellCaster(name, hitPoints, damage, speed, mana) {
        type = priest;
        ability = NULL;
        spell = new Heal(40, 40);
        spellBook->addSpell(spell);
    }

Priest::~Priest() {}
