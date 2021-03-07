#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include "GameLib.h"
#define STRIKES 3
#define MAX_INPUT 81
void DashIt(char *phrase,char Dashphrase[MAX_INPUT]);
void StartGame(char Chosenphrase[]);
void checkphrase(char *phrase);
int GuessALetter(char *phrase,char *Dashphrase,char *Upperphrase);
void StartGame(char Chosenphrase[MAX_INPUT])
{
    
    int i=0;
    int j=0;
    char Dashphrase[MAX_INPUT]={};
    char *PhraseBank[MAX_INPUT]={"Aditya","Chaudhari","Devil","walt","do you bleed",""};
    printf("Welcome to 3 STRIKES - YOU'RE OUT - the CSE version\n\n");
    printf("Please pick a phrase from the following menu\n\n");
    // printf("%c",Dashphrase);
    //printf("flag");
    while(PhraseBank[i] != "")
    {
        //printf("flag");
        checkphrase(PhraseBank[i]);
        DashIt(PhraseBank[i],Dashphrase);
        printf("\n%d. %s",i+1,Dashphrase);
        i++;
        
    }
    printf("\nEnter choice : ");
    scanf("%d",&j);
    if(j<0||j>strlen(*PhraseBank))
    {
        printf("Enter a valid choice ");
    }
    else
    {
        strcpy(Chosenphrase, PhraseBank[j]);
        printf("\n\nHere's the phrase you need to guess\n\n");
        printf("%s\n",Dashphrase);
    }
    strcpy(Chosenphrase, PhraseBank[j]);
}

void checkphrase(char *phrase)
{

    char *c="";
    int i=0;
    int j=0;
    c = strchr(phrase,'-');
    if(c != NULL)
    {
        while(j==0)
        {
            for(i=0;i<strlen(phrase);i++)
            {
                if(phrase[i]=='-')
                {
                    j=1;
                    //i=strlen(phrase);
                    printf("Phrase %s contains a dash in position %d !!\n",phrase, i);
                    printf("You broke the rules.  We can't play.  BYE!!");
                    exit(0);
                }
            }
            
        }
    }
    
}
int GuessALetter(char phrase[],char Dashedphrase[],char Upperphrase[])
{
    int i=0;
    char Guess;
    char *Findguess=NULL;
    char UpperphraseCopy[MAX_INPUT]={};
    int  FoundALetter=0;
    strcpy(UpperphraseCopy,Upperphrase);
    printf("%s",Dashedphrase);
    printf("Guess a letter : ");
    scanf(" %c",&Guess);
    Guess=toupper(Guess);
    Findguess=strchr( UpperphraseCopy,Guess);
    while(Findguess!=NULL)
    {
        FoundALetter=1;
        for(i=0;i<strlen(UpperphraseCopy);i++)
        {
            if(Findguess== &UpperphraseCopy[i])
            {
                Dashedphrase[i]=phrase[i];
                UpperphraseCopy[i]= '-';
            }
        }
        Findguess=strchr( UpperphraseCopy,Guess);
    }
    return FoundALetter;
}
void DashIt(char *phrase,char Dashphrase[MAX_INPUT])
{
    int m;
    for(m=0;m<strlen(phrase);m++)
    {
        Dashphrase[m]= toupper(phrase[m]);
    }
    int n =0;
    int i =0;
    Dashphrase[strlen(phrase)] = '\0';
    
    while(n < strlen(Dashphrase))
    {
        char *ptr = strpbrk(Dashphrase,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        if(ptr!=NULL)
        {
            for(i=0;i<strlen(Dashphrase);i++)
            {
                if(Dashphrase[i]==*ptr)
                {
                    Dashphrase[i] = '-';
                }
            }
        }
        n++;
        
    }
}

