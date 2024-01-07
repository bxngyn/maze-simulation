Maze Generator & Solver
===================

An application written in C++ using SFML to demonstrate the runtime differences between maze generation algorithms as maze size changes.

Requirements
---------

[SFML 2.6.1 or greater](https://www.sfml-dev.org/download.php)

Compiling
---------

After ensuring SFML is installed with correctly linked path directory, run `make` in terminal.

Usage
-----
Run `./maze` in terminal. An example executable, `./the_maze`, has been provided as well.

*Keyboard Shortcuts*
- "k" to activate generation with Kruskal's Algorithm
- "p" to activate generation with Prim's Algorithm

Examples
-----
#### Kruskal's Algorithm

*gif here*

#### Prim's Algorithm
*gif here*

Planned Updates for the Future
-----
- Implementing option for user to choose between solving algorithms such as Random Mouse, Hand on Wall, and A* pathfinding
- Implementing more maze generation algorithms such as DFS and Wilson's Algorithm
