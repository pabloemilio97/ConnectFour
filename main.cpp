#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
    Player p1('X');
    Player p2('O');
    Game game(p1, p2);
    game.startGame();
}
