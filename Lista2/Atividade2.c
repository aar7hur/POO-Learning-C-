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

#define MAX_DIGITS 10

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

RationalNumber *(*operation)(RationalNumber *a, RationalNumber *b);


/*********************************************************************
 * 
 *   FUNCTIONS
 * 
 ********************************************************************/
RationalNumber *addRational(RationalNumber *a, RationalNumber *b);
RationalNumber *subRational(RationalNumber *a, RationalNumber *b);
RationalNumber *multiplyRational(RationalNumber *a, RationalNumber *b);
RationalNumber *divideRational(RationalNumber *a, RationalNumber *b);
RationalNumber *simplifyRational(RationalNumber *rational, RationalNumber *b);
void *allocateMemory(size_t size);
RationalNumber *getFromUserInput(char *outputString);
int readStdinBuffer(); 
int doMMC(int a, int b);
int doMDC(int a, int b);


/** Main Function **/

int main()
{
    
    RationalNumber *aNumber, *bNumber,*add, *sub, *div, *multiply, *simplify;

    aNumber = getFromUserInput("Rational Number A: \n");
    bNumber = getFromUserInput("Rational Number B: \n");


    operation = simplifyRational;
    simplify = (*operation)(aNumber, aNumber);
    printf("A = %d/%d", (*aNumber).numerator, (*aNumber).denominator);
    printf("  = %d/%d ", (*simplify).numerator, (*simplify).denominator);
    printf("  = %f \n", (float)(*simplify).numerator / (*simplify).denominator);
    

    operation = simplifyRational;
    simplify = (*operation)(bNumber, bNumber);
    printf("B = %d/%d", (*bNumber).numerator, (*bNumber).denominator);
    printf("  = %d/%d ", (*simplify).numerator, (*simplify).denominator);
    printf("  = %f \n", (float)(*simplify).numerator / (*simplify).denominator);
    

    operation = addRational;
    add = (*operation)(aNumber, bNumber);
    operation = simplifyRational;
    simplify = (*operation)(add, add);
    printf("A + B = %d/%d ", (*add).numerator, (*add).denominator);
    printf("  = %d/%d ", (*simplify).numerator, (*simplify).denominator);
    printf("  = %f \n", (float)(*simplify).numerator / (*simplify).denominator);


    operation = subRational;
    sub = (*operation)(aNumber, bNumber);
    operation = simplifyRational;
    simplify = (*operation)(sub, sub);
    printf("A - B = %d/%d ", (*sub).numerator, (*sub).denominator);
    printf("  = %d/%d ", (*simplify).numerator, (*simplify).denominator);
    printf("  = %f \n", (float)(*simplify).numerator / (*simplify).denominator);
    

    operation = multiplyRational;
    multiply = (*operation)(aNumber, bNumber);
    operation = simplifyRational;
    simplify = (*operation)(multiply, 0);
    printf("A * B = %d/%d ", (*multiply).numerator, (*multiply).denominator);
    printf("  = %d/%d ", (*simplify).numerator, (*simplify).denominator);
    printf("  = %f \n", (float)(*simplify).numerator / (*simplify).denominator);


    operation = divideRational;
    div = (*operation)(aNumber, bNumber);
    operation = simplifyRational;
    simplify = (*operation)(div, div);
    printf("A / B = %d/%d ", (*div).numerator, (*div).denominator);
    printf("  = %d/%d ", (*simplify).numerator, (*simplify).denominator);
    printf("  = %f \n", (float)(*simplify).numerator / (*simplify).denominator);

}

/*********************************************************************
 *   Function: addRational
 * ----------------------
 * Function that receive two pointers to numbers, adds them and returns
 * a pointer to memory where the result was allocated.
 *
 * returns: a pointer
 ********************************************************************/

RationalNumber *addRational(RationalNumber *a, RationalNumber *b)
{   
    int mmc, addNumerator1, addNumerator2;
    RationalNumber *add = allocateMemory(sizeof(*add));
    
    mmc = doMMC((*a).denominator,(*b).denominator);
    addNumerator1 = (mmc / (*a).denominator) * (*a).numerator;
    addNumerator2 = (mmc / (*b).denominator) * (*b).numerator;

    (*add).numerator = (addNumerator1 + addNumerator2);
    (*add).denominator =  mmc;

    return add;
}

/*********************************************************************
 *   Function: subRational
 * ----------------------
 * Function that receive two pointers to numbers, subtracts them and returns
 * a pointer to memory where the result was allocated.
 *
 * returns: a pointer
 ********************************************************************/
RationalNumber *subRational(RationalNumber *a, RationalNumber *b)
{
    int mmc, addNumerator1, addNumerator2;
    RationalNumber *sub = allocateMemory(sizeof(*sub));
    
    mmc = doMMC((*a).denominator, (*b).denominator);
    addNumerator1 = (mmc / (*a).denominator) * (*a).numerator;
    addNumerator2 = (mmc / (*b).denominator) * (*b).numerator;

    (*sub).numerator = addNumerator1 - addNumerator2;
    (*sub).denominator =  mmc;

    return sub;
}


/*********************************************************************
 *   Function: miltiplyRational
 * ----------------------
 * Function that receive two pointers to numbers, multiplies them and returns
 * a pointer to memory where the result was allocated.
 *
 * returns: a pointer
 *  ********************************************************************/
RationalNumber *multiplyRational(RationalNumber *a, RationalNumber *b)
{
    RationalNumber *multiply = allocateMemory(sizeof(*multiply));

    (*multiply).numerator = (*a).numerator * (*b).numerator;
    (*multiply).denominator = (*a).denominator * (*b).denominator;

    return multiply;
}

/*********************************************************************
 *   Function: divideRational
 * ----------------------
 * Function that receive two pointers to numbers, divides them and returns
 * a pointer to memory where the result was allocated.
 *
 * returns: a pointer
 *  ********************************************************************/
RationalNumber *divideRational(RationalNumber *a, RationalNumber *b)
{
    RationalNumber *divide = allocateMemory(sizeof(*divide));

    (*divide).numerator = (*a).numerator * (*b).denominator;
    (*divide).denominator = (*a).denominator * (*b).numerator;

    return divide;
}

/*********************************************************************
 *   Function: simplifyRational
 * ----------------------
 * Function that receive a pointer to number, do te simplification and
 * returns a pointer to memory where the result was allocated.
 *
 * returns: a pointer
 *  ********************************************************************/
RationalNumber *simplifyRational(RationalNumber *rational, RationalNumber *b)
{   
    // parameter RationalNumber *b is just for consistency
    int mdc, numerator, denominator;
    RationalNumber *simplify = allocateMemory(sizeof(*simplify));

    mdc = doMDC((*rational).numerator, (*rational).denominator);

    (*simplify).numerator = (*rational).numerator / mdc;
    (*simplify).denominator = (*rational).denominator / mdc;

    return simplify;
}

/*********************************************************************
 *   Function: allocateMemory
 * ----------------------
 * Function that receive an size, allocates a pointer to memory with the
 * specified size and returns a pointer.
 *
 * returns: a pointer
 *  ********************************************************************/
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

/*********************************************************************
 *   Function: getFromUserInput
 * ----------------------
 * Function that receives a pointer to char, print them to terminal, allocates
 * a memory address for the number specified by the user and returns a pointer
 * to this number.
 *
 * returns: a pointer
 *  ********************************************************************/
RationalNumber *getFromUserInput(char *outputString)
{   
    int n, d = 0;
  
    printf("%s",outputString );
    printf("Numerator:");
    n = readStdinBuffer();

    printf("Denominator:");

    while(d==0)
    {
        d = readStdinBuffer();
        if (d == 0)
        {
            printf("Please enter with a valid number. The denominator must be different from 0\n");
            printf("Denominador:");
        }
    } 

    RationalNumber *rational = allocateMemory(sizeof *rational);

    (*rational).numerator = n;
    (*rational).denominator = d;

    return rational;
}
/*********************************************************************
 *   Function: readStdinBuffer
 * ----------------------
 * Function that reads string from user input by reading a char and 
 * converting to integer. This is used because scanf is a little bit
 * complicated.
 * 
 * returns: integer number
 *  ********************************************************************/
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

    return integer;
}

/*********************************************************************
 *   Function: doMMC
 * ----------------------
 * Function that performs the MMC to add/subtract number
 * 
 * returns: integer number
 *  ********************************************************************/
int doMMC(int a, int b)
{
   
	return a*b/doMDC(a,b);
}

/*********************************************************************
 *   Function: doMDC
 * ----------------------
 * Function that performs the MDC to simplify number
 * 
 * returns: integer number
 *  ********************************************************************/
int doMDC(int a, int b)
{
    if (b == 0){
        return a;
    }
    else
    {
        return doMDC(b, a%b);
    }
    
}