# Orinoco: 2D Grid-Based Game (C++)

Orinoco is a grid-based C++ game featuring coin collection, obstacles, power-ups/downs, and multi-level progression with a random level generator. (Daily level reset in progress)

## How It's Made:
### Tech Used: C++
Orinoco was built as a simple C++ two level 2D grid-based game with some power-ups. However, over time more features were added to make the game more enjoyable and challenging.
It uses a player, coin, power-up, and power-up "remover" classes that all work together to form one game. As the player progresses the grid size increases, coin collection count increases,
and obstacles get in the player's way to make it more challenging. The game has been tested multiple times so it's guaranteed the player always has a way to win. The main objective is to 
collect the coins as fast as possible.

## Features
- Grid-Based Movement System: Navigate the player across a 2D grid using real-time keyboard input.
- Coin Collection Mechanics :Each level requires collecting all coins to progress, with coin counts increasing over time.
- Dynamic Obstacles: Power-up removers and restricted grid placements introduce strategic challenges and force players to plan efficient paths.
- Power-Ups & Power-Downs :Temporary effects such as movement speed boosts and removals add risk–reward decisions to gameplay.
- Multi-Level Progression :Four handcrafted levels featuring increasing grid sizes, coin counts, and difficulty.
- Random Level Generator :Generates unpredictable levels within predefined constraints while guaranteeing at least one solvable path.
- Timer-Based Scoring :Tracks how quickly the player completes each level, encouraging optimization and replayability.
- Fail-Safe Level Design: All levels are validated to ensure the player can always reach the objective.
- Early Exit Support: Players may exit the game at any time without completing all levels.

## Optimizations
- Player movement no longer requires pressing Enter
- Larger grid sizes for increased difficulty
- Increased coin count per level
- 4 total levels, each with different grid sizes, coin counts, power-ups, and power-downs
- A random level generator for unpredictable gameplay
- A timer to track level completion speed
- Players can exit the game without completing all levels

## Lessons Learned
- Implementing and coordinating multiple classes
- Randomly generating objects within predefined constraints
- Designing levels that are always solvable

## How to Run
### Compile 
```bash
g++ -std=c++17 -Wall -Wextra -o orinoco orinocoCode/gamemain.cpp orinocoCode/game.cpp orinocoCode/randomlevel.cpp orinocoCode/coin.cpp
```
### Run
Windows:
```bash
orinoco.exe
```
Linux:
```bash
.\orinoco
