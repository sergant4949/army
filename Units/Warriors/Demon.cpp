#include "Demon.h"

Demon::Demon(Warlock* master, const std::string& name, int hitPoints, int damage, int speed):
    Soldier(name, hitPoints, damage, speed) {
    this->master = master;
    master->setSlave(this);
    ability = NULL;
}

Demon::~Demon() {
    master = NULL;
}
