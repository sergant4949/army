#include "SpellBook.h"

SpellBook::SpellBook(SpellCaster* owner): owner(owner) {
    spellsList = new std::set<Spell*>();
}

SpellBook::~SpellBook() {
    spellsList->clear();
    delete spellsList;
}

SpellCaster* SpellBook::getOwner() const {
    return owner;
}

std::set<Spell*>* SpellBook::getSpellsList() const {
    return spellsList;
}

void SpellBook::addSpell(Spell* newSpell) {
    spellsList->insert(newSpell);
}

std::string SpellBook::spellName(Spell* spell) const {
    return spell->name();
}

void SpellBook::removeSpell(Spell* removedSpell) {
    spellsList->erase(removedSpell);
}

std::ostream& operator << (std::ostream& out, const SpellBook& sBook) {
    std::set<Spell*>* lst = sBook.getSpellsList();
    std::set<Spell*>::iterator it = lst->begin();

    out << " spells: [ ";
    for ( int i = lst->size() ; i > 1 ; it++, i-- ) {
        out << sBook.spellName(*it) << ", ";
    }
    out << sBook.spellName(*it) << " ]";

    return out;
}