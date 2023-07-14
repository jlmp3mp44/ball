#include <SFML/Graphics.hpp>
#include <cmath>
#include "knight.h"
#include <iostream>
using namespace sf;
void moving(bool& movingForward, Sprite& knighter,Sprite& apple, Sprite& line,   float KnightSpeed, float AppleSpeed, float lineSpeed) {
    if (movingForward)
    {
        knighter.move(KnightSpeed, 0);
        apple.move(AppleSpeed, 0);
        line.move(lineSpeed, 0);
        if (knighter.getPosition().x >= 900) // якщо лицар дос€г к≥нц€ вперед
            movingForward = false; // «м≥нити напр€мок на назад
    }
    else
    {
        knighter.move(-KnightSpeed, 0);
        apple.move(-AppleSpeed, 0);
        line.move(-lineSpeed, 0);
        if (knighter.getPosition().x <= 200) // якщо лицар дос€г к≥нц€ назад
            movingForward = true; // «м≥нити напр€мок на вперед

    }
}

const float SlopeSpeed = 0.4f; // √оризонтальна швидк≥сть
const float SlopeAngle = 45.0f; //  ут кидка (в градусах)

void throwApple(Sprite& apple, std::vector<Sprite> scaling) {
    const float UpwardSpeed = 0.3f; // Ўвидк≥сть руху вгору
    apple.move(-SlopeSpeed, -UpwardSpeed);

}
