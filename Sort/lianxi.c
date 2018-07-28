#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//void QSwap(int *left, int *right)
//{
//	int tmp = *left;
//	*left = *right;
//	*right = *left;
//}
//
//void QQuick(int *arr, int left, int right)
//{
//	int pcur = left;
//	int prev = pcur - 1;
//	int key = arr[right - 1];
//
//	while (pcur < right)
//	{	
//		
//
//	}
//}

#if 0
void cCountSort(int *arr, int size)
{
	int range, i;
	int index = 0;
	int minValue = arr[0];
	int maxValue = arr[0];
	//计算数据范围
	for (i = 0; i < size; i++)
	{
		if (arr[i] > maxValue)
			maxValue = arr[i];
		if (arr[i] < minValue)
			minValue = arr[i];
	}
	range = maxValue - minValue + 1;
	//申请空间，初始化
	int *pCount = (int *)malloc(sizeof(arr[0])*size);
	if (NULL == pCount)
		return;
	memset(pCount, 0, sizeof(arr[0])*range);
	//计算每个元素出现次数
	for (i = 0; i < size; i++)
	{
		pCount[arr[i] - minValue]++;
	}
	//回收数据
	for (i = 0; i < range; i++)
	{
		while (pCount[i]--)
		{
			arr[index++] = i + minValue;
		}
	}
	free(pCount);
}

void TestLXSort()
{
	int arr[] = { 5, 3, 4, 6, 2, 1, 7, 8, 9, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int i;
	cCountSort(arr, n);
	for (i = 0; i<n; i++)
		printf("%d ", arr[i]);
}
#endif