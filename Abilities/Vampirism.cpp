#include "Vampirism.h"

Vampirism::Vampirism(Unit* owner): Ability(owner, "Vampirism") {}
Vampirism::~Vampirism() {}

void Vampirism::action(Unit* target) {
    UnitType targetType = target->getType();

    if ( targetType != vampire ) {
        if ( targetType != necromancer ) {
            drainLife(target);
        }
        if ( targetType != werewolf ) {
            infect(target);
        }
    }
}

void Vampirism::drainLife(Unit* victim) {
    owner->addHitPoints(victim->getHitPointsLimit()/10);
}

void Vampirism::infect(Unit* victim) {
    victim->setAbility(new Vampirism(victim));
    victim->changeName(victim->getName()+"(Vampire)");
}