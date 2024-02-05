/*
Authors: Alidad Mehdizadehnamin
         Shayan Heidari
         Arshia Boroomandrad

Instructor: Tamara Dakic
Course: COMP 120
Program last modified: March 27th 2023
_________________________________________________________________________________________________________
this program plays a game of tic tac toe against the player by choosing random
spots on the board. although it is possible to code, this program does not have
logical thinking when choosing its next move, hence the winning and losing is
random.
_________________________________________________________________________________________________________
*/

/*
we use ctype to make checking our empty spots easier by using the isdigit
function from it for our randomized number bool for checking the
situation of our functions time for using in our randomiser
*/
#include <ctype.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define PLAYER 'O'
#define OPPONENT 'X'
#define GRID_SIZE 9
#define TRUE 1
#define FALSE 0


  
/*
********************************

          Prototypes

********************************
*/
int Menu(void);
int MenuMid(void);
void clearInputStream(void);
char getCharInput(void);
int userSaysYes(char []);
int getIntInput(void);
int valueInRange(int, int, int);
int getIntInputInRange(int, int);
int rowIsWinner(char, char, char);
void userTurn(char []);
void opponnent(char []);
void displayHorizontalLine(void);
void displayOneRow(char, char, char);
void printGrid(char []);
int result(char []);
int checkCount(char []);
char checkWinner(char []);
void setupBoard(char []);



/* Main funciton for calling on everything*/
int main(void) {

}
