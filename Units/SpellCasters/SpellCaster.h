#ifndef SPELL_CASTER_H
#define SPELL_CASTER_H

#include <iostream>
#include "../Unit.h"
#include "../../exceptions.h"
#include "../../Spells/Spell.h"
#include "../../Spells/SpellBook.h"

class SpellBook;

class SpellCaster : public Unit {
    protected:
        int mana;
        int manaLimit;
        Spell* spell;
        SpellBook* spellBook;

    public:
        SpellCaster(const std::string& name, int hitPoints, int damage, int speed, int mana);
        ~SpellCaster();

        int getMana() const;
        int getManaLimit() const;
        SpellBook& getSpellBook() const;

        void addMana(int extra);
        void spendMana(int extra);
        void changeSpell(Spell* newSpell);
        void attack(Unit* enemy);
        void cast(Unit* target);
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& sp);

#endif //SPELL_CASTER_H