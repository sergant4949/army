#include "FireBall.h"

FireBall::FireBall(int spellCost, int actionPoints) : 
    Spell(spellCost, actionPoints) {
        sType = battle;
        spellName = "Fireball";
    }
    
FireBall::~FireBall() {}

void FireBall::action(Unit* target) {
    target->takeMagicDamage(actionPoints);
}