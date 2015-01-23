#include "Gamefield.h"

int Gamefield::turn = 0;

Gamefield::Gamefield(const unsigned high, const unsigned width): high(high), width(width) {
    if ( width > MAXCOLS || high > MAXROWS ) {
        throw OutOfRange();
    }
    for ( int i = 0; i < high ; i++ ) {
        for ( int j = 0; j < width; j++ ) {
            locations.push_back(new Location(i,j));
        }
    }
    turnStrNumber = high * 2 + 3;
    unitStrNumber = turnStrNumber;
    infoStrNumber = turnStrNumber + 1;
    commandStrNumber = turnStrNumber + 2;
    currentLocation = locations[0];
    lastCommand = "";
    unitList = new std::set<Unit*>;
}

Gamefield::~Gamefield() {
    std::vector<Location*>::iterator it;
    std::set<Unit*>::iterator it1;

    for ( it = locations.begin(); it != locations.end(); it++ ) {
        delete *it;
    }
    for ( it1 = unitList->begin(); it1 != unitList->end(); it1++ ) {
        delete *it1;
    }
    delete &locations;
    delete unitList;
}

unsigned Gamefield::getWidth() const {
    return width;
}

unsigned Gamefield::getHigh() const {
    return high;
}

Unit* Gamefield::getOwner(const unsigned y, const unsigned x) const {
    return locations[y*width + x]->getOwner();
}

std::vector<Location*>& Gamefield::getLocations() {
    return locations;
}

Location* Gamefield::getCurrentLocation() const {
    return currentLocation;
}

Location* Gamefield::selectLocation(const unsigned y, const unsigned x) {
    return locations[y*width + x];
}

std::set<Unit*>* Gamefield::getUnitList() {
    return unitList;
}

void Gamefield::addUnit(Unit* newUnit) {
    std::vector<Location*>::iterator it;

    for ( it = locations.begin() ; (*it)->getOwner() != NULL; it++ ) {
        if ( it == locations.end() ) {
            throw NoFreeLocation();
        }
    }
    (*it)->addOwner(newUnit);
    newUnit->setLocation(*it);
    currentLocation = *it;
    addToList(newUnit);
    printLocation(currentLocation);
    printCurrentUnit();
}

void Gamefield::addUnit(Unit* newUnit, const unsigned y, const unsigned x) {
    int offset = y * width + x;
    
    if ( y > high - 1 || x > width - 1 ) {
        throw OutOfRange();
    }
    if ( locations[offset]->getOwner() == NULL ) {
        locations[offset]->addOwner(newUnit);
        newUnit->setLocation(locations[offset]);
        currentLocation = locations[offset];
        addToList(newUnit);
        printLocation(currentLocation);
        printCurrentUnit();
    } else {
        throw LocationAlreadyUsed();
    }
}

void Gamefield::deleteUnit(Unit* deletedUnit) {
    Location* dLocation = deletedUnit->getLocation();

    dLocation->removeOwner();
    unitList->erase(deletedUnit);
    printLocation(deletedUnit->getLocation());
    delete deletedUnit;
}

void Gamefield::moveCurrentUnit(Direction moveTo) {
    Unit* currentUnit = currentLocation->getOwner();

    if ( currentLocation->is_free() ) {
        printInfo("No units on the field. Add unit, please!");
    } else {
        try {
            moveUnit(currentUnit, moveTo);
        } catch (NotEnoughActionPoints) {
            printInfo("Not enough action point to move this unit!");
        } catch (LocationAlreadyUsed) {
            printInfo("This location already used!");
        }
    }
}

void Gamefield::moveUnit(Unit* movedUnit, Direction moveTo) {
    int actionPoints = movedUnit->getActionPoints();
    if ( actionPoints == 0 ) {
        throw NotEnoughActionPoints();
    }
    Location* locationFrom = movedUnit->getLocation();
    Location* locationTo;
    unsigned curY = locationFrom->getY();
    unsigned curX = locationFrom->getX();
    unsigned lastRow = high - 1;
    unsigned lastColumn = width - 1;

    switch (moveTo) {
        case up:
            if ( curY != 0 ) {
                curY -= 1;
            } else {
                curY = lastRow;
            }
            break;
        case down:
            if ( curY != lastRow ) {
                curY += 1;
            } else {
                curY = 0;
            }
            break;
        case left:
            if ( curX != 0 ) {
                curX -= 1;
            } else {
                curX = lastColumn;
            }
            break;
        case right:
            if ( curX != lastColumn ) {
                curX += 1;
            } else {
                curX = 0;
            }
    }
    locationTo = selectLocation(curY, curX);
    if ( locationTo->is_free() ) {
        currentLocation = locationTo;
        movedUnit->setActionPoints(actionPoints - 1);
        locationFrom->removeOwner();
        printLocation(locationFrom);
        locationTo->addOwner(movedUnit);
        printLocation(locationTo);
        printCurrentUnit();
    } else {
        throw LocationAlreadyUsed();
    }
}

void Gamefield::addToList(Unit* addedUnit) {
    unitList->insert(addedUnit);
}

void Gamefield::newTurn() {
    std::set<Unit*>::iterator it;

    for ( it = unitList->begin(); it != unitList->end(); it++ ) {
        (*it)->setActionPoints((*it)->getSpeed());
    }
    turn += 1;
    printCurrentUnit();
    printTurn();
}

void Gamefield::nextUnit() {
    std::set<Unit*>::iterator it;
    if ( !unitList->empty() ) {
        it = unitList->find(currentLocation->getOwner());
        it++;
        if ( it == unitList->end() ) {
            it = unitList->begin();
        }
        currentLocation = (*it)->getLocation();
        printLocation(currentLocation);
        printCurrentUnit();
    } else {
        printInfo("No units on the field. Add unit, please!");
    }
}

void Gamefield::draw() {
    std::string divideLine, cellLine, rLine;
    std::string dLine = "+";
    std::string cLine = "|";

    clearScreen();

    dLine.append(CELLSIZE, '-');
    cLine.append(CELLSIZE, ' ');
    std::cout << "     ";
    for ( int i = 0; i < width; i++ ) {
        rLine.append(CELLSIZE - iToStr(i).length() + 1, ' ');
        std::cout << i << rLine;
        divideLine += dLine;
        cellLine += cLine;
        rLine = "";
    }
    std::cout << std::endl;
    divideLine += "+";
    cellLine += "|";

    for ( int i = 0; i < high; i++ ) {
        std::cout << "   " << divideLine << std::endl;
        rLine = " " + iToStr(i) + " ";
        std::cout << rLine.substr(iToStr(i).length()-1, 3) << cellLine << std::endl;
    }
    std::cout << "   " << divideLine << std::endl;
    std::cout << " Turn: 0   Current unit: <none>" << std::endl;
    std::cout << " Info: " << std::endl;
    std::cout << " Command: " << std::endl;
}

void Gamefield::printTurn() {
    goToXY(turnStrNumber, 8);
    std::cout << turn;
}

void Gamefield::printCurrentUnit() {
    goToXY(unitStrNumber, 26);
    clearString();
    std::cout << *(currentLocation->getOwner());
}

void Gamefield::printInfo(std::string infoStr) {
    goToXY(infoStrNumber, 8);
    clearString();
    std::cout << infoStr;
}

void Gamefield::getCommand() {
    char* token;
    int x, y;
    std::string cmd[4];
    std::string command;
    std::string type = "";
    std::string index = "";
    Unit* newUnit = NULL;
    Unit* currentUnit;
    Unit* underAttack = NULL;
    Location* cLocation;
    Location* toAttack = NULL;

    goToXY(commandStrNumber, 11);
    for ( command = ""; command != "quit"; ) {
        saveCursorPosition();
        cLocation = getCurrentLocation();
        currentUnit = cLocation->getOwner();
        std::getline(std::cin, lastCommand);
        strToLower(lastCommand);
        printInfo("");
        char* cstr = new char[lastCommand.length()+1];
        std::strcpy(cstr, lastCommand.c_str());

        token = std::strtok(cstr, " ,.-;:()<>");
        for ( int i = 0; token != NULL && i < 4; i++ ) {
            cmd[i] = token;
            token = std::strtok(NULL, " ,.-;:()<>");
        }
        delete cstr;
        
        command = cmd[0];
        type = cmd[1];
        index = cmd[2];
        if ( command == "quit" ) {
            printInfo("Game over...");
        } else if ( command == "add" && type.length() > 0 ) {
            if ( type == "berserker" ) {
                newUnit = new Berserker();
            } else if ( type == "rogue" ) {
                newUnit = new Rogue();
            } else if ( type == "soldier" ) {
                newUnit = new Soldier();
            } else if ( type == "vampire" ) {
                newUnit = new Vampire();
            } else if ( type == "werewolf" ) {
                newUnit = new Werewolf();
            } else if ( type == "healer" ) {
                newUnit = new Healer();
            } else if ( type == "necromancer" ) {
                newUnit = new Necromancer();
            } else if ( type == "priest" ) {
                newUnit = new Priest();
            } else if ( type == "warlock" ) {
                newUnit = new Warlock();
            } else if ( type == "priest" ) {
                newUnit = new Priest();
            } else if ( type == "wizard" ) {
                newUnit = new Wizard();
            } else {
                newUnit = NULL;
            }
            if ( newUnit != NULL ) {
                addUnit(newUnit);
            } else {
                printInfo("Type '" + type + "' not supported. Enter valid type!" );
            }
            
        } else if ( command == "up" ) {
            moveCurrentUnit(up);
        } else if ( command == "down" ) {
            moveCurrentUnit(down);
        } else if ( command == "left" ) {
            moveCurrentUnit(left);
        } else if ( command == "right" ) {
            moveCurrentUnit(right);
        } else if ( command == "delete" ) {
            if ( currentUnit != NULL ) {
                nextUnit();
                deleteUnit(currentUnit);
            } else {
                printInfo("No unit in current location!");
            }
        } else if ( command == "attack" ) {
            std::sscanf(type.c_str(), "%d", &y);
            std::sscanf(index.c_str(), "%d", &x);
            if ( y > MAXROWS || x > MAXCOLS ) {
                printInfo("Coordinates out of range");
            } else if ( y == cLocation->getY() && x == cLocation->getX() ) {
                printInfo("Suicide mode disabled in this game!");
            } else if ( inAttackedArea(y, x) ) {
                toAttack = selectLocation(y, x);
                underAttack = toAttack->getOwner();
                if ( underAttack != NULL ) {
                    currentUnit->attack(toAttack->getOwner());
                    printInfo(underAttack->getName() + " was attacked!");
                } else {
                    printInfo("No unit in this location: (" + type + ", " + index + ")");
                }
            } else {
                printInfo("Location (" + type + ", " + index + ") not in attacked area!");
            }
        } else if ( command == "next" ) {
            if ( type == "turn" ) {
                newTurn();
            } else if ( type == "unit" ) {
                nextUnit();
            } else {
                printInfo("Wrong command - " + lastCommand);
            }
        } else {
            printInfo("Wrong command - " + lastCommand);
        }
        
        restoreCursorPosition();
        clearString();
        cmd[0] = cmd[1] = cmd[2] = cmd[3] = "";
    }
}

void Gamefield::printLocation(Location* printedLocation) {
    int x = (CELLSIZE + 1) * printedLocation->getX() + 5;
    int y = 2 * printedLocation->getY() + 3;
    Unit* owner = printedLocation->getOwner();
    std::string outStr = " ";

    if ( printedLocation->is_free() ) {
        outStr.append(CELLSIZE - 1, ' ');
    } else {
        outStr.append(owner->getName().substr(0,2));
    }
    goToXY(y, x);
    std::cout << outStr;
}

void Gamefield::printLocations() {
    std::vector<Location*>::iterator it = locations.begin();

    for ( ; it != locations.end(); it++ ) {
        printLocation(*it);
    }
}

void Gamefield::clearScreen() const {
    std::cout << ESC << "[2J";
}


void Gamefield::clearString() const {
    std::cout << ESC << "[K";
}

void Gamefield::saveCursorPosition() const {
    std::cout << ESC << "[s";
}

void Gamefield::restoreCursorPosition() const {
    std::cout << ESC << "[u";
}

void Gamefield::goToXY(const unsigned y, const unsigned x) {
    std::cout << ESC << '[' << iToStr(y) << ';' << iToStr(x) <<  'H';
}

void Gamefield::printColorStr(std::string str, Color clr) const {

}

std::string Gamefield::iToStr(int value) {
    std::string retString;
    char cDigit;
    
    if ( value == 0 ) {
        return "0";
    }
    for ( ; value > 0; value /= 10 ) {
        cDigit = '0' + value % 10;
        retString = cDigit + retString;
    }
    return retString;
}

void Gamefield::strToLower(std::string& convertedStr) {
    for ( int i = 0; i < convertedStr.length(); i++ ) {
        convertedStr[i] = std::tolower(convertedStr[i]);
    }
}

bool Gamefield::inAttackedArea(int y, int x) const {
    Unit* currentUnit = currentLocation->getOwner();
    int deltaX = x - currentLocation->getX();
    int deltaY = y - currentLocation->getY();

    if ( deltaX < 0 ) {
        deltaX *= -1;
    }
    if ( deltaY < 0 ) {
        deltaY *= -1;
    }

    if ( deltaX + deltaY > currentUnit->getAttackDistance() ) {
        return false;
    }
    return true;
}