#include <iostream>
#include "exceptions.h"
#include "Gamefield/Gamefield.h"
/*
#include "Units/SpellCasters/Wizard.h"
#include "Units/SpellCasters/Healer.h"
#include "Units/SpellCasters/Priest.h"
#include "Units/SpellCasters/Warlock.h"
#include "Units/SpellCasters/Necromancer.h"
#include "Units/Warriors/Berserker.h"
#include "Units/Warriors/Rogue.h"
#include "Units/Warriors/Soldier.h"
#include "Units/Warriors/Vampire.h"
#include "Units/Warriors/Werewolf.h"
*/
int main() {
    Gamefield* gf = new Gamefield(10, 10);

    gf->draw();
    gf->getCommand();

    return 0;
}
