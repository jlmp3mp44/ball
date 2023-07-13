#include <SFML/Graphics.hpp>
#include <cmath>
#include "knight.h"
#include <iostream>
using namespace sf;
void moving(bool& movingForward, Sprite& knighter, float KnightSpeed) {
    if (movingForward)
    {
        knighter.move(KnightSpeed, 0);
        if (knighter.getPosition().x >= 900) // ���� ����� ����� ���� ������
            movingForward = false; // ������ �������� �� �����
    }
    else
    {
        knighter.move(-KnightSpeed, 0);
        if (knighter.getPosition().x <= 800) // ���� ����� ����� ���� �����
            movingForward = true; // ������ �������� �� ������

    }
}

const float SlopeSpeed = 50.0f; // ������������� ��������
const float SlopeAngle = 10.0f; // ��� ����� (� ��������)
const float FlightTime = 5.0f; // ��� ������� (� ��������)

void throwApple(Sprite& apple, float time) {
    float angleRad = SlopeAngle * 3.14f / 180.0f; // ����������� ���� � ������
    float displacementX = SlopeSpeed * std::cos(angleRad) * time; // ������������� �������
    float displacementY = SlopeSpeed * std::sin(angleRad) * time - (0.5f * 9.8f * time * time); // ����������� ������� � ����������� ���������

    if (time <= FlightTime) {
        std::cout << 1;
        apple.setPosition(displacementX, -displacementY); // ������������ ������ �� ������� �������
        time += 0.05f;
        throwApple(apple, time);
    }
}
