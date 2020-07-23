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

#define MAXIMIUM_NUMBER_ACCOUNTS 15
/*********************************************************************
 * 
 *   ENUMS AND TYPEDEFS
 * 
 ********************************************************************/
 
typedef struct 
{
    char *name;
    int accountNUmber;
    float accountBalance;

}customer;
customer userCustomer[15];

typedef int (*Operation)(struct customer);

struct bank
{
    struct client *userCustomer;
    Operation opt;
   
};
/*********************************************************************
 * 
 *   FUNCTIONS
 * 
 ********************************************************************/


/*********************************************************************
 * 
 *   VARIABLES
 * 
 ********************************************************************/

/** Main Function **/

int main()
{
    struct bank *bank;
    int movement;

    bank = malloc(sizeof(*bank));
    if(bank == NULL)
    {
        printf("Cannot Allocate memory");
        return EXIT_FAILURE;
    }

    bank->userCustomer = malloc(sizeof(*(bank->userCustomer)));
    if(bank->userCustomer == NULL)
    {
        printf("Cannot Allocate memory");
        free(bank);
        return EXIT_FAILURE;
    }

    movement = createMenu();
    
   
}

int createMenu()
{
    int movement;

    printf("\n\nWelcome to the bank page\n");
    printf("Below are some instructions for you\n");
    printf("Type 1 if you want to add an account\n");
    printf("Type 2 if you want to visualize an account\n");
    printf("Type 3 if you want to delete the account with the lowest balance\n");
    printf("TYpe 4 if you want to leave\n");
    
    if(scanf("%2d", movement) != 1)
    {
        print("Invalid Input");
        exit();
    }
    else
    {
        return movement;
    }
}
void decideOperation(int movement, struct bank *bank)
{
    switch(movement)
    {
        case 1:
            bank->opt = addAccount;



        case 2:
            bank->opt = visualizeAccounts;
        case 3:
            bank->opt = deleteAccount;
        case 4:
            printf("You are leaving. Thank you!");
            exit(EXIT_SUCCESS);
    }
}
int addAccount(struct customer)
{

}

int deleteAccount(struct customer)
{

}

void visualizeAccounts()
{

}
