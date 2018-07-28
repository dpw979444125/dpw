#include<stdio.h>

void BSwap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(int *arr, int size)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < size ; i++)
	{
		flag = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				BSwap(&arr[j], &arr[j + 1]);      //×¢Òâj+1Ô½½ç
				flag = 1;
			}
		}
		/*if (flag == 0)
			return;*/
	}
}

void BPrint(int *arr, int size)
{
	int i = 0;
	for (; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void TestBubbleSort()
{
	int arr[] = { 5, 1, 2, 3, 9, 6, 7, 8, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	BPrint(arr, size);
	BubbleSort(arr, size);
	BPrint(arr, size);
}