#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SockLib.h"
#include"SortLib.h"
#include"DrawerLib.h"
#include"DresserLib.h"
int main()
{
    int i=0, Choice;
    enum SockAction
    {
        RemoveSocks=1,AddSocks, DisplayDresser, SortSocks
    };
    Sockdrawer Dresser[MAX_DRAWERS];
    GetNumDrawers();
    for(i=1;i<=NumDrawers;i++)
    {
        //Dresserptr= &Dresser[i-1];
        CreateDrawer(&Dresser[i]);
    }
    do
    {
    	printf("What do you need to do?\n\n0. Don't have socks!!\n1. Take socks out of a drawer?\n2. Put more socks in a drawer?\n");
        printf("3. Display dresser\n4. Sort Socks\n\nChoice:  ");
        scanf("%d",&Choice);
    	switch (Choice)
		{
		    case 0:
		    	printf("\nDo Laundry then!!\n");
		        break;
		    case 1:
		    	PutOnMySocks(Dresser);
		    	DisplayMyDresser(Dresser);
		        break;
		    case 2:
		    	PutAwayMySocks(Dresser);
		    	DisplayMyDresser(Dresser);
		        break;
		    case 3:
		    	DisplayMyDresser(Dresser);
		        break;
		    case 4:
		    	SortMySocks(Dresser);
		    	DisplayMyDresser(Dresser);
		        break;
		    default: 
		    	printf("\nInvalid option please reenter\n");
		}
    }while(Choice !=0);
    return 0;
}


