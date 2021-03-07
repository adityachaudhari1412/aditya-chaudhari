//Aditya Chaudhari , 1001747134
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define SIZE 20
void instruction()
{
    printf("Draw commands start with\n\n\n\tP for a single point\n\n\tH for a horizontal line\n\n\tV for a vertical line\n\n\n");
    printf("After the P/V/H, enter a row,col coordinate and the number of spots to mark\n\nenclosed in () and separated by commas and then the character for the mark.\n\n");
    printf("'X' will be used if a mark is not entered. For example,\n\n\n\tP(2,3,1)* \tstart at point 2,3 in the array and mark one spot\n\n\t\t\t");
    printf("with an *. For P, the 3rd parameter is ignored.\n\n\n\tV(1,2,3)$ \tstart at point 1,2 in the array and mark the next\n\n\t\t\t");
    printf("3 spots down from the current position with $\n\n\n\tH(4,6,7)#\tstart at point 4,6 in the array and mark the next\n\n\t\t\t");
    printf("7 spots to the right with #\n\n\nCoordinates out of range and lines drawn past the borders are not allowed.\n\n\n");
    printf("Enter q at the draw command prompt to quit\n\n\n");
    printf("\n\nPress ENTER to continue\n\n");
    fflush(stdout);
    char enter = 0;
    
    while (enter != '\r' && enter != '\n')
    {
         enter = getchar();
    }
}
void map(int* m,char Mychar[][SIZE])
{
    int i=0;
    int j=0;
    char n='X';

    printf("How big is the array? (Enter a value between 1 and 20)  ");
    scanf("%d",m);
    //fflush(stdout);

    while(*m > SIZE || *m < 2)
    {
        printf("\n\nThat value is outside of the max bounds of the array. Please reenter");
        printf("\n\nHow big is the array? (Enter a value between 1 and 20)  ");
        scanf("%d",m);

    }
    printf("What is the background character? ");
    fflush(stdout);
    scanf(" %c",&n);
    if(n == '\r' && n == '\n')
    {
        n='X';
    }
    for(i=0;i<*m;i++)
    {
        for(j=0;j<*m;j++)
        {
            *(*(Mychar+i)+j)=n;
        }
    }
}
void printmap(int *m,char Mychar[][SIZE])
{
    int i=0;
    int j=0;
    char enter;
    scanf("%c", &enter);   
    if(enter==10)
    {
        for(i=0;i<*m;i++)
        {
            for(j=0;j<*m;j++)
            {
                printf("  %c",*(*(Mychar+i)+j));
            }
            printf("\n");
        }
    }
}

void drawLines(int *m, char Mychar[][SIZE])
{
    char Command[9];
    int count;
    int i;
    int j;
    int k;
    char arr[SIZE];
    char drawLine;
    char symbol;
    int start;
    int end;
    int num;
    char p;
    do
    {
        printf("Enter draw command (enter ctrl+c to quit)");
        scanf("%s",Command);
        if(strlen(Command) >=9)
        {
            char *token =NULL;
            token = strtok(Command, "(");
            drawLine = token[0];
            start = atoi(strtok(NULL, ","));
            end = atoi(strtok(NULL, ","));
            num = atoi(strtok(NULL, ")"));
            token = strtok(NULL, ")");
            symbol = token[0];
        }
        printf("\n\n");
        if(end>*m || start>*m || start<0 || end < 0)
        { 
            printf("That draw command is out of range\n");
        }
        else if(drawLine=='P' || drawLine=='p')
        { 
            *(*(Mychar + start)+end) = symbol;
            printmap(m,Mychar);
        }
        else if(drawLine == 'H' || drawLine == 'h')
        {
            if(end+num <= *m && num > 0)
            {
                i=start;
                j=end;
                for(k=j;k<j+num;k++)
                {
                    *(*(Mychar+i)+k)=symbol;
                }
                printmap(m,Mychar);
            }
            else
            {
                printf("That draw command is out of range\n");
            }
        }
        else if(drawLine == 'V' || drawLine == 'v')
        {
            if(start+num <= *m && num > 0)
            {

                i = start;
                j = end;

                for(k=i;k<i+num;k++)
                {
                    *(*(Mychar+k)+j)=symbol;
                }
                printmap(m,Mychar);
            }
            else
            {
                printf("That draw command is out of range\n");
            }
        }
    }while(Command!="Q" || Command!="q");
}



