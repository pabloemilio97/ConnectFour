#ifndef PLAYER_H
#define PLAYER_H
#include <stdlib.h>
#include <time.h>

class Player
{
    public:
        Player();
        Player(char);
        int genRand();
        char getToken();

    protected:

    private:
        char cToken;
};

#endif // PLAYER_H
