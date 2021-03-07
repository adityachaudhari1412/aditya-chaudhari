//1001747134 Aditya Chaudhari
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void swap (int *SwapA, int *SwapB)
{
	int temp = *SwapA;
	*SwapA = *SwapB;
	*SwapB = temp;

}

int partition (int A[], int low, int high)
{
	int i, j = 0;
  
  	
	
	
 	#if QSM
	int middle = (high+low)/2;
	swap(&A[middle], &A[high]);
	#elif QSRND
	int random = (rand() % (high-low+1)) + low;
	swap(&A[random], &A[high]);
	#endif
	int pivot = A[high];
    i = (low - 1);
    for (j = low; j < high; j++)
    {
		if (A[j] < pivot)
	    {
			i++;
			swap (&A[i], &A[j]);
			//printArray (A,sizeof(*A)/sizeof(A[0]));
		}
    }
    swap (&A[i + 1], &A[high]);
	//printArray (A, sizeof(*A)/sizeof(A[0]));
    return (i + 1);
}

void QuickSort (int A[], int low, int high)
{
	if (low < high)
    {
		int ndx = partition (A, low, high);
        QuickSort (A, low, ndx - 1);
        QuickSort (A, ndx + 1, high);
    }
}
void printArray(int *arr,int arr_size)
{

	int i;
	for(i=0;i<arr_size;i++)
	{
		printf("%d\n",arr[i]);
	}
} 
int main(int argc, char *argv[]) 
{
	char buffer[20];
	int arr[] = {12, 11, 5, 13, 7, 6};
	int arr_size= sizeof(arr)/sizeof(arr[0]); 
	printf("Given array is \n"); 
	printArray(arr, arr_size); 
	QuickSort(arr, 0, arr_size-1); 
	printf("\nQuick Sortedarray is \n");
	printArray(arr, arr_size);
	 

	FILE *fp;
	char TestFile[40];
	if(argc==2)
	{
		strcpy(TestFile,argv[1]);
	}
	
	
	printf("%s",TestFile);
	fp = fopen(argv[1], "rw");
	
	int size = 0;
	fseek(fp, 0, 0);
	while(fgets(buffer, sizeof(buffer), fp))
	{
		size++;
	}
	
	fseek(fp, 0, 0);
	//printf("%d", size);
	int *array = (int*)malloc(sizeof(int)*size);
	int i = 0;
	
	while(fgets(buffer, sizeof(buffer), fp))
	{
		int temp = atoi(buffer);
		array[i] = temp;
		i++;
	}
	

	printf("\n");
	#ifdef PRINTARRAY
	printArray(array,size);
	#endif
	clock_t start, end;

	start = clock();
	QuickSort(array, 0, size-1);
	end = clock();
	printf("After Quicksort\n");
	#ifdef PRINTARRAY
	printArray(array,size);
	#endif
	printf("\nTotal tics %ld for Quick sort\n",end-start);

	
	free(array);
	fseek(fp, 0, 0);
	array = (int*)malloc(sizeof(int)*size);
	int j = 0;

	while(fgets(buffer, sizeof(buffer), fp))
	{
		int temp = atoi(buffer);
		array[j] = temp;
		j++;
	}
	int b;
	//int size2 = 0;
	for(i =0; i < atoi(argv[2]); i++)
	{
		clock_t start2, end2;

		start2 = clock();
		
		
		while(fgets(buffer, sizeof(buffer), fp))
		{
			size++;
		}
		int *a = (int*)malloc(sizeof(int)*size);
		fseek(fp, 0, 0);
		while(fgets(buffer, sizeof(buffer), fp))
		{
			int temp = atoi(buffer);
			a[i] = temp;
			i++;
		}

		QuickSort(a, 0, size-1);

		free(a);
		end2 = clock();
		b += end2 - start2;
	}
	b = b/atoi(argv[2]);
	//printf("%d", b);
	
	return 0;
}



