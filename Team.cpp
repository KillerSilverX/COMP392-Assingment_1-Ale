#include "Team.h"
#include <iostream>
#include <cstdlib>
#include <vector>

Team::Team(const std::string& teamName)
    : name(teamName) {
}

Team::~Team() {
    // Delete all allocated warriors.
    for (Warrior* warrior : warriors) {
        delete warrior;
    }
    warriors.clear();
}

void Team::addWarrior(Warrior* warrior) {
    warriors.push_back(warrior);
}

void Team::attackOpponent(Team &opponent) {
    // Each alive warrior in this team attacks one random alive enemy.
    for (Warrior* warrior : warriors) {
        if (warrior->isAlive()) {
            // Build a list of alive enemy warriors.
            std::vector<Warrior*> aliveEnemies;
            const std::vector<Warrior*>& enemyWarriors = opponent.getWarriors();
            for (Warrior* enemy : enemyWarriors) {
                if (enemy->isAlive()) {
                    aliveEnemies.push_back(enemy);
                }
            }
            if (aliveEnemies.empty()) {
                // No enemies alive.
                break;
            }
            // Select a random enemy.
            int index = rand() % aliveEnemies.size();
            Warrior* target = aliveEnemies[index];

            // Attack and capture the actual damage inflicted.
            int damageDealt = warrior->attack(target);

            // Print attack information.
            std::cout << name << " Warrior (" << warrior->getType() << ") at ("
                      << warrior->getX() << ", " << warrior->getY() << ") attacks "
                      << opponent.getName() << " Warrior (" << target->getType() << ") at ("
                      << target->getX() << ", " << target->getY() << ") for "
                      << damageDealt << " damage." << std::endl;
            
            // Print target status.
            if (target->isAlive()) {
                std::cout << opponent.getName() << " Warrior (" << target->getType() << ") is still alive with "
                          << target->getHealth() << " health." << std::endl;
            } else {
                std::cout << opponent.getName() << " Warrior (" << target->getType() << ") has been defeated." << std::endl;
            }
        }
    }
}

bool Team::isTeamAlive() const {
    for (Warrior* warrior : warriors) {
        if (warrior->isAlive()) {
            return true;
        }
    }
    return false;
}

std::string Team::getName() const {
    return name;
}

const std::vector<Warrior*>& Team::getWarriors() const {
    return warriors;
}

void Team::moveWarriors(int gridSize, std::vector<std::vector<Warrior*>>& grid) {
    // For each alive warrior, try to move to one of the 8 adjacent free cells.
    for (Warrior* warrior : warriors) {
        if (!warrior->isAlive())
            continue; // Dead warriors do not move.
        
        int currentX = warrior->getX();
        int currentY = warrior->getY();
        
        // Compute all possible adjacent moves.
        std::vector<std::pair<int, int>> possibleMoves;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if(dx == 0 && dy == 0)
                    continue;
                int newX = currentX + dx;
                int newY = currentY + dy;
                // Check boundaries.
                if (newX >= 0 && newX < gridSize && newY >= 0 && newY < gridSize) {
                    // Check if the cell is free.
                    if (grid[newX][newY] == nullptr) {
                        possibleMoves.push_back(std::make_pair(newX, newY));
                    }
                }
            }
        }
        if (!possibleMoves.empty()) {
            // Choose a random free adjacent cell.
            int index = rand() % possibleMoves.size();
            int newX = possibleMoves[index].first;
            int newY = possibleMoves[index].second;
            // Update the grid: free the old cell and occupy the new cell.
            grid[currentX][currentY] = nullptr;
            grid[newX][newY] = warrior;
            warrior->setPosition(newX, newY);
            std::cout << name << " Warrior (" << warrior->getType() << ") moved from ("
                      << currentX << ", " << currentY << ") to ("
                      << newX << ", " << newY << ")." << std::endl;
        } else {
            std::cout << name << " Warrior (" << warrior->getType() << ") at ("
                      << currentX << ", " << currentY << ") could not move." << std::endl;
        }
    }
}