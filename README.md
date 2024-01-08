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
**Note: height is currently restricted to values from 2-68, width is restricted to values from 2-55.**

*Keyboard Shortcuts*
- "k" to activate generation with Kruskal's Algorithm
- "p" to activate generation with Prim's Algorithm

Example
-----
**Kruskal's Algorithm ran on maze width and height of 45.** <br>
![](https://github.com/bxngyn/maze-simulation/blob/main/resource/example.gif)

Planned Updates for the Future
-----
- Implementing option to choose between solving algorithms such as Random Mouse, Hand on Wall, and A* pathfinding
- Implementing more maze generation algorithms such as Wilson's Algorithm
- Improve user experience by integrating visual dropdown for maze height/width options rather than command line input
