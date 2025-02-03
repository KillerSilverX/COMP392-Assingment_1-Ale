#include "Soldier.h"

Soldier::Soldier(int xPos, int yPos)
    : Warrior(100, 10, 15, xPos, yPos) {
}

Soldier::~Soldier() {
}

std::string Soldier::getType() const {
    return "Soldier";
}