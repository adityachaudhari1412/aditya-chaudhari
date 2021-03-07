#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SockLib.h"
#include"SortLib.h"
#include"DrawerLib.h"
#include"DresserLib.h"
void SortMySocks(Sockdrawer Dresser[])
{
    int choice;
    int (*CompareFunction[4]) (const void *, const void *) = {DrawerIDCompare, NumberOfSocksCompare, MaxCapacityCompare, SockColorCompare};
    printf("Do you want to sort by\n\n");
    printf("0. Changed my mind - don't want to sort\n1. Drawer ID?\n2. Number of socks in drawer?\n3. Max capacity of the drawers?\n4. Sock color?\n\n");
    do
    {
        printf("Choice : ");
        scanf("%d",&choice);
        if(choice==0)
        {
            printf("\n\nYour sock drawer is a mess!\n\n\n");
        }
        else
        {
            qsort(Dresser, NumDrawers, sizeof(Sockdrawer),(*CompareFunction[choice-1]));
        }
    }while(choice);
}
void PutAwayMySocks(Sockdrawer Dresser[])
{
    int i;
    int j;
    int m;
    int n;
    printf("Which drawer are you putting socks into?  ");
    i = GetDrawer(Dresser);
    printf("How many socks are you putting in Drawer  ? ");
    scanf("%d",&n);
    m=Dresser[i].NumberOfSocks+n;
    if(m> Dresser[i].MaxDrawerCapacity)
    {
        j=m-Dresser[i].MaxDrawerCapacity;
        Dresser[i].NumberOfSocks=m;
        printf("%d socks fit in the drawer and %d fell on the floor", Dresser[i].NumberOfSocks,j);
    }
    else
    {
        Dresser[i].NumberOfSocks=m;
    }
}
void PutOnMySocks(Sockdrawer Dresser[])
{

	printf("Which drawer are you taking out socks from?  ");
    int m = GetDrawer(Dresser);
    int i;
    int j;
    printf("How many socks are you taking out?  ");
    scanf("%d",&i);
    j=Dresser[m].NumberOfSocks-i;
    if(i>Dresser[m].MaxDrawerCapacity)
    {
        printf("You don't have that many socks!!  You only get %d socks.",Dresser[m].NumberOfSocks);
        Dresser[m].NumberOfSocks = 0;
    }
    else
    {
        Dresser[m].NumberOfSocks=j;
    }
}



