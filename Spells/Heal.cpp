#include "Heal.h"

Heal::Heal(int spellCost, int actionPoints) :
    Spell(spellCost, actionPoints) {
        sType = healing;
        spellName = "Heal";
    }

Heal::~Heal() {}

void Heal::action(Unit* target) {
    target->addHitPoints(actionPoints);
}