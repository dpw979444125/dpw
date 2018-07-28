#include<stdio.h>
#include<malloc.h>
#include<string.h>
//*
void MMergeData(int *arr, int left, int mid, int right, int *temp)
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid;
	int end2 = right;
	int index = left;
	while (begin1 < end1 && begin2 < end2)
	{
		if (arr[begin1] <= arr[begin2])
			temp[index++] = arr[begin1++];
		else
			temp[index++] = arr[begin2++];
	}
	while (begin1 < end1)
		temp[index++] = arr[begin1++];
	while (begin2 < end2)
		temp[index++] = arr[begin2++];
}

void MergeNorSort(int *arr, int size)
{
	int *temp = (int *)malloc(sizeof(arr[0])*size);
	if (NULL == temp)
		return;
	int gap = 1;
	while (gap < size)
	{
		int left, right, mid;
		for (int i = 0; i < size; i += 2 * gap)
		{
			left = i;
			mid = left + gap;
			if (mid > size)
			{
				mid = size;
			}
			right = mid + gap;
			if (right > size)
			{
				right = size;
			}
			MMergeData(arr, left, mid, right, temp);
		}
		memcpy(arr, temp, size * sizeof(arr[0]));
		gap *= 2;
	}
}

void TestMergeNorSort()
{
	int arr[] = { 5, 3, 4, 6, 2, 1, 7, 8, 9, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int i;
	for (i = 0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	MergeNorSort(arr, n);
	for (i = 0; i<n; i++)
		printf("%d ", arr[i]);
}
