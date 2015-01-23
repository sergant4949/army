#include "Werewolf.h"

State::State(const std::string& name, int hitPoints, int damage, int speed) {
    this->name = name;
    this->hitPoints = hitPoints;
    this->hitPointsLimit = hitPoints;
    this->damage = damage;
    this->speed = speed;
    this->actionPoints = speed;
}

State::~State() {}

Werewolf::Werewolf(const std::string& name, int hitPoints, int damage, int speed):
    Unit(name, hitPoints, damage, speed) {
        type = werewolf;
        ability = NULL;
        latentAbility = new WolfBite(this);
        currentState = State(name+"(Human)", hitPoints, damage, speed);
        alterState = State(name+"(Wolf)", hitPoints*2, damage*2, speed*2);
        this->name = currentState.name;
        this->hitPoints = currentState.hitPoints;
        this->hitPointsLimit = currentState.hitPoints;
        this->damage = currentState.damage;
        this->speed = currentState.speed;
        this->actionPoints = currentState.speed;
    }

Werewolf::~Werewolf() {}

void Werewolf::changeState() {
    State tmpState = currentState;
    Ability* tmpAbility = ability;
    int currentActionPoints = actionPoints;

    if ( actionPoints == 0 ) {
        throw NotEnoughActionPoints();
    }

    currentState.hitPoints = this->hitPoints;
    currentState = alterState;
    alterState = tmpState;

    ability = latentAbility;
    latentAbility = tmpAbility;

    this->name = currentState.name;
    this->hitPoints = currentState.hitPoints;
    this->hitPointsLimit = currentState.hitPointsLimit;
    this->damage = currentState.damage;
    this->speed = currentState.speed;
    this->actionPoints = currentActionPoints - 1;
}

void Werewolf::attack(Unit* enemy) {
    Unit::attack(enemy);
}