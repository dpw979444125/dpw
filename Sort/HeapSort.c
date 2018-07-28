#include<stdio.h>

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void AdjustDown(int *arr, int size, int parent)//���µ���
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] < arr[child])  //����������(child + 1) < size
		{
			child = child + 1;
		}
		if (arr[parent] > arr[child])  //˫�׽ڵ����С�Ĵ󣬽���
		{
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else                                      //����������
			return;
	}
}

void HeapSort(int *arr, int size)
{
	//������
	int end = size - 1;
	int root = (end - 1) >> 1;
	while (root >= 0) //���и��������������������һ������ʼ����
	{
		AdjustDown(arr, size, root);
		root--;
	}
	//����
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);     //ֻ�и��ڵ㲻���㣬����root �� 0��
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
