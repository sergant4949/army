#include "Vampire.h"

Vampire::Vampire(const std::string& name, int hitPoints, int damage, int speed):
    Unit(name, hitPoints, damage, speed) {
        type = vampire;
        ability = new Vampirism(this);
    }

Vampire::~Vampire() {
    delete ability;
}

void Vampire::attack(Unit* enemy) {
    Unit::attack(enemy);
}

void Vampire::counterAttack(Unit* enemy) {
    Unit::counterAttack(enemy);
}