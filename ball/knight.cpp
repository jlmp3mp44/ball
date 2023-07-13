#include <SFML/Graphics.hpp>
#include <cmath>
#include "knight.h"
#include <iostream>
using namespace sf;
void moving(bool& movingForward, Sprite& knighter, float KnightSpeed) {
    if (movingForward)
    {
        knighter.move(KnightSpeed, 0);
        if (knighter.getPosition().x >= 900) // Якщо лицар досяг кінця вперед
            movingForward = false; // Змінити напрямок на назад
    }
    else
    {
        knighter.move(-KnightSpeed, 0);
        if (knighter.getPosition().x <= 800) // Якщо лицар досяг кінця назад
            movingForward = true; // Змінити напрямок на вперед

    }
}

const float SlopeSpeed = 50.0f; // Горизонтальна швидкість
const float SlopeAngle = 10.0f; // Кут кидка (в градусах)
const float FlightTime = 5.0f; // Час польоту (у секундах)

void throwApple(Sprite& apple, float time) {
    float angleRad = SlopeAngle * 3.14f / 180.0f; // Переведення кута у радіани
    float displacementX = SlopeSpeed * std::cos(angleRad) * time; // Горизонтальне зміщення
    float displacementY = SlopeSpeed * std::sin(angleRad) * time - (0.5f * 9.8f * time * time); // Вертикальне зміщення з урахуванням гравітації

    if (time <= FlightTime) {
        std::cout << 1;
        apple.setPosition(displacementX, -displacementY); // Застосування зміщень до позиції спрайту
        time += 0.05f;
        throwApple(apple, time);
    }
}
