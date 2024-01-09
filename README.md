Maze Simulation (w.i.p.)
===================

An application written in C++ using SFML to demonstrate the runtime differences between maze generation algorithms as maze size changes.

Requirements
---------

[SFML 2](https://www.sfml-dev.org/download.php)

Compiling
---------

After ensuring SFML is installed with correctly linked path directory, run `make` in terminal.

Usage
-----
Run `./maze` in terminal. An example executable, `./the_maze`, has been provided as well. <br><br>
After running, user will be prompted to input maze width and height in command line.<br>

*Keyboard Shortcuts*
- "k" to activate generation with Kruskal's Algorithm
- "p" to activate generation with Prim's Algorithm

Graphics
-----

**Prim's Algorithm (675px x 225px)**
![](https://github.com/bxngyn/maze-simulation/blob/main/resource/prims.gif)

Planned Updates for the Future
-----
- Improve user experience by integrating visual dropdown for maze height/width options rather than manually altering code
- Implementing option to choose between solving algorithms such as Random Mouse, Hand on Wall, and A* pathfinding
