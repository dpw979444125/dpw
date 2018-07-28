#include<stdlib.h>
#include<string.h>
#include<stdio.h>
//基数排序

//get max bit
int Getmaxbit(int *arr, int size)
{
	int count = 1;
	int radix = 10;
	int i = 0;
	for (; i < size; ++i)
	{
		while (arr[i] >= radix)
		{
			count++;
			radix *= 10;
		}
	}
	return count;
}

void RadixSortLsd(int *arr, int size)
{
	int i = 0;
	int radix = 1;
	int MaxBit = Getmaxbit(arr, size);
	int BitIndex = 0;
	int *bucket = (int*)malloc(sizeof(arr[0])*size);
	for (BitIndex = 0; BitIndex < MaxBit; BitIndex++)
	{
		int count[10] = { 0 };
		int Addr[10] = { 0 };
		//计算每个桶中有多少个元素
		for (i = 0; i < size; i++)
		{
			count[arr[i] / radix % 10]++;
		}
		//计算每个桶位置（只有十个桶，所以，i = 10,从第一个开始算）
		for (i = 1; i < 10; i++)
		{
			Addr[i] = Addr[i - 1] + count[i - 1];
		}
		//放入桶中
		for(i = 0; i < size; i++)
		{
			int bucketno = arr[i] / radix % 10;
			bucket[Addr[bucketno]] = arr[i];
			Addr[bucketno]++;//地址值加1，避免下一个与其重合
		}
		memcpy(arr, bucket, sizeof(arr[0])*size);
		radix *= 10;
	}
	free(bucket);
}



//void RadixSortLsd(int *arr, int size)
//{
//	int MaxBitcount;
//	int BitIndex = 0;
//	
//	int radix = 10;
//	int i = 0;
//	MaxBitcount = Getmaxbit(arr, size);
//	int *bucket = (int*)malloc(sizeof(arr[0])*size);
//	if (bucket == NULL)
//		return;
//	for (BitIndex = 0; BitIndex < MaxBitcount; BitIndex++)
//	{
//		int count[10] = { 0 };//放入函数内，每次初始化为0
//		int Addr[10] = { 0 };
//		//统计每个桶中有效元素个数
//		for(i = 0;i < size;++i)
//		{
//			count[arr[i] / radix % 10]++; 
//		}
//		//计算每个桶的起始地址
//		for(i = 1;i < 10;++i)
//		{
//			Addr[i] = Addr[i - 1] + count[i - 1];
//		}
//		//将元素按地址放入桶中
//		for(i = 0; i < size; ++i)
//		{
//			int bucketNo = arr[i] / radix % 10;
//			bucket[Addr[bucketNo]++] = arr[i];//将桶想象成一个顺序表，按地址依次往后放
//		}
//		//回收元素入桶
//		memcpy(arr, bucket, sizeof(arr[0])*size);
//		radix *= 10;
//	}
//	free(bucket);
//}


////获取元素最大位数
//int GetBitNum(int *arr, int size)
//{
//	int i = 0;
//	int radix = 10;
//	int count = 1;
//	for (; i < size; ++i)
//	{
//		while (arr[i] > radix)
//		{
//			count++;
//			radix *= 10;
//		}
//	}
//	return count;
//}
////进行排序，从低位开始
//void RadixSortLsd(int *arr, int size)
//{
//	int i;
//	int bitIdx, bitNum;
//	int radix = 1;
//	
//	int *bucket = (int*)malloc(sizeof(arr[0])*size);
//	if (NULL == bucket)
//		return;
//	bitNum = GetBitNum(arr, size);
//	for (bitIdx = 0; bitIdx < bitNum; ++bitIdx)
//	{
//		int count[10] = { 0 };
//		int startAddr[10] = { 0 };
//		//统计每个桶中有效元素的个数
//		for (i = 0; i < size; ++i)
//		{
//			count[arr[i] / radix % 10]++;
//		}
//		//计算每个桶的起始地址
//		for (i = 1; i < 10; ++i)
//		{
//			startAddr[i] = startAddr[i - 1] + count[i - 1];
//		}
//		//将元素按照当前位置放置到相应的桶中
//		for (i = 0; i < size; ++i)
//		{
//			int bucketNo = arr[i] / radix % 10;
//			bucket[startAddr[bucketNo]++] = arr[i];
//		}
//		//对元素进行回收
//		memcpy(arr, bucket, size * sizeof(arr[0]));
//		radix *= 10;
//	}
//	
//	free(bucket);
//}

void TestLSDSort()
{
	int arr[] = { 52, 333, 454, 688, 25, 12, 78, 899, 900, 120 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int i;
	int left = 0;
	int right = n;
	RadixSortLsd(arr, n);
	for (i = 0; i<n; i++)
		printf("%d ", arr[i]);
}