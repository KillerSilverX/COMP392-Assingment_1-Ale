#include "Warrior.h"
#include <cstdlib>
#include <iostream>

Warrior::Warrior(int h, int p, int d, int xPos, int yPos)
    : health(h), power(p), damagePower(d), x(xPos), y(yPos) {
}

Warrior::~Warrior() {
}

void Warrior::move(int gridSize) {
    // Generate a random move: dx and dy in the range [-1, 1]
    int dx = (rand() % 3) - 1;
    int dy = (rand() % 3) - 1;
    int newX = x + dx;
    int newY = y + dy;
    
    // Ensure the new position is within grid boundaries.
    if(newX >= 0 && newX < gridSize && newY >= 0 && newY < gridSize) {
        x = newX;
        y = newY;
    }
}

int Warrior::attack(Warrior* enemy) {
    if (enemy != nullptr && enemy->isAlive()) {
        // Calculate the actual damage:
        int actualDamage = damagePower + (enemy->power - this->power);
        // Prevent negative damage.
        if(actualDamage < 0) {
            actualDamage = 0;
        }
        enemy->health -= actualDamage;
        if(enemy->health < 0) {
            enemy->health = 0;
        }
        return actualDamage;
    }
    return 0;
}

bool Warrior::isAlive() const {
    return health > 0;
}

int Warrior::getX() const {
    return x;
}

int Warrior::getY() const {
    return y;
}

void Warrior::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

int Warrior::getHealth() const {
    return health;
}

int Warrior::getDamagePower() const {
    return damagePower;
}

int Warrior::getPower() const {
    return power;
}