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
  // Initially decalre the grid. only gets manipulated afterwards to reset it.
  char grid[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  
  srand((unsigned)time(NULL));

  // Only goes through if user says yes.
  if (Menu()) {
    // Main loop for the menu
    while (TRUE) {
      // Secondary loop for the game.
      while (TRUE) {
        printGrid(grid);
        // User plays first.
        userTurn(grid);
        // Check for a winner mid-game.
        if (checkWinner(grid) != -1)
          // Get out of the loop in case of a win.
          break;
        opponnent(grid);
        // Check for a winner mid-game.
        if (checkWinner(grid) != -1)
          break;
      }
      // Mid-program menu to see if the user wants to play again.
      if (MenuMid()) {
        printf("\nok. let me set up the board\n");
        // Reset the board/grid[]
        setupBoard(grid);
      } else {
        printf("It was fun while it lasted\n");
        break;
      }
    }
    return 0;
  } else {
    printf("\nMaybe we'll see you later.\n");
    return 0;
  }
}




/*
The main menu that will only pop up once in the prime step of the program.
Clean implementation, no need to pollute main with dialogue.
*/
int Menu(void) {
  printf("Welcome to a game of tic-tac-toe!\n\n");
  return userSaysYes("Press Y to play and N to quit\n");
}



/*
This is the menu that will pop up after the firstt game finishes. the options are similar to userSaysYes but the comments differ.
Clean implementation, no need to pollute main with dialogue.
*/
int MenuMid(void) {
  return userSaysYes("Do you want to play again? Y or N.\n");
}



/*
reads the first character from the input stream using the getchar() function
and stores it in the variable input,Then enters a loop that continues until
input equals the newline character \n.
*/
void clearInputStream(void) {
  char input = getchar();
  while (input != '\n') {
    input = getchar();
  }
}



/* This function clears the newline characters('\n') from the input stream
   and reads the first non-newline character
   Pre: None
   Post: The first non-newline character is returned.
*/
char getCharInput(void) {
  char input;
  input = getchar();
  while (input == '\n') {
    input = getchar();
  }
  return input;
}



/*
Defines a function named userSaysYes that takes a char array (question) as an
argument and returns an int. The purpose of the function is to prompt the
user with a yes-or-no question and wait for the user to input a valid
response.
*/
int userSaysYes(char question[]) {
  char answer;
  int result = 0;
  printf("%s (y/n): \n", question);

  while (TRUE) {
    answer = getCharInput();
    clearInputStream();

    if (toupper(answer) == 'Y') {
      result = 1;
      break;
    } else if (toupper(answer) == 'N') {
      break;
    } else {
      printf("Invalid input. Please enter Y or N\n");
    }
  }
  printf("\n");
  return result;
}



/*
This function reads an integer value from the standard input stream and returns it. If the input is not a valid integer, the function will prompt the user to enter a proper integer and continue to loop until a valid integer is
entered.
*/
int getIntInput(void) {
  int num;
  char term;

  while (scanf("%d%c", &num, &term) != 2 || term != '\n') {
    printf("Improper input. Please enter an integer: \n");
    clearInputStream();
  }
  return num;
}



/*
this section determines whether a given integer value is within a specified
range, which is defined by a minimum value (min) and a maximum value (max).
*/
int valueInRange(int value, int min, int max) {
  return (min <= value && value <= max);
}



/*
The function getIntInputInRange() reads an integer value from the user and
validates it to ensure that it falls within the specified range.
*/
int getIntInputInRange(int numMin, int numMax) {
  int num;

  num = getIntInput();
  while (!valueInRange(num, numMin, numMax)) {
    printf("%d is not between %d and %d\nTry again: ", num, numMin, numMax);
    num = getIntInput();
  }
  return num;
}



/*
The function rowIsWinner() takes three characters as parameters, which
represent the symbols in a row of the game and checks if all three symbols
are the same non-digit character.
The rowIsWinner() function takes three characters as input arguments,
representing the values in a row of a tic-tac-toe game board, and returns an
integer value.
*/

int rowIsWinner(char s1, char s2, char s3) {
  return (s1 == s2 && s2 == s3 && !(isdigit(s1)));
}


/*
The function userTurn() allows the user to make a move in a game represented
by the character array arr. The function prompts the user to select a
position in the game board and then checks if the selected position is empty
or not.
*/
void userTurn(char arr[]) {
  printf("You are %cs.\nFill the position: \n", PLAYER);

  int num;
  int numMin = 1; // I CHANGED THIS FROM 0 AND 8
  int numMax = GRID_SIZE;

  do {
    num = getIntInputInRange(numMin, numMax);

    if (!(isdigit(
            arr[num - 1]))) { // checks if spot is a digit or not(empty or not)
      printf("The position you have selected (%d) is already occupied. Please "
             "choose another position: \n",
             num);
    } else {
      arr[num] = PLAYER;
      printf("\n");
      printf("\n");
      break;
    }
  } while (true);
}



/*
The opponent() function selects a random empty position on the game board
represented by the character array arr and updates it with the opponent'smove.
*/
void opponnent(char grid[]) {
  printf("Computer playing %cs. 🤖 \n ", OPPONENT);
  int played = FALSE;

  while (played != TRUE) {
    int b = rand();
    int num = b;
    if (isdigit(grid[num])) {
      grid[num] = OPPONENT;
             
    }
  }
}


/*
The displayHorizontalLine() function prints a horizontal line to the console.
This line consists of underscores (represented by the underscore character
'_') and a newline character '\n' to start a new line.
*/
void displayHorizontalLine(void)
{
  printf("__________________\n\n");
}



/*
The displayOneRow() function prints a single row of a tic-tac-toe game board
to the console. This row contains three characters or symbols that represent
the current state of the game board.
*/
void displayOneRow(char s1, char s2, char s3) {
  printf("  %c  |  %c  |  %c\n", s1, s2, s3);
}




/*
The printGrid() function takes an array of characters representing the
current state of a tic-tac-toe game board and prints it to the console. The
function does https://music.youtube.com/watch?v=QgQWu3cOCtsthis by calling
displayOneRow() and displayHorizontalLine() functions in a loop.
*/
void printGrid(char grid[]) {
  printf("\n");
  for (int i = 0; i < 8; i = i + 3) {
    displayOneRow(grid[i], grid[i + 1], grid[i + 2]);
    if (i < 6) // this condition is made to make sure we have a grid instead of
               // a box
      displayHorizontalLine();
  }
}



/* 
The result() function takes an array grid representing the current state of a
tic-tac-toe game board, and returns an integer value.
List of all possiblities.
*/
int result(char grid[]) {
  if (rowIsWinner(grid[0], grid[1], grid[2]) ||
      rowIsWinner(grid[0], grid[3], grid[6]) ||
      rowIsWinner(grid[0], grid[4], grid[8])) {
    return grid[0];
  }
  if (rowIsWinner(grid[2], grid[5], grid[8]) ||
      rowIsWinner(grid[2], grid[4], grid[6])) {
    return grid[2];
  }
  if (rowIsWinner(grid[3], grid[4], grid[5])) {
    return grid[3];
  }
  if (rowIsWinner(grid[6], grid[7], grid[8])) {
    return grid[6];
  }
  if (rowIsWinner(grid[1], grid[4], grid[7])) {
    return grid[1];
  }
  return 0;
}


/*
Go through the grid[] and see how many spots are left.
*/
int checkCount(char grid[]) {
  int count = 0;
  for (int i = 0; i < GRID_SIZE; ++i) {
    if (isdigit(grid[i])) {
      ++count;
    }
  }
  return count;
}


/*
This function calls the result() function and from its return value, its determines who has won, 'O' for the robot and 'X' for the human player.
It also calls the checkCount function to check for ties or when we've run out of cells to fill out.
*/
char checkWinner(char grid[]) {
  char winner;
  while (TRUE) {
    if ((winner = result(grid))) { // only true if it's anything besides 0
      if (winner == PLAYER) {
        printf("\nYou won, congrats on your hollow victory!\n");
      } else if (winner == OPPONENT) {
        printf("\nThe robot won. The AI overlords are laughing at your "
               "failure. Shame!\n");
      }
      printGrid(grid);
      return winner;
    }
    // Tie condition
    if (checkCount(grid) < 1) {
      printf("\nIt was a tie. you tied with an ai that cannot even comprehend "
             "what it does. good job ;(.\n");
      return 1;
    }
    return -1;
  }
}



/*
  This Function has to iterate over the grid array and override its elements,
  can't just say grid = {'1',...,'9'} Simple trick that converts 0-9 to its
  character equivalent by adding 49 to them.
*/
void setupBoard(char grid[]) {
  for (int i = 0; i < GRID_SIZE; ++i)
    grid[i] = i + 45;
}
