#include "BattleSimulator.h"
#include "Soldier.h"
#include "Queen.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

BattleSimulator::BattleSimulator(int gridSize, int numSoldiers, int numQueens)
    : gridSize(gridSize), numSoldiers(numSoldiers), numQueens(numQueens)
{
    // Initialize the grid with nullptr (empty cells).
    grid.resize(gridSize, std::vector<Warrior*>(gridSize, nullptr));
    teamA = new Team("Team A");
    teamB = new Team("Team B");
    
    // Seed the random number generator.
    srand(static_cast<unsigned int>(time(0)));
}

BattleSimulator::~BattleSimulator() {
    delete teamA;
    delete teamB;
}

void BattleSimulator::initializeBattle() {
    int x, y;
    // Place warriors for Team A.
    for (int i = 0; i < numSoldiers; i++) {
        // Find a free random position.
        do {
            x = rand() % gridSize;
            y = rand() % gridSize;
        } while (grid[x][y] != nullptr);
        Warrior* soldier = new Soldier(x, y);
        teamA->addWarrior(soldier);
        grid[x][y] = soldier;
    }
    for (int i = 0; i < numQueens; i++) {
        do {
            x = rand() % gridSize;
            y = rand() % gridSize;
        } while (grid[x][y] != nullptr);
        Warrior* queen = new Queen(x, y);
        teamA->addWarrior(queen);
        grid[x][y] = queen;
    }
    // Place warriors for Team B.
    for (int i = 0; i < numSoldiers; i++) {
        do {
            x = rand() % gridSize;
            y = rand() % gridSize;
        } while (grid[x][y] != nullptr);
        Warrior* soldier = new Soldier(x, y);
        teamB->addWarrior(soldier);
        grid[x][y] = soldier;
    }
    for (int i = 0; i < numQueens; i++) {
        do {
            x = rand() % gridSize;
            y = rand() % gridSize;
        } while (grid[x][y] != nullptr);
        Warrior* queen = new Queen(x, y);
        teamB->addWarrior(queen);
        grid[x][y] = queen;
    }
}

void BattleSimulator::simulateBattle() {
    int round = 1;
    std::cout << "Welcome to the Battle Simulator!" << std::endl;
    std::cout << teamA->getName() << " and " << teamB->getName() << " are about to fight..." << std::endl;
    std::cout << std::endl;
    
    // Continue simulation until one team is defeated.
    while (teamA->isTeamAlive() && teamB->isTeamAlive()) {
        std::cout << "Round " << round << ":" << std::endl;
        
        // Move warriors for both teams.
        teamA->moveWarriors(gridSize, grid);
        teamB->moveWarriors(gridSize, grid);
        std::cout << std::endl;
        
        // Team A attacks Team B.
        teamA->attackOpponent(*teamB);
        std::cout << std::endl;
        // Team B attacks Team A.
        teamB->attackOpponent(*teamA);
        std::cout << std::endl;
        
        // Print current status.
        printStatus();
        std::cout << "------------------------------------------------------" << std::endl;
        
        // Check for victory.
        if (!teamA->isTeamAlive() || !teamB->isTeamAlive()) {
            break;
        }
        round++;
    }
    
    // Declare the winner.
    if (teamA->isTeamAlive() && !teamB->isTeamAlive()) {
        std::cout << teamA->getName() << " wins the battle!" << std::endl;
    } else if (!teamA->isTeamAlive() && teamB->isTeamAlive()) {
        std::cout << teamB->getName() << " wins the battle!" << std::endl;
    } else {
        std::cout << "The battle ended in a draw!" << std::endl;
    }
}

void BattleSimulator::printStatus() const {
    // Print status for Team A.
    std::cout << teamA->getName() << " Status:" << std::endl;
    const std::vector<Warrior*>& warriorsA = teamA->getWarriors();
    for (const Warrior* warrior : warriorsA) {
        std::cout << "  Warrior (" << warrior->getType() << ") at ("
                  << warrior->getX() << ", " << warrior->getY() << ") - Health: "
                  << warrior->getHealth() << std::endl;
    }
    // Print status for Team B.
    std::cout << teamB->getName() << " Status:" << std::endl;
    const std::vector<Warrior*>& warriorsB = teamB->getWarriors();
    for (const Warrior* warrior : warriorsB) {
        std::cout << "  Warrior (" << warrior->getType() << ") at ("
                  << warrior->getX() << ", " << warrior->getY() << ") - Health: "
                  << warrior->getHealth() << std::endl;
    }
}