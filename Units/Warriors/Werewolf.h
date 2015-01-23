#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "../Unit.h"
#include "../../Abilities/Ability.h"
#include "../../Abilities/WolfBite.h"

class State {
    public:
        int hitPoints;
        int hitPointsLimit;
        int damage;
        int speed;
        int actionPoints;
        std::string name;

        State(const std::string& name="None", int hitPoints=0, int damage=0, int speed=0);
        ~State();
};

class Werewolf : public Unit {
    private:
        State currentState;
        State alterState;
        Ability* latentAbility;

    public:
        Werewolf(const std::string& name="Werewolf", int hitPoints=100, int damage=15, int speed=3);
        ~Werewolf();

        void changeState();
        void attack(Unit* enemy);
};

#endif //WEREWOLF_H