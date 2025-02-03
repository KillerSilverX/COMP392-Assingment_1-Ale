# Battle Simulator - Assignment 1

## 📌 Student Information
**📝 Student Name:** Ale Pintado Munoz  
**🆔 Student Number:** 301207313  
**📚 Course:** COMP392 Advanced Graphics (SEC. 001) Winter 2025  

---

## 🎯 Introduction
### Hi Professor,
This is my submission for **Assignment 1**. I’ve implemented the **Battle Simulator** as requested.

I wasn't quite sure what the difference was between `power` and `damagePower`, so I tried to make sense of it by using `power` as a modifier that affects the final damage output.  
In my implementation, the actual damage dealt during an attack is calculated as:

```cpp
actualDamage = damagePower + (enemy.power - attacker.power);
```

This means that `damagePower` serves as the **base damage value**, while `power` adjusts that base value depending on the relative strength of the **attacker** and the **enemy**.  
For instance:
- A **Soldier** has a `damagePower` of **15** and a `power` of **10**.
- A **Queen** has a `power` of **20**.

So, when a **Soldier attacks a Queen**, the calculation becomes:
```cpp
15 + (20 - 10) = 25 damage
```
Conversely, when a **Queen attacks a Soldier**, the calculation would lower the damage accordingly.  
This approach gives both attributes a **clear role in the combat mechanics**.

I hope you find everything in order. Thanks! 😊

---

## 📂 Files Included
```
📁 Battle Simulator
│── Warrior.h / Warrior.cpp                 # Base class for all warriors
│── Soldier.h / Soldier.cpp                 # Soldier class
│── Queen.h / Queen.cpp                     # Queen class
│── Team.h / Team.cpp                       # Manages a team of warriors
│── BattleSimulator.h / BattleSimulator.cpp # Handles the game logic and grid management
│── main.cpp                                # The main file where the program starts
│── README.md                               # This file
│── Battle Simulator Precompiled            # Folder containing the precompiled executable
```

---

## ⚙️ Compilation Instructions
You can compile this program using **g++** from the command line. Make sure that **g++** is installed on your system and its directory is added to your `PATH`.

### On **Windows** using CMD:
```sh
# Open a CMD window
cd "D:\COMP392\Assignment 1"

# Compile the program
g++ -o BattleSimulator main.cpp Warrior.cpp Soldier.cpp Queen.cpp Team.cpp BattleSimulator.cpp

# Run the program
BattleSimulator.exe
```

If you have any trouble compiling, a **precompiled executable** is available in the `Battle Simulator Precompiled` folder.

---

## ▶️ Running the Program
When running the executable by **double-clicking**, the console window may open and close immediately.  
To keep the window open and see the output, open a **CMD** or **terminal** in the directory where `BattleSimulator.exe` is located and **run it from there**:
```sh
cd "D:\COMP392\Assignment 1"
BattleSimulator.exe
```

---

## 🔧 Note
- You can tweak the **grid size** and the **number of warriors** by modifying `main.cpp` or the `BattleSimulator.cpp` constructor.

---

## Thanks :)

