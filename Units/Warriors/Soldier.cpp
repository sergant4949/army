#include "Soldier.h"

Soldier::Soldier(const std::string& name, int hitPoints, int damage, int speed):
    Unit(name, hitPoints, damage, speed) {
        type = soldier;
        ability = NULL;
    }

Soldier::~Soldier() {}

void Soldier::attack(Unit* enemy) {
    Unit::attack(enemy);
}
