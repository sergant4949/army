#include "Ability.h"

Ability::Ability(Unit* owner, const std::string& name): owner(owner), name(name) {}
Ability::~Ability() {}

std::string Ability::getName() const {
    return name;
}

void Ability::action(Unit* target) {}