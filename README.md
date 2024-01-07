Maze Generator & Solver
===================

Application written in C++ using SFML.

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
- "k" to activate generation with Kruskall's Algorithm
- "p" to activate generation with Prim's Algorithm

Examples
-----
#### Kruskall's Algorithm

*gif here*

#### Prim's Algorithm
*gif here*

Planned Updates for the Future
-----
- Option for user to manually input maze height and width to demonstrate how runtime of Kruskall's and Prim's changes as maze size increases/decreases
- Implementing more maze generation and solving algorithms such as DFS and A* pathfinding algorithm
