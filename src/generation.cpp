#include <iostream>
#include <SFML/Graphics.hpp>

#include "../header/helper.h"
#include "../header/generation.h"

void kruskal(sf::RenderWindow &window)
{
    srand(time(nullptr));

    Cell cellArr[MAZE_WIDTH * MAZE_HEIGHT];
    for (int i = 0; i < MAZE_WIDTH * MAZE_HEIGHT; i++)
    {
        cellArr[i].group = i;
    }

    std::vector<Edge> edgeVec;
    for (int col = 0; col < MAZE_WIDTH; col++)
    {
        for (int row = 0; row < MAZE_HEIGHT; row++) 
        {
            Cell* cell1 = &(cellArr[col + row * MAZE_WIDTH]);
            for (int i = 0; i < 2; ++i)
            {
                int next_col = nextCol(col, i);
                int next_row = nextRow(row, i);
                if (inBound(next_col, next_row))
                {
                    Edge edge;
                    edge.cell1 = cell1;
                    edge.cell2 = &(cellArr[next_col + next_row * MAZE_WIDTH]);
                    edgeVec.push_back(edge);
                }
            }
        }
    }
    
    sf::Text elapsedTimeText;
    sf::Font font;
    if (!font.loadFromFile("static/PixeloidSans.ttf")) {
        exit(1);
    }
    sf::Vector2u windowSize = window.getSize();
    elapsedTimeText.setFont(font);
    elapsedTimeText.setCharacterSize(20);
    elapsedTimeText.setFillColor(sf::Color::White);
    elapsedTimeText.setPosition(windowSize.x / 2.5, windowSize.y / 1.1);

    sf::Clock timer;
    timer.restart();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Color michblue(0, 39, 76);
        window.clear(michblue);

        if (!edgeVec.empty())
        {
            int rndEdge = rand() % edgeVec.size();
            Edge* edge = &(edgeVec.at(rndEdge));
            Cell* cell1 = edge->cell1;
            Cell* cell2 = edge->cell2;
            if (cell1->group != cell2->group)
            {
                joinCells(cellArr, cell1, cell2);
                mergeGroup(cellArr, cell1->group, cell2->group);
            }

            edgeVec.erase(edgeVec.begin() + rndEdge);

            float elapsedTime = timer.getElapsedTime().asSeconds();
            elapsedTimeText.setString(std::to_string(elapsedTime) + " s");
        }

        drawMaze(window, cellArr);

        window.draw(elapsedTimeText);

        window.display();
    }
}

void prim(sf::RenderWindow &window)
{
    srand(time(nullptr));

    Cell cellArr[MAZE_WIDTH * MAZE_HEIGHT];

    int cur_col = rand() % MAZE_WIDTH;
    int cur_row = rand() % MAZE_HEIGHT;

    std::vector<Edge> edgeVec;
    appendEdge(&edgeVec, cellArr, cur_col, cur_row);
    cellArr[cur_col + cur_row * MAZE_WIDTH].visited = true;

    sf::Text elapsedTimeText;
    sf::Text title;
    sf::Font font;
    if (!font.loadFromFile("static/PixeloidSans.ttf"))
    {
        exit(1);
    }
    sf::Vector2u windowSize = window.getSize();
    elapsedTimeText.setFont(font);
    elapsedTimeText.setCharacterSize(20);
    elapsedTimeText.setFillColor(sf::Color::White);
    elapsedTimeText.setPosition(windowSize.x / 2.5, windowSize.y / 1.1);
    sf::Clock timer;
    timer.restart();

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        sf::Color michblue(0, 39, 76);
        window.clear(michblue);

        if (!edgeVec.empty())
        {
            int rndEdge = rand() % edgeVec.size();
            Edge edge = edgeVec.at(rndEdge);
            Cell* cell1 = edge.cell1;
            Cell* cell2 = edge.cell2;

            if((cell1->visited && !cell2->visited) || (!cell1->visited && cell2->visited))
            {
                joinCells(cellArr, cell1, cell2);

                int node_index;
                if (!cell1->visited)
                {
                    node_index = cell1 - cellArr;
                    cell1->visited = true;
                } else
                {
                    node_index = cell2 - cellArr;
                    cell2->visited = true;
                }

                cur_row = (int) node_index / MAZE_WIDTH;
                cur_col = node_index % MAZE_WIDTH;

                appendEdge(&edgeVec, cellArr, cur_col, cur_row);
            }

            edgeVec.erase(edgeVec.begin() + rndEdge);
            float elapsedTime = timer.getElapsedTime().asSeconds();
            elapsedTimeText.setString(std::to_string(elapsedTime) + " s");
        }

        drawMaze(window, cellArr);
        
        window.draw(elapsedTimeText);

        window.display();
    }
}