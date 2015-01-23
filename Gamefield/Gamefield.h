#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#define MAXWIDTH 80
#define MAXHIGH  25
#define CELLSIZE 4
#define MAXCOLS  (MAXWIDTH-5)/(CELLSIZE+1)
#define MAXROWS  (MAXHIGH-5)/2

#define ESC      '\x1B'

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cctype>
#include "Location.h"
#include "../Units/Unit.h"
#include "../Units/SpellCasters/Wizard.h"
#include "../Units/SpellCasters/Healer.h"
#include "../Units/SpellCasters/Priest.h"
#include "../Units/SpellCasters/Warlock.h"
#include "../Units/SpellCasters/Necromancer.h"
#include "../Units/Warriors/Berserker.h"
#include "../Units/Warriors/Rogue.h"
#include "../Units/Warriors/Soldier.h"
#include "../Units/Warriors/Vampire.h"
#include "../Units/Warriors/Werewolf.h"
#include "../exceptions.h"

enum Direction {
    up,
    down,
    left,
    right
};

enum Color {
    red,
    yellow,
    green,
    blue,
    white
};

class Gamefield {
    private:
        unsigned width;
        unsigned high;

        unsigned turnStrNumber;
        unsigned commandStrNumber;
        unsigned unitStrNumber;
        unsigned infoStrNumber;
        static int turn;

        std::string lastCommand;

        std::vector<Location*> locations;
        Location* currentLocation;
        std::set<Unit*>* unitList;

    public:
        Gamefield(const unsigned high, const unsigned width);
        ~Gamefield();

        unsigned getWidth() const;
        unsigned getHigh() const;
        Unit* getOwner(const unsigned y, const unsigned x) const;
        std::vector<Location*>& getLocations();
        Location* getCurrentLocation() const;
        std::set<Unit*>* getUnitList();

        Location* selectLocation(const unsigned y, const unsigned x);
        void addUnit(Unit* newUnit);
        void addUnit(Unit* newUnit, const unsigned y, const unsigned x);
        void deleteUnit(Unit* deletedUnit);
        void moveCurrentUnit(Direction moveTo);
        void moveUnit(Unit* movedUnit, Direction moveTo);
        void addToList(Unit* addedUnit);
        void newTurn();
        void nextUnit();
        bool inAttackedArea(int y, int x) const;

        void draw();
        void clearScreen() const;
        void clearString() const;
        void saveCursorPosition() const;
        void restoreCursorPosition() const;
        void printLocations();
        void printTurn();
        void printCurrentUnit();
        void printLocation(Location* printedLocation);
        void printInfo(std::string infoStr);
        void getCommand();
        void goToXY(const unsigned y, const unsigned x);
        void printColorStr(std::string str, Color clr) const;
        std::string iToStr(int value);
        void strToLower(std::string& convertedStr);

};

#endif // GAMEFIELD_H