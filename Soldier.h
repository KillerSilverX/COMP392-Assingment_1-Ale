#ifndef SOLDIER_H
#define SOLDIER_H

#include "Warrior.h"

// Soldier class, derived from Warrior. Soldiers have fixed attributes.
class Soldier : public Warrior {
public:
    // Soldier constructor: initializes with health=100, power=10, damagePower=15.
    Soldier(int xPos, int yPos);
    
    virtual ~Soldier();

    // Override getType() to return "Soldier".
    virtual std::string getType() const override;
};

#endif