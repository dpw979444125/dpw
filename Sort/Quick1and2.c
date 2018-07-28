#include<stdlib.h>
#include<stdio.h>

int  n;//定义全局变量，这两个变量需要在子函数中使用   
void quicksort(int *a,int left, int right)
{
	int i, j, t, temp;
	if (left>right)
		return;
	temp = a[left]; //temp中存的就是基准数   
	i = left;
	j = right;
	while (i != j)
	{
		//顺序很重要，要先从右边开始找   
		while (a[j] >= temp && i<j)
			j--;
		//再找右边的   
		while (a[i] <= temp && i<j)
			i++;
		//交换两个数在数组中的位置   
		if (i<j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//最终将基准数归位   
	a[left] = a[i];//i位置放temp，temp前数据就都比他小，i的数据给left（left原来数据就是temp）
	a[i] = temp;
	quicksort(a,left, i - 1);//继续处理左边的，这里是一个递归的过程   
	quicksort(a,i + 1, right);//继续处理右边的 ，这里是一个递归的过程   
}






//
//int partion2(int array[], int left, int right)	//挖坑法
//{
//	int key = array[right - 1];
//	int begin = left;
//	int end = right - 1;
//	while (begin < end)
//	{
//		while (begin < end && array[begin] <= key)//从左往右找最大的//begin<end防止在查找的时候begin越界
//			begin++;
//		if (begin < end)		//填坑
//			array[end] = array[begin];
//		while (begin < end && array[end] >= key)	//从右往左找最小的
//			end--;
//		if (begin < end)
//			array[begin] = array[end];
//	}
//	//begin, end到同一位置
//	array[end] = key;	//填最后一个坑
//	return begin;
//}
//




//void PQuickSort(int array[], int left, int right)
//{
//	int div = 0;
//	//if (right - right < 16)
//	//{
//	//	InsertionSort(array, right - left, Less);
//	//}
//	//else
//	if (left < right)
//	{
//		div = partion(array, left, right);
//		PQuickSort(array, left, div);
//		PQuickSort(array, div + 1, right);
//	}
//}

//void QickSortByLoop(int array[], int size)
//{
//	Stack s;
//	int left = 0;
//	int mid = 0;
//	int right = size;
//	assert(array);
//	if (size <= 1)
//	{
//		return;
//	}
//	//用栈保存每一个待排序子串的首尾元素下标，
//	//下一次while循环时取出这个范围，对这段子序列进行partition操作  
//	InitStack(&s);
//	PushStack(&s, left);		//左入栈
//	PushStack(&s, right);		//右入栈
//	while (!StackEmpty(&s))//栈不为空
//	{
//		right = TopStack(&s);	//右出栈
//		PopStack(&s);
//		left = TopStack(&s);	//左出栈
//		PopStack(&s);
//		if (left < right)
//		{
//			mid = partion3(array, left, right);
//			PushStack(&s, left);
//			PushStack(&s, mid);
//			PushStack(&s, mid + 1);
//			PushStack(&s, right);
//		}
//	}
//}

void pTestQuickSort()
{
	int arr[] = { 5, 0, 4, 6, 2, 3, 7, 8, 9, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int i;
	/*for (i = 0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");*/
	quicksort(arr, 0, n-1);
	for (i = 0; i<n; i++)
		printf("%d ", arr[i]);
}

//int partion3(int array[], int left, int right)//双支指针前移法
//{
//	int key = array[right - 1];
//	int begin = left - 1;//此处不会发生越界问题，并未访问数组-1处的元素
//	int end = left;
//
//	//定义两个指针一个begin和end，从左往右遍历，end的值小于基准值时让begin前进一个位置
//	//并检测是否与end为同一位置，若不是则交换位置上的值，end就是检测所有数据中比基准值小的值
//	//利用begin将其向前挪，循环结束时需交换begin位置的元素和基准值
//	while (end < right)//end指向当前元素，每次循环都要往前走，直到遍历完序列
//	{
//		if (array[end] < key)
//		{
//			//end处的元素小于key，begin前移，并判断
//			begin++;
//			if (begin != end)
//			{
//				QQSwap(&array[begin], &array[end]);
//			}
//		}
//		end++;
//	}
//	// if(++begin != right)    swap;
//
//	if (array[++begin] != key)			//此时begin的值一定小于key,begin的下一个元素大于等于key
//										//交换begin+1 和最后的元素
//		QQSwap(&array[begin], &array[right - 1]);
//	return begin;
//}
