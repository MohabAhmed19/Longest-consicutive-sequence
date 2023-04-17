#include<stdio.h>
#include<stdint.h>
#include<process.h>

int8_t insertionSort(int32_t* array, uint8_t arraySize);
void printArray(int32_t *array, uint8_t arraySize);
int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS);

void main()
{
	char stop;
	uint8_t LCS=0;
	int error;
	int32_t arr[10],n;
	printf("enter number of elements elements\n");
	scanf("%d",&n);
	if(n>0&&n<=10)
	{
		printf("enter %d elements\n",n);
	for(int i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);		
	}
	insertionSort(arr,n);
	}
	
	//printArray(arr,n);
	
	error = lcsGetSize(arr, n, &LCS);
	if(error == -1)
	{
			printf("no array elements\n");
	}
	else if(error == -2)
		{
			printf("array size is more than 10 elements\n");
		}
	else if(error == -3)
		{
			printf("No consecutive sequence\n");
		}
	else if(error == 0)
		{
			printf("LCS size = %d",LCS);
		}
	system("pause");
}


int8_t insertionSort(int32_t* array, uint8_t arraySize)
{
	int32_t temp,temp2;
	for (int i = 1; i < arraySize; i++)
	{
		temp=array[i];
		for (int j = i; j > 0; j--)
		{
			if (temp < array[j-1])
			{
				array[j]=array[j-1];
				array[j-1]=temp;
			}
		}
	}
}

void printArray(int32_t *array, uint8_t arraySize)
{
	for(int i=0;i<arraySize;i++)
	{
		printf("%d, ",array[i]);
	}
}
int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS)
{
	int max=0,current=0;
	if(arraySize==0)
	{
		return -1;
	}
	else if(arraySize>10)
	{
		return -2;
	}
	for(int i=0;i<arraySize-1;i++)
	{
		if(array[i+1]==(array[i]+1))
		{		
			current++;
		}
		else
		{
			current=0;
		}
		if(current>0 && current+1>max)
		{
			max=current+1;
		}
		*sizeofLCS=max;
	}
	if(max==0)
	{
		return -3;
	}
	else
	{
		return 0;
	}
}