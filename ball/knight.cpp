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
        if (knighter.getPosition().x >= 900) // ���� ����� ����� ���� ������
            movingForward = false; // ������ �������� �� �����
    }
    else
    {
        knighter.move(-KnightSpeed, 0);
        apple.move(-AppleSpeed, 0);
        line.move(-lineSpeed, 0);
        if (knighter.getPosition().x <= 200) // ���� ����� ����� ���� �����
            movingForward = true; // ������ �������� �� ������

    }
}

const float SlopeSpeed = 0.4f; // ������������� ��������
const float SlopeAngle = 45.0f; // ��� ����� (� ��������)

void throwApple(Sprite& apple, std::vector<Sprite> scaling) {
    const float UpwardSpeed = 0.3f; // �������� ���� �����
    apple.move(-SlopeSpeed, -UpwardSpeed);

}
