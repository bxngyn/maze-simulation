#ifndef __HELPER_H__
#define __HELPER_H__

#include <SFML/Graphics.hpp>
#include "init.h"

/**
 * Used to access cell's N/E/S/W edges
*/
enum Direction
{
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
};

/**
 * Represents each cell in graph, which can be connected
 * by 4 edges in NESW directions
*/
struct Cell
{
    bool edges[4] = {true, true, true, true};
    bool visited = false;
    int group;
};

/**
 * Used to access two cells connected by an edge
*/
struct Edge
{
    Cell* cell1;
    Cell* cell2;
};

sf::Text drawText(const char *string, sf::Font &font, size_t fontSize, float xPos, float yPos);

void drawCell(sf::RenderWindow &window, Cell cellArr[], int col, int row);

void drawEdge(sf::RenderWindow &window, Cell cellArr[], int col, int row);

void drawMaze(sf::RenderWindow &window, Cell cellArr[]);

bool inBound(int col, int row);

int nextCol(int cur_col, int side);

int nextRow(int cur_row, int side);

void setEdge(Cell cellArr[], int col, int row, int side, bool state);

int connectingSide(int cell1_index, int cell2_index);

void joinCells(Cell cellArr[], Cell* cell1, Cell* cell2);

void mergeGroup(Cell cellArr[], int group1, int group2);

void appendEdge(std::vector<Edge> *edgeVec, Cell cellArr[], int col, int row);

#endif