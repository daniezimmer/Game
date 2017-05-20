#include "stdafx.h"
#include "Game.h"

/*
How to compile:
1. g++ -std=c++0x -c main.cpp
2. g++ -main.o -o GameGAMEgame -lsfml-graphics -lsfml-window -lsfml-system

*/


int main(int argc, char** argv)
{
    Game::Start();
    return 0;
}
