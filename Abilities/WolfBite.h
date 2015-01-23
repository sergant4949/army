#ifndef WOLFBITE_H
#define WOLFBITE_H

#include "../Units/Unit.h"

class WolfBite: public Ability {
    public:
        WolfBite(Unit* owner);
        ~WolfBite();

        virtual void action(Unit* target);
        void infect(Unit* victim);
};

#endif // WOLFBITE_H