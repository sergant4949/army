#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <iostream>
#include "Spell.h"
#include "../Units/SpellCasters/SpellCaster.h"

class SpellCaster;

class SpellBook {
    private:
        std::set<Spell*>* spellsList;
        SpellCaster* owner;
    public:
        SpellBook(SpellCaster* owner);
        ~SpellBook();
        
        SpellCaster* getOwner() const;
        std::set<Spell*>* getSpellsList() const;
        std::string spellName(Spell* spell) const;
        void addSpell(Spell* newSpell);
        void removeSpell(Spell* removedSpell);
};

std::ostream& operator << (std::ostream& out, const SpellBook& sBook);

#endif // SPELLBOOK_H