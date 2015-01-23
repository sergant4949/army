#include "WolfBite.h"

WolfBite::WolfBite(Unit* owner): Ability(owner, "WolfBite") {}
WolfBite::~WolfBite() {}

void WolfBite::action(Unit* target) {
    UnitType targetType = target->getType();

    if ( targetType != vampire && targetType != werewolf ) {
        infect(target);
    }
}

void WolfBite::infect(Unit* victim) {
    victim->setAbility(new WolfBite(victim));
    victim->changeName(victim->getName()+"(Werewolf)");
}