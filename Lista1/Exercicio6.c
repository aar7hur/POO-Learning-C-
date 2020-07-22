/**
 * TIC TAC TOE implemented in c language
 * Author: Arthur Munhoz Amaral
 * Date: 21/07/2020
 * GRR20177243
 * Language: C
 * Programação Orientada a Objeto
 * 
 * Purpose: IMplement Tic Tac Toe in C.
 **/

/*********************************************************************
 * 
 *   INCLUDES
 * 
 ********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

/*********************************************************************
 * 
 *   DEFINES
 * 
 ********************************************************************/
#define ROWS 3
#define COLS 3
#define SIZE 3
#define MIN_NUMBER_MOVES_WIN 5
#define MAX_NUMBER_MOVES 9

/*********************************************************************
 * 
 *   ENUMS AND TYPEDEFS
 * 
 ********************************************************************/
enum GameState {
    X_PLAYING,
    O_PLAYING,
    X_WON,
    O_WON,
    DRAW,
} state;

typedef enum {
    A,
    B,
    C
} InputUser;

typedef unsigned int uint;
/*********************************************************************
 * 
 *   FUNCTIONS
 * 
 ********************************************************************/

void instructions();
void verifyInput(char row, char col, char **myBoard);
InputUser getEnumFromString(const char s);
void playGame(char **myBoard, int row, int col);
void printTable(char **myBoard);
char **createBoard();
void verifyDiagonal(char **myBoard);
void verifyLineAndColumn(char **myBoard);
void setEnumState(char movement);
void verifyWinner();
void updateTerminal();

/*********************************************************************
 * 
 *   VARIABLES
 * 
 ********************************************************************/
const char xPlay = 'X';
const char oPlay = 'O';
const char initState = ' ';
int moves;
bool validMovement;
int rowPosition, colPosition;

/** Main Function **/
int main()
{
    instructions();
    char row, col;
    char **myBoard = createBoard();
    state = X_PLAYING;
    moves = 1;
    validMovement = false;
    
    while(state == X_PLAYING || state == O_PLAYING)
    {   
        while(validMovement != true)
        {
            printf("Choose where you want to play:\n ");
            fflush(stdout);
            scanf(" %c%c", &row, &col);
        
            verifyInput(row, col, myBoard);
        }
        playGame(myBoard, rowPosition, colPosition);   
    }
    verifyWinner();
    free(myBoard);
    return EXIT_SUCCESS;
}

/*********************************************************************
 *   Function: verifyWinner
 * ----------------------
 * Verify enum state to decide who won
 *
 * returns: nothing. Void functions
 ********************************************************************/
void verifyWinner()
{
    char *outputLog;
    
    switch(state)
    {
        case X_WON:
            outputLog = "X Winner!!";
            break;
        case O_WON:
            outputLog = "O Winner!!";
            break;
        case DRAW:
            outputLog = "DRAW";
            break;
    }
    printf("\n\nThe game is over. The result was ---> \t%s\n", outputLog);
}

/*********************************************************************
 * Function: verifyInput
 * ----------------------
 * Checks the user's entry.
 * Checks if the entry was a letter between A and C 
 * and also checks if the play field is valid
 *
 * returns: nothing. Void function
 ********************************************************************/
void verifyInput(char row, char col, char **myboard)
{
    if((row >= 'a' && row <= 'c') || (col >='a' && col <= 'c'))
    {
        row = (char)toupper(row);
        col = (char)toupper(col);
    }
    if((row >= 'A' && row <= 'C') && (col >='A' && col <= 'C'))
    {
        rowPosition = getEnumFromString((char)row);
        colPosition = getEnumFromString((char)col);
        if (myboard[rowPosition][colPosition] != ' ')
        {
            printf("Invalid play! This field has already been used to make a move\n");

        }
        else
        {
            validMovement = true;
        }
    }
    else
    {
     printf("Invalid play! Please enter the rows and columns between A and C\n");
       
    }  
}
/*********************************************************************
 * Function: getEnumFromString
 * ----------------------
 * Converts the character typed by the user into a 
 * valid row and column number by accessing an static
 * struct.
 * 
 * const char s: User input.
 *
 * returns: An Enum type that refers to line and column
 ********************************************************************/
InputUser getEnumFromString(const char s)
{
    uint i;
    static struct {
        const char s;
        InputUser input;
    } map[] = {
        { 'A', A },
        { 'B', B },
        { 'C', C },
    };
   
    for (i = 0 ; i < sizeof(map)/sizeof(map[0]); i++) 
    {
        if (s == map[i].s) 
        {
            return map[i].input;
        }
    }
}
/*********************************************************************
 * Function: verifyLineAndColumn
 * ----------------------
 * Check each row and column to try to identify a 
 * row or column with equal moves. If this happens, 
 * read the row or column in question and decide to 
 * change the state of the 'state' flag
 * 
 * char **myBoard: pointer wto the board
 * 
 * returns: Nothing. Void function
 ********************************************************************/
void verifyLineAndColumn(char **myBoard)
{   
    uint row = 1, aux = 1;
    uint line[3], column[3];
    uint countLine = 0, countCol = 0;
    bool isLineEqual;
    char result;

    while (aux <= SIZE)
    {   
        line[row-1] = myBoard[aux-1][row-1];
        column[row-1] = myBoard[row-1][aux-1];
        if((row % SIZE) == 0)
        {
            row = 0;
            aux++;
            
            for(row; row < SIZE; row++)
            {
                if(!(line[row] == ' '))
                {
                    countLine++;
                    
                }
                if(!(column[row] == ' '))
                {
                    countCol++;
                }
            }
            row = 0;
            if (countCol == SIZE)
            {
                if((column[row] == column[row+1]) && (column[row+1] == column[row+2]))
                {
                    result = column[row];
                    setEnumState(result);
                    break;
                }
            }
            if (countLine == SIZE)
            {
                if((line[row] == line[row+1]) && (line[row+1] == line[row+2]))
                {
                    result = line[row];
                    setEnumState(result);
                    break;
                }
            }
            countLine = 0;
            countCol = 0;
        }
        row++;
    }
}
/*********************************************************************
 * Function: setEnumState
 * ----------------------
 * Checks the flag state.
 * Checks the caracter to set the enum's flag
 *
 * char movement: Character that will be read to set the flag status
 * 
 * returns: nothing. Void function
 ********************************************************************/
void  setEnumState(char movement)
{
    if ((movement != xPlay) && (movement != oPlay))
    {
        return;
    }
    else if (movement == xPlay)
    {
        state = X_WON;
    }
    else if (movement == oPlay)
    {
        state = O_WON;
    }
}
/*********************************************************************
 * Function: verifyDiagonal
 * ----------------------
 * Check each foward and reverse diagonal to find
 * the one with all equal moves. If this happens, 
 * read diagonal in question and decide to 
 * change the state of the 'state' flag
 *  
 * char **myBoard: pointer wto the board
 * 
 * returns: Nothing. Void function
 ********************************************************************/
void verifyDiagonal(char **myBoard)
{   
    uint fwDiag[3], revDiag[3];
    char initFowarValue = myBoard[0][0];
    char initReverValue = myBoard[0][2];
    char result;
    uint aux = SIZE -1; 
    uint countRev, countFw;
    uint row;
    
    for (row = 0; row < SIZE; row++)
    {   
        fwDiag[row] = myBoard[row][row]; 
        revDiag[row] = myBoard[row][aux-row];
    }
   
    countRev = 0;
    countFw = 0;
    for (row = 0; row < SIZE; row++)
    {
        if (fwDiag[row] == initFowarValue)
            countFw++;
        
        if (revDiag[row] == initReverValue)
            countRev++;
    }
    if (countFw == SIZE)
        result = initFowarValue;
       
    else if (countRev == SIZE)
        result = initReverValue;

    setEnumState(result); 
}
/*********************************************************************
 * Function: playGame
 * ----------------------
 * Receives a board position, assigns that position 
 * to the player (X or 0), draws the table in the 
 * terminal and makes the winner checks.
 *  
 * int row: position of the line to be played
 * int col: ṕsition of the col to be played
 *
 * char **myBoard: pointer wto the board
 * 
 * returns: Nothing. Void function
 ********************************************************************/
void playGame(char **myBoard, int row, int col)
{
    char playAux;

    if (state == X_PLAYING)
    {   
        playAux = xPlay;
        state = O_PLAYING;
    }
    else if(state == O_PLAYING)
    {
        playAux = oPlay;
        state = X_PLAYING;
    }

    myBoard[row][col] = playAux;
    printTable(myBoard);
   
    if(moves >= MIN_NUMBER_MOVES_WIN)
    {
       verifyDiagonal(myBoard);
       verifyLineAndColumn(myBoard);
    }
    if(((moves == MAX_NUMBER_MOVES) && (state != X_WON) && (state != O_WON)))
    {
        state = DRAW;
    }
    moves++;
    validMovement = false;
}
/*********************************************************************
 * Function: createBoard
 * ----------------------
 * Allocates a memory position for 3 char to 
 * form the board. In each position 3 more chars 
 * are allocated, thus forming a 2D 3x3 array.
 * Also, start each matrix position with ''.
 *
 * returns: Board --> the matrix itself
 ********************************************************************/
char **createBoard()
{
    char **board; 
    board = (char**) malloc(SIZE * sizeof(char*));
    uint row;
    uint col;

    for(row = 0 ; row < SIZE; row++)
    {
        board[row] = (char*) malloc(SIZE * sizeof(char));
    }

    for (row = 0; row < SIZE; row++)
    {
        for (col = 0; col < SIZE; col++)
        {
            board[row][col] = initState;
        }
    }
    return board;
}
/*********************************************************************
 * Function: createBoard
 * ----------------------
 * Go through each position of the matrix and 
 * show it on the screen while the game is played
 *
 * char **myBoard: pointer wto the board
 *
 * returns: Nothing. Vvoid function
 ********************************************************************/
void printTable(char **myBoard)
{
    uint row, col;

    updateTerminal();
    printf("\n  _________________ \n");
    printf(" |  A  |  B  |  C  |");
    printf("\n |_________________| \n");
    for(row = 0; row < SIZE; ++row) 
    {
        printf("%c|", 'A' + row);
        for(col = 0; col < SIZE; ++col) 
        {
            printf("  %c  |", myBoard[row][col]);
        }
        printf("\n");
    }
   
}
/*********************************************************************
 * Function: updateTerminal
 * ----------------------
 * Checks which operating system it is and cleans the terminal
 * 
 * returns: Nothing. Vvoid function
 ********************************************************************/
void updateTerminal()
{
    #ifdef _WIN32 
	    system("cls");
    #else
	    system("clear");
    #endif
}
/********************************************************************* 
 * Function Instructions()
 * ------------------------
 * Show instructions to user at the moment
 * that game is started
 *
 * returns: Nothing. Void function
 ********************************************************************/
void instructions()
{
    printf("To play tic tac toe, some instructions must be defined:\n");
    printf("The positions must follow the following format:\n");
    printf("  |  A    B    C |\n");
    printf("  |______________|\n");
    printf(" A| AA | AB | AC |\n");
    printf("  |______________|\n");
    printf(" B| BA | BB | BC |\n");
    printf("  |______________|\n");
    printf(" C| CA | CB | CC |\n");
    printf("  |______________|\n");
    printf("\n\nExample: \nTo play in row 1 column 1, just write AA\n");
    printf("The game will begin\n\n");
}