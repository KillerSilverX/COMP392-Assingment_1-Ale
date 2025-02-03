#include "BattleSimulator.h"

int main() {
    // Create a BattleSimulator with a 10x10 grid,
    // 2 Soldiers and 1 Queen per team (you can modify these values as needed).
    BattleSimulator simulator(10, 2, 1);
    
    // Initialize the battle (teams and initial positions).
    simulator.initializeBattle();
    
    // Start the simulation.
    simulator.simulateBattle();
    
    return 0;
}