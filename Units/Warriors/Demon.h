#ifndef DEMON_H
#define DEMON_H

#include "Soldier.h"
#include "../SpellCasters/Warlock.h"

class Warlock;

class Demon : public Soldier {
    private:
        Warlock* master;

    public:
        Demon(Warlock* master, const std::string& name="Demon", int hitPoints=150, int damage=20, int speed=5);
        ~Demon();
};

#endif //DEMON_H