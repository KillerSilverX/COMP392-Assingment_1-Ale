#ifndef BATTLE_SIMULATOR_H
#define BATTLE_SIMULATOR_H

#include "Team.h"
#include <vector>

// BattleSimulator class handles the overall game logic.
class BattleSimulator {
private:
    Team* teamA;    // Pointer to Team A.
    Team* teamB;    // Pointer to Team B.
    int gridSize;   // Size of the grid (e.g., 10 for a 10x10 grid).

    // 2D grid representing the battlefield.
    // Each cell points to the Warrior occupying it, or is nullptr if free.
    std::vector<std::vector<Warrior*>> grid;

    // Number of warriors per type per team.
    int numSoldiers;
    int numQueens;
public:
    // Constructor sets grid size and number of warriors.
    BattleSimulator(int gridSize, int numSoldiers, int numQueens);
    
    // Destructor cleans up allocated memory.
    ~BattleSimulator();

    // Initializes the teams and places warriors randomly on the grid.
    void initializeBattle();

    // Runs the simulation of battle rounds until one team is defeated.
    void simulateBattle();

    // Prints the current status (health and position) of all warriors.
    void printStatus() const;
};

#endif