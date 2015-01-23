#include "Spell.h"

Spell::Spell(int spellCost, int actionPoints): spellCost(spellCost), actionPoints(actionPoints) {}
Spell::~Spell() {}

int Spell::cost() const {
    return spellCost;
}

int Spell::getActionPoints() const {
    return actionPoints;
}

std::string Spell::name() const {
    return spellName;
}

SpellType Spell::type() const {
    return sType;
}

std::ostream& operator << (std::ostream& out, const Spell& sp) {
    out << sp.name() << ": action points - " << sp.getActionPoints() << ", need " << sp.cost() << " mana";
    return out;
}