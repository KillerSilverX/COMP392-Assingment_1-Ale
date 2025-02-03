#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include <string>
#include "Warrior.h"

// Team class represents a team of warriors.
class Team {
private:
    std::vector<Warrior*> warriors; // List of warriors in the team.
    std::string name;               // Team name (e.g., "Team A" or "Team B").
public:
    // Constructor sets the team name.
    Team(const std::string& teamName);
    
    // Destructor frees memory allocated for warriors.
    ~Team();

    // Adds a warrior to the team.
    void addWarrior(Warrior* warrior);

    // Each warrior in the team attacks a random enemy from the opponent team.
    void attackOpponent(Team &opponent);

    // Moves all warriors in the team on the grid.
    void moveWarriors(int gridSize, std::vector<std::vector<Warrior*>>& grid);

    // Checks if at least one warrior in the team is alive.
    bool isTeamAlive() const;

    // Returns the team name.
    std::string getName() const;

    // Returns a constant reference to the vector of warriors.
    const std::vector<Warrior*>& getWarriors() const;
};

#endif