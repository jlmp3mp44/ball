#include <SFML/Graphics.hpp>
#include "Knight.h"
#include <iostream>

using namespace sf;



int main()
{
    float KnightSpeed = 0.2f;
    bool movingForward = true;
    ///////////////BACKGROUND
    Sprite backSprite;
    Texture backGroundTexture;
    backGroundTexture.loadFromFile("D:/C++/ball/back.jpg");
    backSprite.setTexture(backGroundTexture);
    backSprite.setScale(0.4f, 0.4f);

    ///////////////KNIGHT
    Sprite knighter;
    Texture texture;
    texture.loadFromFile("D:/C++/ball/knighter.png");
    knighter.setTexture(texture);
    knighter.setScale(0.4f, 0.4f);
    knighter.setPosition(800, 650);


    /////////////APPLE
    Sprite apple;
    Texture texture2;
    texture2.loadFromFile("D:/C++/ball/apple.png");
    apple.setTexture(texture2);
    apple.setScale(0.3f, 0.3f);
    apple.setPosition(780, 650);


    RenderWindow window(VideoMode(1000, 800), "SFML Works!");


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.key.code == Keyboard::Space) {
                Clock clock;
                float time = 2.0;
                    throwApple(apple, time);  
                    std::cout << 2;
                    window.draw(apple);

                    while()
            }
           
        }
        moving(movingForward, knighter, KnightSpeed);
        window.clear(Color::White);
        window.draw(backSprite);
        window.draw(knighter);
        window.draw(apple);
        window.display();
    }

    return 0;
}
