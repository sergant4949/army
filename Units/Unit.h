#ifndef UNIT_H
#define UNIT_H

#include <iostream>

#include "../exceptions.h"
#include "../Interfaces/Interface.h"
#include "../Abilities/Ability.h"
#include "../Gamefield/Location.h"

enum UnitType {
    berserker,
    demon,
    healer,
    necromancer,
    priest,
    rogue,
    soldier,
    vampire,
    warlock,
    werewolf,
    wizard
};

class Ability;
class Location;

class Unit : public Observer, public Observable {
    protected:
        int hitPoints;
        int hitPointsLimit;
        int damage;
        std::string name;
        int speed;
        int actionPoints;
        Ability* ability;
        UnitType type;
        Location* location;
        int attackDistance;
        
        void ensureIsAlive();
    public:
        Unit(const std::string& name, int hitPoints, int damage, int speed, int attackDistance = 1);
        virtual ~Unit();

        int getHitPoints() const;
        int getHitPointsLimit() const;
        int getDamage() const;
        int getSpeed() const;
        int getActionPoints() const;

        static std::set<Unit*>* getUnitList();

        std::string getName() const;
        Ability& getAbility() const;
        UnitType getType() const;
        Location* getLocation() const;
        int getAttackDistance() const;

        void setAbility(Ability* ability);
        void addHitPoints(int hp);
        void setActionPoints(int ap);
        void changeName(std::string newName);
        virtual void takeDamage(int dmg);
        virtual void takeMagicDamage(int dmg);
        void setLocation(Location* newLocation);

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);

        virtual void notify();
        virtual void sendNotification();
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif //UNIT_H
