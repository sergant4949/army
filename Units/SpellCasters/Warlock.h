#ifndef WARLOCK_H
#define WARLOCK_H 

#include <iostream>
#include "SpellCaster.h"
#include "../../Spells/FireBall.h"
#include "../Warriors/Demon.h"

class Demon;

class Warlock : public SpellCaster {
    private:
        Demon* slave;

    public:
        Warlock(const std::string& name="Warlock", int hitPoints=100, int damage=10, int speed=3, int mana=150);
        ~Warlock();

        void summon();
        void freeSlave();
        void setSlave(Demon* demon);
        Demon* demon();
};

#endif //WARLOCK_H