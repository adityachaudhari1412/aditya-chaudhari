//Aditya Chaudhari, 1001747134
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "GameLib.h"
#define STRIKES 3
#define MAX_INPUT 81
int main()
{
    char phrase[MAX_INPUT]={};
    char Dashedphrase[MAX_INPUT]={};
    char Upperphrase[MAX_INPUT]={};
    char Chosenphrase[MAX_INPUT]={};
    int strike=0;
    int i;
    char Dashphrase[MAX_INPUT]={};
    StartGame(phrase);
    DashIt(Chosenphrase,Dashedphrase);
    for(i=0;i<strlen(phrase);i++)
    {
        Upperphrase[i]=toupper(phrase[i]);
    }
    do
    {
        if(GuessALetter(phrase,Dashedphrase,Upperphrase)==0)
        {
            strike++;
            printf("Your number of strike is %d",strike);
        }
    }while(strchr(Dashphrase,'-')!=NULL&&strike<STRIKES);
    if(strike<STRIKES)
    {
        printf("You figured it out!!\n\nThe phrase was\n\n");
        printf("%s\n\nYOU WIN!!!!",Chosenphrase);
    }
    else
    {
        printf("%d STRIKES - YOU'RE OUT!!\n\nGame over",strike);
    }
    return 0;
}

