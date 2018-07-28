#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//*
//数据比较集中
void CountSort(int *arr, int size)
{
	int maxValue = arr[0];
	int minValue = arr[0];
	int i = 0;
	int range;
	int *pCount;
	int index = 0;
	//确定数据范围
	for (; i < size; ++i)
	{
		if (arr[i] > maxValue)
		{
			maxValue = arr[i];
		}

		if (arr[i] < minValue)
		{
			minValue = arr[i];
		}
	}

	range = maxValue - minValue + 1;
	pCount = (int *)malloc(range * sizeof(int));
	if (NULL == pCount)
		return;
	//初始化memset
	memset(pCount, 0, sizeof(int) * range);
	//统计每个元素出现的次数
	for (i = 0; i < size; ++i)
	{
		pCount[arr[i] - minValue]++;
	}
	//回收数据
	i = 0;
	while (i < range)
	{
		while (pCount[i]--)
			arr[index++] = i + minValue;
		i++;
	}
	free(pCount);
}

void TestCountSort()
{
	int arr[] = { 5, 3, 4, 6, 2, 1, 7, 8, 9, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int i;
	CountSort(arr, n);
	for (i = 0; i<n; i++)
		printf("%d ", arr[i]);
}