#include <SFML/Graphics.hpp>
#include "Knight.h"
#include <iostream>
#include <SFML/Audio.hpp>



float KnightSpeed = 0.2f;
bool movingForward = true;

//////////////FOR THROW
const float FlightTime = 6.5f;
bool throwAppleFlag = false;
float appleThrowTime = 0.0f;
bool moveFlag = true;

///////SCALING
int scaleInt = -20;
bool ScaleFlag = true;
bool WIN = true;

bool intersected = false;
bool restart = false;
bool endGame = false;

using namespace sf;
void makeSprite(Sprite& sprite, Texture& texture, String path,float scale);

void makeSprite (Sprite& sprite, Texture& texture, String path, float scale) {
    texture.loadFromFile(path);
    sprite.setTexture(texture);
    sprite.setScale(scale, scale);
}


int main()
{
    
    ///////////////BACKGROUND
    Sprite backSprite;
    Texture backGroundTexture;
    makeSprite(backSprite, backGroundTexture, "D:/C++/ball/back.jpg", 0.4f);

    ///////////////KNIGHT
    Sprite knighter;
    Texture texture;
    makeSprite(knighter, texture, "D:/C++/ball/knighter.png", 0.6f);
    knighter.setPosition(770, 600);
    Vector2f startPosKnight = knighter.getPosition();

    /////////////APPLE
    Sprite apple;
    Texture texture2;
    makeSprite(apple, texture2, "D:/C++/ball/apple.png", 0.3f);
    apple.setPosition(780, 650);
    Vector2f startPosApple = apple.getPosition();


    /////////LINE
    Sprite line;
    Texture lineTexture;
    makeSprite(line, lineTexture, "D:/C++/ball/line.png", 1.0f);
    line.setPosition(350, 300);
    line.setColor(Color::White);

    ///////////////SOUND
    SoundBuffer buffer;
    buffer.loadFromFile("D:/C++/ball/svist.mp3");
    Sound sound;
    sound.setBuffer(buffer);


    //////////////TEXT
    Font font;
    if(!font.loadFromFile("C:/Windows/Fonts/Britanic.ttf")) return 0;
    Text scale;
    scale.setFont(font);
    scale.setString("Scale");
    scale.setFillColor(Color::Black);
    scale.setCharacterSize(48);
    scale.setPosition(50, 25);

    /////////////LOSE
    Sprite loseSprite;
    Texture loseTexture;
    makeSprite(loseSprite, loseTexture, "D:/C++/ball/lose.jpg", 1.1f);

    ///////////////WIN
    Sprite winSprite;
    Texture winTexture;
    makeSprite(winSprite, winTexture, "D:/C++/ball/win.png", 1.0f);

//////////////////SCALING
    std::vector<Sprite> scaling;
    Texture textureEmptySprite;
    textureEmptySprite.loadFromFile("D:/C++/ball/empty.png");
    textureEmptySprite.setSmooth(true);
    for (int i = 0; i < 5; i++) {
        Sprite sprite;
        sprite.setTexture(textureEmptySprite);
        sprite.setScale(0.1f, 0.1f);
        sprite.setPosition(1, 150 + i * 100);
        scaling.push_back(sprite);
    }
   
    RenderWindow window(VideoMode(1000, 800), "SFML Works!");


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.key.code == Keyboard::Space) {
                if (!endGame) {
                    sound.play();
                    throwAppleFlag = true;
                    moveFlag = false;
                }
                
            }
            if (event.key.code == Keyboard::Enter ) {
                    if (endGame) {
                        knighter.setPosition(startPosKnight);
                        apple.setPosition(startPosApple);
                    }
                    restart = true;
                
            }
           
        }
        
        window.clear(Color::White);
        window.draw(backSprite);
        window.draw(knighter);
        window.draw(apple);
        window.draw(line);
        if(moveFlag) moving(movingForward, knighter, apple, line, KnightSpeed, KnightSpeed, KnightSpeed);

        
        if (throwAppleFlag && endGame!=true) {
            throwApple(apple, scaling);
            window.draw(apple);
            if (apple.getPosition().x <= 1) throwAppleFlag = false;


            for (int i = 0; i < scaling.size(); i++) {
                if (scaling[i].getGlobalBounds().contains(apple.getGlobalBounds().left, apple.getGlobalBounds().top) && ScaleFlag) {
                    sound.stop();
                    scaleInt += i * 30;
                    ScaleFlag = false;
                    scale.setString("Scale  " + std::to_string(abs(scaleInt)));
                    intersected = true;
                    break;
                }
                
            }
            WIN = intersected;
        }
        
           
        window.draw(apple);
        window.draw(scale);
        for (int i = 0; i < scaling.size(); i++) {
            window.draw(scaling[i]);
        }
        
        if (WIN!=true && throwAppleFlag == false ) {
            moveFlag = true;
            endGame = true;
            window.clear(Color::Red);
            window.draw(loseSprite);
        }
        else if (WIN == true && throwAppleFlag == true) {
            endGame = true;
            window.clear(Color::Green);
            window.draw(winSprite);
            scale.setString(std::to_string(abs(scaleInt)));
            scale.setPosition(500, 500);
            scale.setCharacterSize(70);
            window.draw(scale);
        }
       
        window.display();
        
    }
   
    return 0;
}
