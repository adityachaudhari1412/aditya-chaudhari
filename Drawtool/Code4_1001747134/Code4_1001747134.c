//Aditya Chaudhari, 1001747134
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DrawTool.h"
int main()
{
    int *m=malloc(sizeof(int));
    char Mychar[SIZE][SIZE];
    
    map(m,Mychar);
    instruction();
    printmap(m,Mychar);
    drawLines(m,Mychar);
    return 0;
}
