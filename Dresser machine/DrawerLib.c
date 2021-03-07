#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SockLib.h"
#include"SortLib.h"
#include"DrawerLib.h"
#include"DresserLib.h"


int GetDrawer(Sockdrawer Dresser[])
{
    int drawID;
    int id = 0;

    do
    {
    	scanf(" %d",&drawID);
    	if(drawID <=0 || drawID >NumDrawers)
    	{
    		printf("\nThat is not one of your drawers!\n\n");

    	}
    }while(drawID <=0 || drawID > NumDrawers);

    while(drawID != Dresser[id].DrawerID)
    {
    	id++;
    }
    return id;
}
void GetNumDrawers()
{
    int i;
    do
    {
    	printf("How many drawers does your dresser have? (1-10) ");
    	scanf(" %d",&NumDrawers);
    	if(NumDrawers<0||NumDrawers>10)
    	{
    		printf("\nNumber of drawers must be between 1 and 10.Please reenter.\nHow many drawers does your dresser have?(1-10) ");
    	}
        
    }while(NumDrawers<0||NumDrawers>10);
}
void CreateDrawer(Sockdrawer *p)
{
    int j=0;
    p->DrawerID = NumDrawers+1;
    printf("\nHow many total socks will fit in Drawer %d ",p->DrawerID);
    scanf(" %d",&(p->MaxDrawerCapacity));
    printf("\nHow many socks are you putting in Drawer  ");
    scanf(" %d",&(p->NumberOfSocks));
    j=(p->NumberOfSocks)-(p->MaxDrawerCapacity);
    if((p->NumberOfSocks)>(p->MaxDrawerCapacity))
    {
         printf("\n%d socks fit in the drawer and %d fell on the floor\n", p->MaxDrawerCapacity,j);
         p->NumberOfSocks=p->MaxDrawerCapacity;
    }
    printf("What color are the socks in Drawer  ");
    scanf(" %s",(p->SockColor));
    
}

