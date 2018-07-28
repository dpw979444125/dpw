#include<stdio.h>
//*
void SWAP(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int Quick(int *arr, int left, int right)
{
	int cur = left;
	int prev = cur - 1;
	int key = arr[right - 1];

	while (cur < right)
	{
		if(arr[cur] < key)
		{
			prev++;
			if(cur != prev)
			{
				SWAP(&arr[cur], &arr[prev]);
			}
		}
		cur++;
		//if (arr[cur] < key && ++prev != cur)  //ֻ��pcur>keyʱ������pcur������
		//	SWAP(&arr[cur], &arr[prev]);   //pcur��ʼ��prevһ���ߣ�����pcur�߹��˱�key��ģ������˱�keyС�ģ���prev����
		//cur++;
	}
	if (++prev != right)
	{
		SWAP(&arr[prev], &arr[right - 1]);
	}
	return prev;
}

void QuickSort(int *arr, int left, int right)
{
	if (left < right)
	{
		int div = Quick(arr, left, right);
		QuickSort(arr, left, div);
		QuickSort(arr, div + 1, right);
	}
}

void TestQuickSort()
{
	int arr[] = { 5, 3, 4, 6, 2, 1, 7, 8, 9, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int i;
	int left = 0;
	int right = n ;
	QuickSort(arr, left, right);
	for (i = 0; i<n; i++)
		printf("%d ", arr[i]);
}