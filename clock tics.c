#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int left, int middle, int right) 
{ 
	int i, j, k; 
	int n1 = middle -left + 1; 
	int n2 = right -middle; 
	int L[n1], R[n2]; 
	for (i= 0; i< n1; i++) 
	L[i] = arr[left + i]; 
	for (j = 0; j < n2; j++) 
	R[j] = arr[middle + 1 + j]; 
	i= 0;j = 0; k = left;
	while (i< n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{  
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j];
			j++;
		} 
		k++;
	}
	while (i< n1) 
	{ 
		arr[k] = L[i]; 
		i++;
		k++; 
	} 
	while (j < n2) 
	{ 
		arr[k] = R[j];
		j++;
		k++; 
	}
}
void mergeSort(int arr[], int L, int R)
{
	if (L < R) 
    { 
		int M = (L+R)/2;
		mergeSort(arr, L, M);
		mergeSort(arr, M+1, R);
		merge(arr, L, M, R);
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
void insertionSort(int arr[], int n) 
{ 
	int i, key, j; 
	for (i = 1; i < n; i++) 
	{ 
		key = arr[i]; 
		j = i - 1; 

		while (j >= 0 && arr[j] > key) 
		{ 
			arr[j + 1] = arr[j]; 
			j=j-1; 
		} 
		arr[j + 1] = key; 
    } 
} 
 
int main(int argc, char *argv[]) 
{
	char buffer[10000];
	int arr[] = {12, 11, 5, 13, 7, 6};
	int arr_size= sizeof(arr)/sizeof(arr[0]); 
	printf("Given array is \n"); 
	printArray(arr, arr_size); 
	mergeSort(arr, 0, arr_size-1); 
	printf("\nMerge Sortedarray is \n");
	printArray(arr, arr_size);
	printf("\nInsertion sorted array is \n");
	insertionSort(arr, arr_size); 
	printArray(arr, arr_size); 

	FILE *fp;
	char TestFile[]={};
	if(argc==2)
	{
		strcpy(TestFile,argv[1]);
	}
	fp = fopen(TestFile, "rw");
	int size = 0;
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
	/*for(i =0; i < size; i++)
	{
		printf("%d\n", array[i]);
	}
	*/

	printf("\n");
	clock_t start, end;

	start = clock();
	mergeSort(array, 0, size-1);
	end = clock();

	#ifdef PRINTARRAY
	printArray(array,size);
	#endif
	printf("\nTotal tics %ld for merge sort",end-start);

	/*for(i =0; i < size; i++)
	{
		printf("%d\n", array[i]);
	}*/
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
	/*for(j =0; j < size; j++)
	{
		printf("%d\n", array[j]);
	}*/

	/*for(j =0; j < size; j++)
	{
		printf("%d\n", array[j]);
	}*/
	free(fp);
	clock_t s, e;
	s = clock();
	insertionSort(array, size);
	e = clock();
	printf("\nTotal tics %ld for insertion sort",e-s);
	#ifdef PRINTARRAY
	printArray(array,size);
	#endif
	printf("\nTotal tics %ld for merge sort",end-start);
	printf("\nTotal tics %ld for insertion sort",e-s);
	return 0;
}




