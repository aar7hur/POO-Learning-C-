/**
 * Program to simulate bank account
 * Author: Arthur Munhoz Amaral
 * Date: 21/07/2020
 * GRR20177243
 * Language: C
 * Programação Orientada a Objeto
 * 
 * Purpose: program to simulate bank account
 **/
/*********************************************************************
 * 
 *   INCLUDES
 * 
 ********************************************************************/
#include <stdlib.h>
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

#define MAX_DIGITS 12

/*********************************************************************
 * 
 *   ENUMS AND TYPEDEFS
 * 
 ********************************************************************/


typedef struct RationalNumber
{
    int numerator;
    int denominator;
} RationalNumber;

typedef RationalNumber *(*Operation)(int a, int b);


typedef struct Commands
{
    Operation opt;
} Commands;



/*********************************************************************
 * 
 *   FUNCTIONS
 * 
 ********************************************************************/
RationalNumber *addRational(RationalNumber *a, RationalNumber *b);
RationalNumber *subRational(RationalNumber *a, RationalNumber *b);
RationalNumber *multiplyRational(RationalNumber *a, RationalNumber *b);
RationalNumber *divideRational(RationalNumber *a, RationalNumber *b);
RationalNumber *simplifyRational(RationalNumber *rational, int n);
void *allocateMemory(size_t size);
RationalNumber *getFromUserInput();
int readStdinBuffer();
int doMMC(int a, int b);
int doMDC(int a, int b);

/*********************************************************************
 * 
 *   VARIABLES
 * 
 ********************************************************************/

/** Main Function **/

int main()
{
    Commands *command = allocateMemory(sizeof *command);
    RationalNumber *aNumber, *bNumber,*add, *sub, *div, *multiply, *simplify;

    aNumber = getFromUserInput();
    (*command).opt = simplifyRational;
    simplify = (*command).opt(aNumber, 0);
    printf("A = %d/%d", (*aNumber).numerator, (*aNumber).denominator);
    printf("  = %d/%d ", (*simplify).numerator, (*simplify).denominator);
    printf("  = %f ", (float)(*simplify).numerator / (*simplify).denominator);
    

    bNumber = getFromUserInput();
    (*command).opt = simplifyRational;
    simplify = (*command).opt(bNumber, 0);
    printf("A = %d/%d", (*bNumber).numerator, (*bNumber).denominator);
    printf("  = %d/%d ", (*simplify).numerator, (*simplify).denominator);
    printf("  = %f ", (float)(*simplify).numerator / (*simplify).denominator);
    

    (*command).opt = addRational;
    add = (*command).opt(aNumber, bNumber);
    (*command).opt = simplifyRational;
    simplify = (*command).opt(add, 0);
    printf("A + B = %d/%d ", (*add).numerator, (*add).denominator);
    printf("  = %d/%d ", (*simplify).numerator, (*simplify).denominator);
    printf("  = %f ", (float)(*simplify).numerator / (*simplify).denominator);


    (*command).opt = subRational;
    sub = (*command).opt(aNumber, bNumber);
    (*command).opt = simplifyRational;
    simplify = (*command).opt(sub, 0);
    printf("A - B = %d/%d ", (*sub).numerator, (*sub).denominator);
    printf("  = %d/%d ", (*simplify).numerator, (*simplify).denominator);
    printf("  = %f ", (float)(*simplify).numerator / (*simplify).denominator);
    
    
    (*command).opt = multiplyRational;
    multiply = (command).opt(aNumber, bNumber);
    (*command).opt = simplifyRational;
    simplify = (*command).opt(multiply, 0);
    printf("A * B = %d/%d ", (*multiply).numerator, (*multiply).denominator);
    printf("  = %d/%d ", (*simplify).numerator, (*simplify).denominator);


    (*command).opt = divideRational;
    div = (*command).opt(aNumber, bNumber);
    (*command).opt = simplifyRational;
    simplify = (*command).opt(div, 0);
    printf("A * B = %d/%d ", (*div).numerator, (*div).denominator);
    printf("  = %d/%d ", (*simplify).numerator, (*simplify).denominator);

}


RationalNumber *addRational(RationalNumber *a, RationalNumber *b)
{   
    int mmc, addNumerator1, addNumerator2;
    RationalNumber *add = allocateMemory(sizeof(*add));
    
    mmc = doMMC(a, b);
    addNumerator1 = (mmc / (*a).denominator) * (*a).numerator;
    addNumerator2 = (mmc / (*b).denominator) * (*b).numerator;

    (*add).numerator = addNumerator1 + addNumerator2;
    (*add).denominator =  mmc;

    return add;
}

RationalNumber *subRational(RationalNumber *a, RationalNumber *b)
{
    int mmc, addNumerator1, addNumerator2;
    RationalNumber *sub = allocateMemory(sizeof(*sub));
    
    mmc = doMMC(a, b);
    addNumerator1 = (mmc / (*a).denominator) * (*a).numerator;
    addNumerator2 = (mmc / (*b).denominator) * (*b).numerator;

    (*sub).numerator = addNumerator1 - addNumerator2;
    (*sub).denominator =  mmc;

    return sub;
}

RationalNumber *multiplyRational(RationalNumber *a, RationalNumber *b)
{
    RationalNumber *multiply = allocateMemory(sizeof(*multiply));

    (*multiply).numerator = (*a).numerator * (*b).numerator;
    (*multiply).denominator = (*a).denominator * (*b).denominator;

    return multiply;
}

RationalNumber *divideRational(RationalNumber *a, RationalNumber *b)
{
    RationalNumber *divide = allocateMemory(sizeof(*divide));

    (*divide).numerator = (*a).numerator * (*b).numerator;
    (*divide).denominator = (*a).denominator * (*b).denominator;

    return divide;
}

RationalNumber *simplifyRational(RationalNumber *rational, int n)
{   
    // parameter n is just for consistency
    int mdc, numerator, denominator;
    RationalNumber *simplify = allocateMemory(sizeof(*simplify));

    mdc = doMDC((*rational).numerator, (*rational).denominator);

    (*simplify).numerator = (*rational).numerator / mdc;
    (*simplify).denominator = (*rational).denominator / mdc;

    return simplify;
}

void *allocateMemory(size_t size)
{
    void *p = malloc(size);
    if(!p)
    {
        perror("Cannot allocate memory");
        exit(EXIT_FAILURE);
    }
    return p;
}

RationalNumber *getFromUserInput()
{   
    int n, d;
  
    printf("Rational Number A:\n");
    printf("Numerator:");
    n = readStdinBuffer();

    printf("Denominator:");
    d = readStdinBuffer();

    RationalNumber *rational = allocateMemory(sizeof *rational);

    (*rational).numerator = n;
    (*rational).denominator = d;

    return rational;
}

int readStdinBuffer()
{   
    int integer;
    char *inputBuffer = malloc(sizeof(char) * MAX_DIGITS);
    char *input = NULL;

    if(!(inputBuffer))
    {
        printf("Cannot allocated memory");
        exit(EXIT_FAILURE);
    }
    
    input = fgets(inputBuffer, MAX_DIGITS, stdin);
    integer = atoi(input);
    if(integer == 0)
    {
        printf("Please enter with a valid number");
    }
    return integer;
}

int doMMC(int a, int b)
{
    int initValue = 2, aux = 1;
    bool nextSequence = true;
    
    while(true)
    {
        if((a % initValue ) && (b % initValue ))
        {
            initValue++;
        }
        else if (!(a % initValue) && !(b  % initValue))   
        {
            return initValue;
        }
        else
        {
            if (!(a % initValue))
            {
                a = a / initValue;
                aux = aux * initValue
            }
            else
            {
                b = b / initValue;
                aux = aux * initValue;
            }
        }
        if (( a == 1) && (b == 1))
        {
            break;
        }
        
    }
    return aux;   
}
int doMDC(int a, int b)
{
    if (b == 0){
        return a;
    }
    else
    {
        return doMDC(b, a%b)
    }
    
}

