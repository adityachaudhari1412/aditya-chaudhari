
#ifndef _SOCKLIB_H
#define _SOCKLIB_H

#define MAX_DRAWERS 10

typedef struct  SockDrawer
{
    int  DrawerID;
    int NumberOfSocks;
    char  SockColor[40];
    int  MaxDrawerCapacity;
}Sockdrawer;

void SortMySocks(Sockdrawer Dresser[]);
void PutAwayMySocks(Sockdrawer Dresser[]);
void PutOnMySocks(Sockdrawer Dresser[]);

#endif

