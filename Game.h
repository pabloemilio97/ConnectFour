#ifndef GAME_H
#define GAME_H
#include "Player.h"

class Game
{
    public:
        Game(Player,Player);
        void display();
        bool checkWin();
        int insertToken(int,Player);
        void startGame();
        void selectMove();
        bool isFull();
    protected:

    private:
        Player p1, p2, current;
        int column, rows;
        bool isPlayer1 = false;
        char cGrid[6][7];/* = {{'O', '-', '-', '-', '-', '-', '-'},
                            {'-', '-', '-', '-', '-', '-', '-'},
                            {'-', '-', '-', '-', '-', '-', '-'},
                            {'-', '-', '-', '-', '-', '-', '-'},
                            {'-', '-', '-', '-', '-', '-', '-'},
                            {'-', '-', '-', '-', '-', '-', '-'}
                            };*/
        int altura [7] = {5,5,5,5,5,5,5};
};

#endif // GAME_H
