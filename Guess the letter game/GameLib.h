//Aditya chaudhari, 1001747134
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_INPUT 81
#define STRIKES 3
#ifndef _GameLib_H
#define _GameLib_H

void DashIt(char *phrase,char Dashphrase[MAX_INPUT]);
void StartGame(char Chosenphrase[]);
void checkphrase(char *phrase);
int GuessALetter(char *phrase,char *Dashphrase,char *Upperphrase);
void StartGame(char Chosenphrase[MAX_INPUT]);


#endif

