#pragma once
#ifndef KNIGHT_H
#define KNIGHT_H
#include <SFML/Graphics.hpp>
using namespace sf;

void moving(bool& movingForward, Sprite& knighter, Sprite& apple, Sprite& line, float KnightSpeed, float AppleSpeed, float lineSpeed);
void throwApple(Sprite& apple, std::vector<Sprite> scaling);
#endif 
