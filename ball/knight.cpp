#include <SFML/Graphics.hpp>
#include <cmath>
#include "knight.h"
#include <iostream>
using namespace sf;
void moving(bool& movingForward, Sprite& knighter,Sprite& apple,  float KnightSpeed, float AppleSpeed) {
    if (movingForward)
    {
        knighter.move(KnightSpeed, 0);
        apple.move(AppleSpeed, 0);
        if (knighter.getPosition().x >= 900) // якщо лицар дос€г к≥нц€ вперед
            movingForward = false; // «м≥нити напр€мок на назад
    }
    else
    {
        knighter.move(-KnightSpeed, 0);
        apple.move(-AppleSpeed, 0);
        if (knighter.getPosition().x <= 600) // якщо лицар дос€г к≥нц€ назад
            movingForward = true; // «м≥нити напр€мок на вперед

    }
}

const float SlopeSpeed = 180.0f; // √оризонтальна швидк≥сть
const float SlopeAngle = 45.0f; //  ут кидка (в градусах)

void throwApple(Sprite& apple, float time) {
    const float UpwardSpeed = 20.0f; // Ўвидк≥сть руху вгору

    float angleRad = SlopeAngle * 3.14f / 180.0f; // ѕереведенн€ кута у рад≥ани
    float displacementX = SlopeSpeed * std::cos(angleRad) * time; // √оризонтальне зм≥щенн€
    float displacementY = UpwardSpeed * time; // ¬ертикальне зм≥щенн€ вгору


    apple.setPosition(-displacementX+800, -displacementY+600);
}
