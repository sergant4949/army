#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include "../Units/Unit.h"

class Unit;

class Location {
    private:
        int y;
        int x;
        Unit* owner;

    public:
        Location(int y, int x);
        ~Location();

        int getX() const;
        int getY() const;
        Unit* getOwner() const;
        bool is_free() const;

        void addOwner(Unit* newOwner);
        void removeOwner();

        int distance(const Location& other);
        bool operator==(const Location& other);
        bool operator!=(const Location& other);
};

std::ostream& operator<<(std::ostream& out, const Location& loc);

#endif // LOCATION_H