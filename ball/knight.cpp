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
        if (knighter.getPosition().x >= 900) // ���� ����� ����� ���� ������
            movingForward = false; // ������ �������� �� �����
    }
    else
    {
        knighter.move(-KnightSpeed, 0);
        apple.move(-AppleSpeed, 0);
        if (knighter.getPosition().x <= 600) // ���� ����� ����� ���� �����
            movingForward = true; // ������ �������� �� ������

    }
}

const float SlopeSpeed = 180.0f; // ������������� ��������
const float SlopeAngle = 45.0f; // ��� ����� (� ��������)

void throwApple(Sprite& apple, float time) {
    const float UpwardSpeed = 20.0f; // �������� ���� �����

    float angleRad = SlopeAngle * 3.14f / 180.0f; // ����������� ���� � ������
    float displacementX = SlopeSpeed * std::cos(angleRad) * time; // ������������� �������
    float displacementY = UpwardSpeed * time; // ����������� ������� �����


    apple.setPosition(-displacementX+800, -displacementY+600);
}
