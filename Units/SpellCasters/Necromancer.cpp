#include "Necromancer.h"

Necromancer::Necromancer(const std::string& name, int hitPoints, int damage, int speed, int mana):
    SpellCaster(name, hitPoints, damage, speed, mana) {
        ability = NULL;
        type = necromancer;
        spell = new FireBall();
        spellBook->addSpell(spell);
    }

void Necromancer::takeDamage(int dmg) {
    ensureIsAlive();
    if ( dmg >= hitPoints ) {
        notify();
        sendNotification();
        hitPoints = 0;
        return;
    }
    hitPoints -= dmg;
}

Necromancer::~Necromancer() {}

void Necromancer::cast(Unit* target) {
    spendMana(spell->cost());
    spell->action(target);
    addObservable(target);
}