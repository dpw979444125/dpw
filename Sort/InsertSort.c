#include<stdio.h>
#include<stdlib.h>
//������Ϊa[0��n - 1]��
//
//1.      ��ʼʱ��a[0]�Գ�1����������������Ϊa[1..n - 1]����i = 1
//
//2.      ��a[i]���뵱ǰ��������a[0��i - 1]���γ�a[0��i]���������䡣
//
//3.      i++���ظ��ڶ���ֱ��i == n - 1��������ɡ�

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
//	int i, j;                    //��С��������       
//	for (i = 1; i < n; i++)      //Ĭ��arr[0]��������i = 1
//	{
//		if (arr[i] < arr[i - 1]) //ÿ�����ȡһ�����������в��룬������������������һ��Ԫ��С������
//		{
//			int tmp = arr[i];  //����arr[i]
//			for (j = i - 1; j >= 0 && arr[j] > tmp; j--)  //��ǰѰ�ң�ֱ���ҵ�����λ�ã��ҵ���һ��������ģ�����ǰ�棩
//				arr[j + 1] = arr[j];            //����λ�ú��Ԫ��������
//			arr[j + 1] = tmp;                   //��tmp����ָ��λ��
//		}
//	}
//}
