#include "Game.h"
#include <iostream>

Game::Game(Player one, Player two)
{
    p1 = one;
    p2 = two;
    current = p1;

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            cGrid[i][j] = '-';
        }
    }


}
bool Game::checkWin()
{
    int counter = 0; //counter for determining if 4 adjacent tokens exist
    //check Vertical
    for(int i = 0; i < 6; i++)
    {
        if(cGrid[i][column] == current.getToken())
        {
            counter++;
        }
        else{
            counter = 0;
        }
        if(counter == 4)
            {
                std::cout << "Triumph by vertical" << std::endl;
                return false;
            }

    }
    //check Horizontal
    counter = 0;
    for(int i = 0; i < 7; i++)
    {
        if(cGrid[rows][i] == current.getToken())
        {
            counter++;
        }
        else{
            counter = 0;
        }
        if(counter == 4)
        {
            std::cout << "Triumph by horizontal" << std::endl;
            return false;
        }

    }
    //check Diagonal \ */
    int iMin = (column < rows? column:rows);
    int currCol, currRow;
    counter = 0;
    currCol = column - iMin;
    currRow = rows - iMin;
    do
    {
        if(cGrid[currRow][currCol] == current.getToken())
        {
            counter++;
        }
        else
        {
            counter = 0;
        }
        if(counter == 4)
        {
            std::cout << "Triumph by diagonal \\ " << std::endl;
            return false;
        }
        currCol++;
        currRow++;
    } while(currRow <= 5 && currCol <= 6);

    // check Diagonal /
    counter = 0;
    if (rows + column < 6)
    {
        currCol = 0;
        currRow = column + rows;
        do
        {
            if(cGrid[currRow][currCol] == current.getToken())
                counter++;
            else
                counter = 0;
            if(counter == 4)
            {
            std::cout << "Triumph by diagonal /" << std::endl;
            return false;
            }
            currCol++;
            currRow--;
        }while(currRow >= 0);
    }
    else
    {
        currRow = 5;
        currCol = currRow - rows;
        do
        {
            if(cGrid[currRow][currCol] == current.getToken())
                counter++;
            else
                counter = 0;
            if(counter == 4)
                return false;
            currCol++;
            currRow--;
        }while(currCol < 7);
    }
    return true;
}
int Game::insertToken(int x, Player p)
{
    if(altura[x] < 0)
        return -1;
    cGrid[altura[x]][x] = p.getToken();
    return altura[x]--;

}
void Game::selectMove()
{
    do{
        column = current.genRand();
        rows = insertToken(column,current);
    }while(rows < 0);
}
void Game::startGame(){
    srand (time(NULL));
    do{
    isPlayer1 = !isPlayer1;
    current = (isPlayer1?p1:p2);
    selectMove();
    display();
    }while(checkWin() && isFull());

    if(!isFull())
        std::cout << "It's a tie!!!\n";
    else
        std::cout << current.getToken() << " wins!!!! Congrats!!\n";
}
bool Game::isFull()
{
    //check if there's available space
    int counter = 0;
    for(int i = 0; i < 7; i++)
    {
        if(altura[i] < 0)
            counter++;
    }
    if(counter == 7)
        return false;
    return true;
}
void Game::display()
{
    std::cout << current.getToken() << "'s Turn" << std::endl;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            std::cout << cGrid[i][j];
        }
        std::cout << std::endl;
    }
        std::cout << std::endl;
        std::cout << std::endl;

}
