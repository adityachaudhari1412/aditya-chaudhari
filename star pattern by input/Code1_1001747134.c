/*Aditya Ramdas Chaudhari  , 1001747134*/
#include<stdio.h>
int main(void)
{
	int a;
	printf("Enter i's starting value ");
	scanf("%d",&a);
	int a2;
	printf("Enter i's ending value ");
	scanf("%d",&a2);
	int b;
	printf("Enter j's starting value ");
	scanf("%d",&b);
	int b2;
	printf("Enter j's ending value ");
	scanf("%d",&b2);
	int c;
	printf("Enter k's starting value ");
	scanf("%d",&c);
	int c2;
	printf("Enter k's ending value ");
	scanf("%d",&c2);
	int i,j,k;
	for (i = a; i < a2; i++)
	{
		for (j = b; j < b2; j++)
		{
			for (k = c; k < c2; k++)
			{
				printf("*");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
