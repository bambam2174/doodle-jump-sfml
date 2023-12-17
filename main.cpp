#include <SFML/Graphics.hpp>
#include <time.h>
#include <array>
#include <iostream>

void logBounds(sf::Sprite &, std::string);
typedef struct _Point
{
    int x;
    int y;
} Point;

int main()
{
    srand((unsigned int)time(0));

    sf::RenderWindow app(sf::VideoMode(400, 533), "Doodle Jump");
    app.setFramerateLimit(60);

    sf::Texture t1, t2, t3, t4, t5;
    t1.loadFromFile("./images/background.png");
    t2.loadFromFile("./images/platform.png");
    t3.loadFromFile("./images/player.png");

    sf::Sprite sBackground(t1), sPlatform(t2), sPlayer(t3);

    float widthPlayer = sPlayer.getLocalBounds().width;
    float heightPlayer = sPlayer.getLocalBounds().height;
    float widthPlatform = sPlatform.getLocalBounds().width;
    float heightPlatform = sPlatform.getLocalBounds().height;

    logBounds(sPlayer, "Initial sPlayer");

    std::array<Point, 20> platforms;
    for (int i = 0; i < 10; i++)
    {
        platforms[i].x = rand() % 400;
        platforms[i].y = rand() % 533;
    }

    int x = 100, y = 100, h = 200;
    float dx = 0.f, dy = 0.f;

    while (app.isOpen())
    {
        sf::Event e;
        while (app.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                app.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            x -= 3.f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            x += 3.f;
        }

        dy += 0.2f;
        y += dy;

        if (y > 500)
        {
            dy = -10.f;
        }
        std::cout << "dy : " << dy << ", y : " << y << std::endl;

        for (int i = 0; i < 10; i++)
        {
            if (x + widthPlayer > platforms[i].x && x < platforms[i].x + widthPlatform &&
                y + heightPlayer < platforms[i].y + heightPlatform && y + heightPlayer > platforms[i].y && dy > 0)
            {
                dy = -10.f;
            }
        }
        sPlayer.setPosition(x, y);

        logBounds(sPlayer, "Player");
        app.draw(sBackground);

        app.draw(sPlayer);

        for (int i = 0; i < 10; i++)
        {
            sPlatform.setPosition(platforms[i].x, platforms[i].y);
            app.draw(sPlatform);
        }

        app.display();
    }
    return 0;
}

/**
 * Logs the bounds of a given SFML sprite.
 *
 * @param sName the name of the sprite
 * @param sSprite the sprite to log bounds for
 *
 * @return void
 *
 * @throws None
 */
void logBounds(sf::Sprite &sSprite, std::string sName)
{
    sf::FloatRect rectSprite = sSprite.getLocalBounds();
    std::cout << sName << "> width : " << rectSprite.width << ", height : " << rectSprite.height << std::endl;
}