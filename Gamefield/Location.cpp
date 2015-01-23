#include "Location.h"

Location::Location(int y, int x): y(y), x(x) {
    owner = NULL;
}

Location::~Location() {
    if ( owner != NULL ) {
        delete owner;
    }
}

int Location::getX() const {
    return x;
}

int Location::getY() const {
    return y;
}

Unit* Location::getOwner() const {
    return owner;
}

bool Location::is_free() const {
    return owner == NULL;
}

void Location::addOwner(Unit* newOwner) {
    owner = newOwner;
    newOwner->setLocation(this);
}

void Location::removeOwner() {
    owner = NULL;
}

int Location::distance(const Location& other) {
    int distX = this->x - other.x;
    int distY = this->y - other.y;

    if ( distX < 0 ) {
        distX *= -1;
    }
    if ( distY < 0 ) {
        distY *= -1;
    }
    return distX + distY;
}

bool Location::operator==(const Location& other) {
    return this->x == other.x && this->y == other.y;
}

bool Location::operator!=(const Location& other) {
    return this->x != other.x || this->y != other.y;
}

std::ostream& operator<<(std::ostream& out, const Location& loc) {
    // Unit* currentOwner = loc.getOwner();

    out << "(" << loc.getY() << ", " << loc.getX() << ")";
    // if ( currentOwner == NULL ) {
        // out << "<none>";
    // } else {
        // out << *currentOwner;
    // }
    return out;
}