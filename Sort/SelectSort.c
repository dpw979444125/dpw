#include<stdio.h>
#include<assert.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void SelectSort2(int *arr, int n)
{
	assert(arr);
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int min = left;
		int max = right;
		for (int i = left; i <= right; i++)
		{
			if (arr[i] < arr[min])
				min = i;
			if (arr[i] > arr[max])
				max = i;
		}
		//考虑修正的情况，最大值在最小位置，最小值在最大位置。
		swap(&arr[max], &arr[right]);

		if (min == right)
		{
			min = max;
		}
		swap(&arr[min], &arr[left]);
		left++;
		right--;
	}
}

//void SelectSort(int *arr, int size)
//{
//	int i = 0;
//	int j = 0;
//	int max = 0;
//	for (i = 0; i < size - 1 ; i++)
//	{
//		max = i;
//		for (j = i; j < size ; j++)   //j从i的地方开始
//		{
//			if (arr[max] < arr[j])
//			{
//				max = j;
//			}
//		}
//		if (max != i)                          //
//			SSwap(&arr[i], &arr[max]);
//	}
//}

void SPrint(int *arr, int size)
{
	int i = 0;
	for (; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void SelectSortTest()
{
	int arr[] = { 5, 1, 2, 3, 6, 7, 8, 9, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	SPrint(arr, size);

	SelectSort2(arr, size);
	SPrint(arr, size);
}