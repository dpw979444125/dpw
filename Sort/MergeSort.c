#include<stdio.h>
#include<malloc.h>
#include<string.h>
//*
void MergeData(int *arr, int left, int right,int mid, int *temp)//合并有序数列
{
	//int mid = left + (right - left) >> 1;
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid ;
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
	while(begin2 < end2)
		temp[index++] = arr[begin2++];
}

void _MergeSort(int *arr, int left, int right, int *temp)
{
	if ((right - left) > 1)
	{
		int *temp = (int*)malloc(sizeof(arr[0])*(right - left));
		int mid = left + ((right - left) >> 1);
		_MergeSort(arr, left, mid, temp);//左边有序
		_MergeSort(arr, mid , right, temp);//右边有序
		MergeData(arr, left, right, mid, temp);//合并两个有序数列
		memcpy(arr + left, temp + left, sizeof(arr[0])*(right - left));
	}
}

void MergeSort(int *arr, int size)
{
	int *temp = (int *)malloc(sizeof(arr[0])*size);
	if (NULL == temp)
		return;
	_MergeSort(arr, 0, size, temp);
	free(temp);
}

void TestMergeSort()
{
	int arr[] = { 5, 3, 4, 6, 2, 1, 7, 8, 9, 0, 12, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int i;
	for (i = 0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	MergeSort(arr, n);
	for (i = 0; i<n; i++)
		printf("%d ", arr[i]);
}