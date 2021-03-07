#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SockLib.h"
#include"SortLib.h"
#include"DrawerLib.h"
#include"DresserLib.h"

int SockColorCompare(const void *a, const void *b)
{
    return(strcmp(((Sockdrawer*)a)->SockColor,((Sockdrawer*)b)->SockColor));
}
int DrawerIDCompare(const void *a, const void *b)
{
    return(((Sockdrawer*)a)->DrawerID > ((Sockdrawer*)b)->DrawerID);
}
int NumberOfSocksCompare(const void *a, const void *b)
{
    return(((Sockdrawer*)a)->NumberOfSocks > ((Sockdrawer*)b)-> NumberOfSocks);
}
int MaxCapacityCompare(const void *a, const void *b)
{
    return(((Sockdrawer*)a)->MaxDrawerCapacity > ((Sockdrawer*)b)-> MaxDrawerCapacity);
}