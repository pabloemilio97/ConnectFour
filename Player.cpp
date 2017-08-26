#include "Player.h"


Player::Player()
{
    //ctor
}
Player::Player(char c)
{
    cToken = c;
}
int Player::genRand()
{
    int randNum = rand() % 7;
    return randNum;
}
char Player::getToken()
{
    return cToken;
}
