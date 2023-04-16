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
	int32_t arr[10];
	printf("enter 10 elements");
	for(int i=0;i<10;i++)
	{
	scanf("%d",&arr[i]);		
	}
	insertionSort(arr,10)	;
	printArray(arr,10);
	
	lcsGetSize(arr, 10, &LCS);
	printf("size= %d",LCS);
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
		if(current+1>max)
		{
			max=current+1;
		}
		*sizeofLCS=max;
	}
}