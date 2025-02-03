#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>

// Base Warrior class. Represents a generic warrior on the battlefield.
class Warrior {
protected:
    int health;        // Health points of the warrior.
    int power;         // Base power of the warrior.
    int damagePower;   // Damage dealt during an attack.
    int x;             // Warrior's x-coordinate on the grid.
    int y;             // Warrior's y-coordinate on the grid.
public:
    // Constructor initializes the warrior with given attributes and position.
    Warrior(int h, int p, int d, int xPos, int yPos);
    
    // Virtual destructor.
    virtual ~Warrior();

    // Moves the warrior randomly to one of the 8 adjacent cells (if possible).
    virtual void move(int gridSize);

    // Attacks an enemy warrior and returns the actual damage dealt.
    // Damage is calculated as: damagePower + (enemy.power - attacker.power)
    virtual int attack(Warrior* enemy);

    // Checks if the warrior is still alive.
    bool isAlive() const;

    // Pure virtual function to return the type of warrior (e.g., "Soldier" or "Queen").
    virtual std::string getType() const = 0;

    // Getters for the warrior's current position.
    int getX() const;
    int getY() const;

    // Sets a new position for the warrior.
    void setPosition(int newX, int newY);

    // Getter for the current health.
    int getHealth() const;

    // Getter for the base damage power (the predefined damage value).
    int getDamagePower() const;
    
    // Getter for the base power.
    int getPower() const;
};

#endif