#include "Warlock.h"

Warlock::Warlock(const std::string& name, int hitPoints, int damage, int speed, int mana):
    SpellCaster(name, hitPoints, damage, speed, mana) {
        type = warlock;
        ability = NULL;
        slave = NULL;
        spell = new FireBall();
        spellBook->addSpell(spell);
    }

Warlock::~Warlock() {
    if ( slave != NULL ) {
        freeSlave();
    }
}

void Warlock::setSlave(Demon* demon) {
    slave = demon;
}

void Warlock::summon() {
    if ( actionPoints == 0 ) {
        throw NotEnoughActionPoints();
    } else {
        spendMana(50);
        actionPoints -= 1;
        if ( slave != NULL ) {
            freeSlave();
        }
        slave = new Demon(this);
    }
}

void Warlock::freeSlave() {
    delete slave;
    slave = NULL;
}

Demon* Warlock::demon() {
    if ( slave == NULL ) {
        throw SummonException();
    }
    return slave;
}