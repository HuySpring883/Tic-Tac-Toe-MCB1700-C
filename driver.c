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

char cells[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int selection, player;
int winCondition();
void drawGameboard();
void updateGameboard(char playerInput);

int funcTicTacToe() {
 
  int i;
  char playerInput;
  player = 1;

  GLCD_DisplayString(0, 4, __FI_LARGE, "Tic Tac Toe"); // Title
  Delay(3000000);
  
  do {
    drawGameboard();
    Delay(10000000);
    player = (player % 2) ? 1 : 2;
    playerInput = (player == 1) ? 'X' : 'O';
    updateGameboard(playerInput);
    i = winCondition();
    player++;
  } while (i == -1);
  
  return 0;
}

int winCondition() {
	 int returnValue = 0;
	
	 if (cells[1] == cells[2] && cells[2] == cells[3])
   	returnValue = 1;
  else if (cells[4] == cells[5] && cells[5] == cells[6])
   	returnValue = 1;
  else if (cells[7] == cells[8] && cells[8] == cells[9])
   	returnValue = 1;
  else if (cells[1] == cells[5] && cells[5] == cells[9])
    returnValue = 1;
  else if (cells[3] == cells[5] && cells[5] == cells[7])
  		returnValue = 1;
  else if (cells[1] == cells[4] && cells[4] == cells[7])
    returnValue = 1;
  else if (cells[2] == cells[5] && cells[5] == cells[8])
    returnValue = 1;
  else if (cells[3] == cells[6] && cells[6] == cells[9])
    returnValue = 1;
  else if (cells[1] != '1' && cells[2] != '2' && cells[3] != '3' &&
           cells[4] != '4' && cells[5] != '5' && cells[6] != '6' &&
           cells[7] != '7' && cells[8] != '8' && cells[9] != '9')
    returnValue = 0;
  else
    returnValue = -1;
 
  return returnValue;
}

/* Draw the game board here */
void drawGameboard() {
 // GLCD Display: 320x240 pixels
 GLCD_DisplayString
}

void updateGameboard(char playerInput) {
 
 if (selection == 1 && cells[1] == '1')
  cells[1] = playerInput;
 else if (selection == 2 && cells[2] == '2')
  cells[2] = playerInput;
 else if (selection == 3 && cells[3] == '3')
  cells[3] = playerInput;
 else if (selection == 4 && cells[4] == '4')
  cells[4] = playerInput;
 else if (selection == 5 && cells[5] == '5')
  cells[5] = playerInput;
 else if (selection == 6 && cells[6] == '6')
  cells[6] = playerInput;
 else if (selection == 7 && cells[7] == '7')
  cells[7] = playerInput;
 else if (selection == 8 && cells[8] == '8')
   cells[8] = playerInput;
 else if (selection == 9 && cells[9] == '9')
   cells[9] = playerInput;
 else
   player--;
 
}
