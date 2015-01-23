#include "Lightning.h"

Lightning::Lightning(int spellCost, int actionPoints) : 
    Spell(spellCost, actionPoints) {
        sType = battle;
        spellName = "Lightning";
    }
    
Lightning::~Lightning() {}

void Lightning::action(Unit* target) {
    target->takeMagicDamage(actionPoints);
}