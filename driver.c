/*
 Implementing Tic-Tac-Toe on the MCB1700 Evaluation board using C programming language.
 
 General Complexity is Simple
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Add required header files
#include "GLCD.h"
#include "KBD.h"

// .bimp files
#include "symbol_X.c"
#include "symbol_O.c"
#include "symbol_X_selected.c"
#include "symbol_O_selected.c"
#include "gameboard.c"

#define __FI_LARGE 1
#define __FI_SMALL 0

extern void Delay(uint32_t);

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int choice, player;
int checkForWin();
void displayBoard();
void mrkBoard(char mark);

int funcTicTacToe()
{
  int i;
  char mark;
  player = 1;

  GLCD_DisplayString(0, 4, __FI_LARGE, "Tic Tac Toe"); // Title
  Delay(3000000);
  
  do {
    displayBoard();
    Delay(10000000);
    player = (player % 2) ? 1 : 2;
    mark = (player == 1) ? 'X' : 'O';
    mrkBoard(mark);
    i = checkForWin();
    player++;
  } while (i == -1);
  
  return 0;
}

int checkForWin()
{
    int returnValue = 0;
    if (square[1] == square[2] && square[2] == square[3])
        returnValue = 1;
    else if (square[4] == square[5] && square[5] == square[6])
        returnValue = 1;
    else if (square[7] == square[8] && square[8] == square[9])
        returnValue = 1;
    else if (square[1] == square[5] && square[5] == square[9])
        returnValue = 1;
    else if (square[3] == square[5] && square[5] == square[7])
        returnValue = 1;
    else if (square[1] == square[4] && square[4] == square[7])
        returnValue = 1;
    else if (square[2] == square[5] && square[5] == square[8])
        returnValue = 1;
    else if (square[3] == square[6] && square[6] == square[9])
        returnValue = 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
        returnValue = 0;
    else
        returnValue = -1;
    return returnValue;
}

/* Draw the game board here */
void displayBoard()
{
  // GLCD Display: 320x240 pixels
}

void mrkBoard(char mark)
{
    if (choice == 1 && square[1] == '1')
        square[1] = mark;
    else if (choice == 2 && square[2] == '2')
        square[2] = mark;
    else if (choice == 3 && square[3] == '3')
        square[3] = mark;
    else if (choice == 4 && square[4] == '4')
        square[4] = mark;
    else if (choice == 5 && square[5] == '5')
        square[5] = mark;
    else if (choice == 6 && square[6] == '6')
        square[6] = mark;
    else if (choice == 7 && square[7] == '7')
        square[7] = mark;
    else if (choice == 8 && square[8] == '8')
        square[8] = mark;
    else if (choice == 9 && square[9] == '9')
        square[9] = mark;
    else
    {
        printf("Invalid ");
        player--;
        getch();
    }
}
