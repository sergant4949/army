#include "Rogue.h"

Rogue::Rogue(const std::string& name, int hitPoints, int damage, int speed):
    Unit(name, hitPoints, damage, speed) {
        type = rogue;
        ability = NULL;
    }

Rogue::~Rogue() {}

void Rogue::attack(Unit* enemy) {
    if ( actionPoints == 0 ) {
        throw NotEnoughActionPoints();
    }
    actionPoints -= 1;
    enemy->takeDamage(damage);
}
