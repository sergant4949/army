#ifndef VAMPIRISM_H
#define VAMPIRISM_H

#include "../Units/Unit.h"

class Vampirism: public Ability {
    public:
        Vampirism(Unit* owner);
        ~Vampirism();

        virtual void action(Unit* target);
        void drainLife(Unit* victim);
        void infect(Unit* victim);
};

#endif // VAMPIRISM_H