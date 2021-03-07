/*Aditya Chaudhari, 1001747134*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
int globleArray[25];
int counter = 0;

void fillRandoms(int lower, int a[75]) 
{ 
    
    int i; 
    
    int num=0;

    
    for (i = 0; i < 5; i++)
    {
	   num=(rand() % 15) + lower;
	   while(a[num]==1)
	   {
	   num= (rand() % 15) + lower;
	   }
	    a[num]=1;
        globleArray[counter]=num;

        counter++;
    } 

} 
void printArr(int bingo[5][5])
{
	printf("\n\tB\t\tI\t\tN\t\tG\t\tO\t");
    int o,u;
    for (o= 0; o <5 ; o++) 
    {
        printf("\n--------------------------------------------------------------------------------");
        printf("\n");
        for (u = 0; u < 5; u++) 
		{
            if(bingo[o][u]==0)
			{
                printf("|\tX\t");
                continue;
            }
        
        printf("|\t%d\t",bingo[o][u]);
        
        }
       printf("|");
        
    }
    printf("\n--------------------------------------------------------------------------------\n");
}

int giveValue(int k, int bingo[5][5])
{
    int i=0;
    int j=0;
    for(i=0;i<5;i++)
	{
        for(j=0;j<5;j++)
		{
            if(bingo[i][j]==k)
			{
                bingo[i][j]=0;
                return 0;
                
            }
           
        }
    }
    return 1;

}
int pickNumber(int bingo[5][5])
{
    int num;
    char select;

    num = rand() % 76;
    if(num<16)
    {
        printf("The next number is B%d",num);
    }
    else if(num > 15 && num <=30)
    {
        printf("The next number is I%d",num);
    }
    else if(num > 30 && num <= 45)
    {
        printf("The next number is N%d",num);
    }
    else if(num > 45 && num <= 60)
    {
        printf("The next number is G%d",num);
    }
    else if(num > 60 && num <= 75)
    {
        printf("The next number is O%d",num);
    }
    printf("\nDo you have it? (Y/N):");
    
    fflush(stdin);
    scanf("%c",&select);
    fflush(stdin);
    if(giveValue(num,bingo) && (select=='y'||select=='Y'))
    {
         printf("That value is not on your BINGO card - are you trying to cheat??\n\n");
    }
    fflush(stdin);
    return num;
    
}
int main()
{   
    int k=0;
    int l;
    int count = 0;
    int m;
    int bingo[5][5];
    int a[75];
    int i=0;
    for(i=0;i<75;i++)
	{
        a[i]=0;
    }
    
    fillRandoms(1,a);
    fillRandoms(16,a);
    fillRandoms(31,a);
    fillRandoms(46,a);
    fillRandoms(61,a);
    
    for(l=0;l<5;l++)
    {
		for(m=0;m<5;m++)
		{
			bingo[m][l] = globleArray[k];
			k++;
        }
    }
    bingo[2][2]=0;
    while(count<75)
    {

        printArr(bingo);
        pickNumber(bingo);
        fflush(stdin);
        count++;

    }
    
    
    return 0;
}

