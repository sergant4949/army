#include "Berserker.h"

Berserker::Berserker(const std::string& name, int hitPoints, int damage, int speed)
        : Unit(name, hitPoints, damage, speed) {
            type = berserker;
            ability = NULL;
        }

Berserker::~Berserker() {}

void Berserker::attack(Unit* enemy) {
    Unit::attack(enemy);
}

void Berserker::takeMagicDamage(int dmg) {}