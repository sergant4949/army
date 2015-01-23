#include "Unit.h"

Unit::Unit(const std::string& name, int hitPoints, int damage, int speed, int attackDistance) {
    this->name = name;
    this->hitPoints = hitPoints;
    this->hitPointsLimit = hitPoints;
    this->damage = damage;
    this->speed = speed;
    actionPoints = speed;
    ability = NULL;
    this->attackDistance = attackDistance;
}

Unit::~Unit() {
    if ( ability != NULL ) {
        delete ability;
    }
}

void Unit::ensureIsAlive() {
    if ( hitPoints == 0 ) {
        throw DeadUnitException();
    }
}

int Unit::getHitPoints() const {
    return hitPoints;
}

int Unit::getHitPointsLimit() const {
    return hitPointsLimit;
}

int Unit::getDamage() const {
    return damage;
}

std::string Unit::getName() const {
    return name;
}

int Unit::getSpeed() const {
    return speed;
}

int Unit::getActionPoints() const {
    return actionPoints;
}

Ability& Unit::getAbility() const {
    return *ability;
}

UnitType Unit::getType() const {
    return type;
}

Location* Unit::getLocation() const {
    return location;
}

int Unit::getAttackDistance() const {
    return attackDistance;
}

void Unit::setAbility(Ability* newAbility) {
    ability = newAbility;
}

void Unit::setLocation(Location* newLocation) {
    location = newLocation;
}

void Unit::changeName(std::string newName) {
    name = newName;
}

void Unit::setActionPoints(int ap) {
    actionPoints = ap;
}

void Unit::addHitPoints(int hp) {
    ensureIsAlive();
    int total = hp + hitPoints;
    
    std::cout << "Hit points: " << hitPoints << ", added " << hp << std::endl;
    if ( total > hitPointsLimit ) {
        hitPoints = hitPointsLimit;
        return;
    }
    hitPoints = total;
}

void Unit::takeDamage(int dmg) {
    ensureIsAlive();
    if ( dmg >= hitPoints ) {
        notify();
        hitPoints = 0;
        return;
    }
    hitPoints -= dmg;
}

void Unit::takeMagicDamage(int dmg) {
    takeDamage(dmg);
}

void Unit::attack(Unit* enemy) {
    if ( actionPoints == 0 ) {
        throw NotEnoughActionPoints();
    }
    // infoMessage();
    actionPoints -= 1;
    enemy->takeDamage(damage);
    if ( ability != NULL ) {
        ability->action(enemy);
    }
    enemy->counterAttack(this);
}

void Unit::counterAttack(Unit* enemy) {
    if ( actionPoints != 0 ) {
        actionPoints -= 1;
        enemy->takeDamage(damage/2);
    }
}

void Unit::notify() {
    std::set<Observer*>::iterator it = observers.begin();

    for ( ; it != observers.end(); it++ ) {
        ((Unit*)(*it))->addHitPoints(hitPointsLimit/10);
        (*it)->removeObservable(this);
    }
}

void Unit::sendNotification() {
    std::set<Observable*>::iterator it = observables.begin();

    for ( ; it != observables.end(); it++ ) {
        (*it)->removeObserver(this);
    }
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    if ( &unit != NULL ) {
        out << unit.getName() << " " << *(unit.getLocation()) << " [ hp: ";
        out << unit.getHitPoints() << "/" << unit.getHitPointsLimit();
        out << " dmg: " << unit.getDamage();
        out << " act: " << unit.getActionPoints() <<  "/" << unit.getSpeed() << " ]";
    } else {
        out << "<none>";
    }
    return out;
}
