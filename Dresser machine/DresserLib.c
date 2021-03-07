#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SockLib.h"
#include"SortLib.h"
#include"DrawerLib.h"
#include"DresserLib.h"

void DisplayMyDresser(Sockdrawer Dresser[])
{
	int i= 0;
	printf("\n\nMyDresser\n");
	for(i=0;i<NumDrawers;i++)
	{
		printf("\nDrawer %d", Dresser[i].DrawerID);
		printf("\n     Contents : %d %s socks",Dresser[i].NumberOfSocks,Dresser[i].SockColor);
		printf("\n     Capacity : %d socks",Dresser[i].MaxDrawerCapacity);

	}
}

