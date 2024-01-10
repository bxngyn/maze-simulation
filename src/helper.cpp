#include <SFML/Graphics.hpp>

#include "../header/helper.h"

sf::Text drawText(const char *string, sf::Font &font, size_t fontSize, float xPos, float yPos)
{
    sf::Text text(string, font, fontSize);
    
    sf::Rect bound = text.getLocalBounds();
    text.setOrigin(bound.left + bound.width / 2, bound.top + bound.height / 2);
    text.setPosition(xPos, yPos);
    text.setFillColor(sf::Color::White);

    return text;
}

void drawCell(sf::RenderWindow &window, Cell cellArr[], int col, int row)
{
    Cell* curCell = &(cellArr[col + row * MAZE_WIDTH]);

    if (!(curCell->edges[NORTH] && curCell->edges[EAST] && curCell->edges[SOUTH] && curCell->edges[WEST]))
    {
        sf::RectangleShape cell;
        sf::Color maize(191, 155, 8);
        cell.setPosition(col * CELL_SIZE + 5, row * CELL_SIZE + 5);
        cell.setSize(sf::Vector2f(10, 10));
        cell.setFillColor(maize);
        window.draw(cell);
    }
}

void drawEdge(sf::RenderWindow &window, Cell cellArr[], int col, int row)
{
    Cell* node = &(cellArr[col + row * MAZE_WIDTH]);
    if (!(node->edges[NORTH] && node->edges[EAST] && node->edges[SOUTH] && node->edges[WEST]))
    {
        sf::RectangleShape edge;
        sf::Color maize(191, 155, 8);
        edge.setFillColor(maize);

        if (!node->edges[NORTH])
        {
            edge.setPosition(sf::Vector2f(col * CELL_SIZE + 5, row * CELL_SIZE));
            edge.setSize(sf::Vector2f(10, 5));
            window.draw(edge);
        }
        if (!node->edges[EAST])
        {
            edge.setPosition(sf::Vector2f(col * CELL_SIZE + 5 + 10, row * CELL_SIZE + 5));
            edge.setSize(sf::Vector2f(5, 10));
            window.draw(edge);
        }
        if (!node->edges[SOUTH])
        {
            edge.setPosition(sf::Vector2f(col * CELL_SIZE + 5, row * CELL_SIZE + 5 + 10));
            edge.setSize(sf::Vector2f(10, 5));
            window.draw(edge);
        }
        if (!node->edges[WEST])
        {
            edge.setPosition(sf::Vector2f(col * CELL_SIZE, row * CELL_SIZE + 5));
            edge.setSize(sf::Vector2f(5, 10));
            window.draw(edge);
        }
    }
}

void drawMaze(sf::RenderWindow &window, Cell cellArr[])
{
    for (int col = 0; col < MAZE_WIDTH; col++)
    {
        for (int row = 0; row < MAZE_HEIGHT; row++)
        {
            drawCell(window, cellArr, col, row);
            drawEdge(window, cellArr, col, row);
        }
    }
}

bool inBound(int col, int row)
{
    if ((col < 0 || col >= MAZE_WIDTH) || (row < 0 || row >= MAZE_HEIGHT))
    {
        return false;
    }
    return true;
}

int nextCol(int cur_col, int side)
{
    int dcol = 0;
    if (side == EAST)
    {
        dcol++;
    }
    else if (side == WEST)
    {
        dcol--;
    }
    return cur_col + dcol;
}

int nextRow(int cur_row, int side)
{
    int drow = 0;
    if (side == SOUTH)
    {
        drow++;
    }
    else if (side == NORTH)
    {
        drow--;
    }
    return cur_row + drow;
}


int connectingSide(int cell1_index, int cell2_index)
{
    int side;
    switch (cell2_index - cell1_index)
    {
    case 1:
        side = EAST;
        break;
    case -1:
        side = WEST;
        break;
    case MAZE_WIDTH:
        side = SOUTH;
        break;
    case -MAZE_WIDTH:
        side = NORTH;
        break;
    }
    return side;
}

void joinCells(Cell cellArr[], Cell* cell1, Cell* cell2)
{
    int cell1_index = cell1 - cellArr;
    int cell2_index = cell2 - cellArr;
    int side = connectingSide(cell1_index, cell2_index);
    int oppositeSide = (side + 2) % 4;
    cell1->edges[side] = false;
    cell2->edges[oppositeSide] = false;
}

void mergeGroup(Cell cellArr[], int group1, int group2)
{
    for (int i = 0; i < MAZE_WIDTH * MAZE_HEIGHT; ++i)
    {
        if (cellArr[i].group == group2)
        {
            cellArr[i].group = group1;
        }
    }
}

void appendEdge(std::vector<Edge> *edgeVec, Cell cellArr[], int col, int row)
{
    Cell* cell1 = &(cellArr[col + row * MAZE_WIDTH]);
    for (int side = 0; side < 4; side++)
    {
        int next_col = nextCol(col, side);
        int next_row = nextRow(row, side);
        if (inBound(next_col, next_row))
        {
            Edge edge;
            edge.cell1 = cell1;
            edge.cell2 = &(cellArr[next_col + next_row * MAZE_WIDTH]);
            edgeVec->push_back(edge);
        }
    }
}