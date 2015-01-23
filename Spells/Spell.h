#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../Units/Unit.h"

enum SpellType {
    battle,
    healing
};

class Spell {
    protected:
        int spellCost;
        int actionPoints;
        std::string spellName;
        SpellType sType;
    public:
        Spell(int spellCost, int actionPoints);
        virtual ~Spell();

        int cost() const;
        int getActionPoints() const;
        std::string name() const;
        SpellType type() const;
        virtual void action(Unit* target) = 0;
};

std::ostream& operator << (std::ostream& out, const Spell& sp);

#endif //SPELL_H
