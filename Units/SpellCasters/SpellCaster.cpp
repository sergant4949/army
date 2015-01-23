#include "SpellCaster.h"

SpellCaster::SpellCaster(const std::string& name, int hitPoints, int damage, int speed, int mana):
    Unit(name, hitPoints, damage, speed), mana(mana), manaLimit(mana) {
        spellBook = new SpellBook(this);
    }

SpellCaster::~SpellCaster() {
    std::set<Spell*>* sList = spellBook->getSpellsList();
    std::set<Spell*>::iterator it = sList->begin();
    
    for ( ; it != sList->end(); it++ ) {
        delete *it;
    }
    delete spellBook;
}

void SpellCaster::changeSpell(Spell* newSpell) {
    if ( actionPoints == 0 ) {
        throw NotEnoughActionPoints();
    }
    actionPoints -= 1;
    delete spell;
    spell = newSpell;
}

int SpellCaster::getMana() const {
    return mana;
}

int SpellCaster::getManaLimit() const {
    return manaLimit;
}

SpellBook& SpellCaster::getSpellBook() const {
    return *spellBook;
}

void SpellCaster::addMana(int extra) {
    if ( actionPoints == 0 ) {
        throw NotEnoughActionPoints();
    }
    actionPoints -= 1;
    ensureIsAlive();
    int total = mana + extra;

    if ( total > manaLimit ) {
        mana = manaLimit;
    } else {
        mana = total;
    }
}

void SpellCaster::spendMana(int cost) {
    ensureIsAlive();
    if ( cost > mana ) {
        throw OutOfManaException();
    }
    mana -= cost;
}

void SpellCaster::attack(Unit* enemy) {
    Unit::attack(enemy);
}

void SpellCaster::cast(Unit* target) {
    ensureIsAlive();
    if ( actionPoints == 0 ) {
        throw NotEnoughActionPoints();
    }
    actionPoints -= 1;
    spendMana(spell->cost());
    spell->action(target);
}

std::ostream& operator<<(std::ostream& out, const SpellCaster& sp) {
    out << (const Unit&)sp;
    if ( &sp != NULL ) {
        out << " mana: [ " << sp.getMana();
        out << "/" << sp.getManaLimit() << " ]";
        out << sp.getSpellBook();
    }
    return out; 
}
