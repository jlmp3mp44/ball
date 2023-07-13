#pragma once
#ifndef KNIGHT_H
#define KNIGHT_H
#include <SFML/Graphics.hpp>
using namespace sf;

void moving(bool& movingForward, Sprite& knighter,Sprite& apple, float KnightSpeed, float AppleSpeed);
void throwApple(Sprite& apple, float time);
#endif 
