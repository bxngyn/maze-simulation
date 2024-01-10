#ifndef __INIT_H__
#define __INIT_H__

#include <SFML/Graphics.hpp>

#define APP_WIDTH 1024
#define APP_HEIGHT 768
#define MAZE_WIDTH 35
#define MAZE_HEIGHT 25
#define CELL_SIZE 15

class App
{
    public:
        App(void);
        void run(void);

    private:
        sf::RenderWindow window;
        sf::Font pixeloid;
        sf::Color bgColor;
        sf::Text titleText, kruskalText, primText, footerText;
        void loop(void);
        void render(void);
};

#endif
