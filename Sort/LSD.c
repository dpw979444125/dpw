#include<stdlib.h>
#include<string.h>
#include<stdio.h>
//��������

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
		//����ÿ��Ͱ���ж��ٸ�Ԫ��
		for (i = 0; i < size; i++)
		{
			count[arr[i] / radix % 10]++;
		}
		//����ÿ��Ͱλ�ã�ֻ��ʮ��Ͱ�����ԣ�i = 10,�ӵ�һ����ʼ�㣩
		for (i = 1; i < 10; i++)
		{
			Addr[i] = Addr[i - 1] + count[i - 1];
		}
		//����Ͱ��
		for(i = 0; i < size; i++)
		{
			int bucketno = arr[i] / radix % 10;
			bucket[Addr[bucketno]] = arr[i];
			Addr[bucketno]++;//��ֵַ��1��������һ�������غ�
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
//		int count[10] = { 0 };//���뺯���ڣ�ÿ�γ�ʼ��Ϊ0
//		int Addr[10] = { 0 };
//		//ͳ��ÿ��Ͱ����ЧԪ�ظ���
//		for(i = 0;i < size;++i)
//		{
//			count[arr[i] / radix % 10]++; 
//		}
//		//����ÿ��Ͱ����ʼ��ַ
//		for(i = 1;i < 10;++i)
//		{
//			Addr[i] = Addr[i - 1] + count[i - 1];
//		}
//		//��Ԫ�ذ���ַ����Ͱ��
//		for(i = 0; i < size; ++i)
//		{
//			int bucketNo = arr[i] / radix % 10;
//			bucket[Addr[bucketNo]++] = arr[i];//��Ͱ�����һ��˳�������ַ���������
//		}
//		//����Ԫ����Ͱ
//		memcpy(arr, bucket, sizeof(arr[0])*size);
//		radix *= 10;
//	}
//	free(bucket);
//}


////��ȡԪ�����λ��
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
////�������򣬴ӵ�λ��ʼ
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
//		//ͳ��ÿ��Ͱ����ЧԪ�صĸ���
//		for (i = 0; i < size; ++i)
//		{
//			count[arr[i] / radix % 10]++;
//		}
//		//����ÿ��Ͱ����ʼ��ַ
//		for (i = 1; i < 10; ++i)
//		{
//			startAddr[i] = startAddr[i - 1] + count[i - 1];
//		}
//		//��Ԫ�ذ��յ�ǰλ�÷��õ���Ӧ��Ͱ��
//		for (i = 0; i < size; ++i)
//		{
//			int bucketNo = arr[i] / radix % 10;
//			bucket[startAddr[bucketNo]++] = arr[i];
//		}
//		//��Ԫ�ؽ��л���
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