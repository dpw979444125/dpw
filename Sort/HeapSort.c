#include<stdio.h>

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void AdjustDown(int *arr, int size, int parent)//向下调整
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] < arr[child])  //！！！！！(child + 1) < size
		{
			child = child + 1;
		}
		if (arr[parent] > arr[child])  //双亲节点比最小的大，交换
		{
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else                                      //！！！！！
			return;
	}
}

void HeapSort(int *arr, int size)
{
	//创建堆
	int end = size - 1;
	int root = (end - 1) >> 1;
	while (root >= 0) //所有根都不满足条件，从最后一个根开始调整
	{
		AdjustDown(arr, size, root);
		root--;
	}
	//排序
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);     //只有根节点不满足，所以root 是 0。
		end--;
	}
}

void Print(int *arr, int size)
{
	int i = 0;
	for (; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void HeapSortTest()
{
	int arr[] = { 5,1,2,3,6,7,8,4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Print(arr, size);
	HeapSort(arr, size);
	Print(arr, size);
}
