#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30

int main(void)
{
	char  StartVertex=0;
	int AdjMatrix=-1;
	int VertexCount=0;
	printf("what is the Starting vertex  ");
	scanf("%s",& StartVertex);
	int CurrentVertex= StartVertex;
	VertexArray[StartVertex].distance = 0;
	VertexArray[StartVertex].previous = -1;
	VertexArray[StartVertex].visited = 1;
	for(i= 0; i< VertexCount; i++)
	{
		if (AdjMatrix[CurrentVertex][i] != -1 && !VertexArray[i].visited)  
		{
			dofu= VertexArray[CurrentVertex].distance;
			cofuv= AdjMatrix[CurrentVertex][i];
			dofv= VertexArray[i].distance;
			if (dofu+ cofuv< dofv)
			{
				dofv= dofu+ cofuv;
				VertexArray[i].distance = dofv;
				VertexArray[i].previous = CurrentVertex;
			}
		}
	}
	for(i= 0; i< VertexCount; i++)
	{
		// Check all vertices for distance from CurrentVertexand update
		int SmallestVertexIndex= -1;
		int SmallestVertex= INT_MAX;
		for(i= 0; i< VertexCount; i++)
		{
			if (!VertexArray[i].visited)
			{
				if (VertexArray[i].distance < SmallestVertex)
				{
					SmallestVertex= VertexArray[i].distance;
					SmallestVertexIndex= i;
				}
			}
		}
		CurrentVertex= SmallestVertexIndex;
		VertexArray[CurrentVertex].visited = 1;
	}