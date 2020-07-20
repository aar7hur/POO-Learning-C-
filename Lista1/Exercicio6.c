/**
 * TIC TAC TOE implemented in c language
 * Author: Arthur Munhoz Amaral
 **/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define ROWS 3
#define COLS 3
#define SIZE 3
#define MIN_NUMBER_MOVES_WIN 5
#define MAX_NUMBER_MOVES 9

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

void instructions();
void verifyInput(char row, char col, char **myBoard);
InputUser getEnumFromString(const char s);
void playGame(char **myBoard, int row, int col);
void printTable(char **myBoard);
char **createBoard();
void verifyDiagonal(char **myBoard);
void verifyLineAndColumn(char **myBoard);
void verifyEnumState(char movement);
void verifyWinner();
void updateTerminal();
extern void perror (const char *__s);

const char xPlay = 'X';
const char oPlay = 'O';
const char initState = ' ';
int moves;
bool validMovement;
int rowPosition, colPosition;


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
    return EXIT_SUCCESS;
}

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

void verifyInput(char row, char col, char **myboard)
{
    
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

InputUser getEnumFromString(const char s)
{
   static struct {
        const char s;
        InputUser input;
    } map[] = {
        { 'A', A },
        { 'B', B },
        { 'C', C },
    };
   
    for (uint i = 0 ; i < sizeof(map)/sizeof(map[0]); i++) 
    {
        if (s == map[i].s) 
        {
            return map[i].input;
        }
    }
}

void verifyLineAndColumn(char **myBoard)
{   
    uint row = 1;
    uint line[3], column[3];
    uint aux = 1;
    uint countLine = 0;
    uint countCol = 0;
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
                    verifyEnumState(result);
                    break;
                }
            }
            if (countLine == SIZE)
            {
                if((line[row] == line[row+1]) && (line[row+1] == line[row+2]))
                {
                    result = line[row];
                    verifyEnumState(result);
                    break;
                }
            }
            countLine = 0;
            countCol = 0;
        }
        row++;
    }
}

void verifyEnumState(char movement)
{
    if (movement == xPlay)
    {
        state = X_WON;
    }
    else if (movement == oPlay)
    {
        state = O_WON;
    }
    else
    {
        state = DRAW;
    }  
}

void verifyDiagonal(char **myBoard)
{   
    int fwDiag[3], revDiag[3];
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
     
    if (result == xPlay)
    {
        state = X_WON;  
    }
    else if(result == oPlay)
    {
        state = O_WON;     
    }
}

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
    if(moves == MAX_NUMBER_MOVES)
    {
        state = DRAW;
    }
    moves++;
    validMovement = false;
}

char **createBoard()
{
    char **board; 
    board = (char**) malloc(SIZE * sizeof(char*));
    uint row;

    for(row = 0 ; row < SIZE; row++)
    {
        board[row] = (char*) malloc(SIZE * sizeof(char));
    }

    for (row = 0; row < SIZE; row++)
    {
        for (uint col = 0; col < SIZE; col++)
        {
            board[row][col] = initState;
        }
    }

    return board;
}

void printTable(char **myBoard)
{
    updateTerminal();
    printf("\n  _________________ \n");
    printf(" |  A  |  B  |  C  |");
    printf("\n |_________________| \n");
    for(uint i = 0; i < SIZE; ++i) 
    {
        printf("%c|", 'A' + i);
        for(uint j = 0; j < SIZE; ++j) 
        {
            printf("  %c  |", myBoard[i][j]);
        }
        printf("\n");
    }
   
}

void updateTerminal()
{
    #ifdef _WIN32 
	    system("cls");
    #else
	    system("clear");
    #endif
}

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
