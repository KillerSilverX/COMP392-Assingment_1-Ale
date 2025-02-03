#ifndef QUEEN_H
#define QUEEN_H

#include "Warrior.h"

// Queen class, derived from Warrior. Queens have fixed attributes.
class Queen : public Warrior {
public:
    // Queen constructor: initializes with health=150, power=20, damagePower=25.
    Queen(int xPos, int yPos);
    
    virtual ~Queen();

    // Override getType() to return "Queen".
    virtual std::string getType() const override;
};

#endif
