#include "../header/init.h"
#include "../header/generation.h"
#include "../header/helper.h"

App::App() : window(sf::VideoMode(APP_WIDTH, APP_HEIGHT), "Maze Simulation"), bgColor(0, 39, 76)
{
    if (!pixeloid.loadFromFile("static/PixeloidSans.ttf"))
    {
        exit(1);
    }
    titleText = drawText("Random Maze Generator", pixeloid, 30, APP_WIDTH / 2.0f, APP_HEIGHT / 4.0f);
    kruskalText = drawText("Press K to generate with Kruskal's", pixeloid, 20, APP_WIDTH / 1.97f, APP_HEIGHT / 2.5f);
    primText = drawText("Press P to generate with Prim's", pixeloid, 20, APP_WIDTH / 1.98f, APP_HEIGHT / 2.0f);
    footerText = drawText("Made by Brandon Nguyen (@bxngyn)", pixeloid, 14, 140, APP_HEIGHT - 15);
}

void App::loop()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::K)
            {
                sf::RenderWindow kSim(sf::VideoMode(MAZE_WIDTH * CELL_SIZE, MAZE_HEIGHT * CELL_SIZE + 100), "Kruskal");
                while (kSim.isOpen())
                {
                    sf::Event mazeEvent;
                    while (kSim.pollEvent(mazeEvent))
                    {
                        if (mazeEvent.type == sf::Event::Closed)
                        {
                            kSim.close();
                        }
                    }
                    kruskal(kSim);
                }
            }
            else if (event.key.code == sf::Keyboard::P)
            {
                sf::RenderWindow pSim(sf::VideoMode(MAZE_WIDTH * CELL_SIZE, MAZE_HEIGHT * CELL_SIZE + 100), "Prim");
                while (pSim.isOpen())
                {
                    sf::Event mazeEvent;
                    while (pSim.pollEvent(mazeEvent))
                    {
                        if (mazeEvent.type == sf::Event::Closed)
                        {
                            pSim.close();
                        }
                    }
                    prim(pSim);
                }
            }
        }
    }
}

void App::render()
{
    window.clear(bgColor);
    window.draw(titleText);
    window.draw(kruskalText);
    window.draw(primText);
    window.draw(footerText);
    window.display();
}

void App::run()
{
    while (window.isOpen())
    {
        loop();
        render();
    }
}
