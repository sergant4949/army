# army
Small game for testing RPG classes.

Working on *nix console (for cursor positioning was used ANSI sequences).
Uses management from the command line.

Commands:
quit - exit from game
add <unit> - add specified unit, e.g. "add soldier", "add vampire" etc.
delete <unit> - delete specified unit.
up - move current unit to next location up.
down - ...down.
right - ...right.
left - ...left.
next unit - change current unit to next
attack <y,x> - attack unit in location y,x
next turn - end current turn (all units refresh its action points)
