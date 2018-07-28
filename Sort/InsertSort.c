#include<stdio.h>
#include<stdlib.h>
//设数组为a[0…n - 1]。
//
//1.      初始时，a[0]自成1个有序区，无序区为a[1..n - 1]。令i = 1
//
//2.      将a[i]并入当前的有序区a[0…i - 1]中形成a[0…i]的有序区间。
//
//3.      i++并重复第二步直到i == n - 1。排序完成。

void Insertsort2(int arr[], int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		int tmp = arr[i];
		if (arr[i] < arr[i - 1]) {
			for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = tmp;
		}
	}
}
void TestInsertSort()
{
	int arr[] = { 5, 3, 4, 6, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	int i;
	Insertsort2(arr, n);
	for (i = 0; i<n; i++)
		printf("%d ", arr[i]);

}

//void Insertsort2(int arr[], int n)
//{
//	int i, j;                    //从小到大排列       
//	for (i = 1; i < n; i++)      //默认arr[0]有序，所以i = 1
//	{
//		if (arr[i] < arr[i - 1]) //每次向后取一个向有序列中插入，如果比有序序列中最后一个元素小，调整
//		{
//			int tmp = arr[i];  //保存arr[i]
//			for (j = i - 1; j >= 0 && arr[j] > tmp; j--)  //向前寻找，直到找到插入位置（找到第一个比他大的，放在前面）
//				arr[j + 1] = arr[j];            //插入位置后的元素向后搬移
//			arr[j + 1] = tmp;                   //将tmp插入指定位置
//		}
//	}
//}
