#include "Queen.h"

Queen::Queen(int xPos, int yPos)
    : Warrior(150, 20, 25, xPos, yPos) {
}

Queen::~Queen() {
}

std::string Queen::getType() const {
    return "Queen";
}
