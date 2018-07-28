#include<stdlib.h>
#include<stdio.h>

int  n;//����ȫ�ֱ�����������������Ҫ���Ӻ�����ʹ��   
void quicksort(int *a,int left, int right)
{
	int i, j, t, temp;
	if (left>right)
		return;
	temp = a[left]; //temp�д�ľ��ǻ�׼��   
	i = left;
	j = right;
	while (i != j)
	{
		//˳�����Ҫ��Ҫ�ȴ��ұ߿�ʼ��   
		while (a[j] >= temp && i<j)
			j--;
		//�����ұߵ�   
		while (a[i] <= temp && i<j)
			i++;
		//�����������������е�λ��   
		if (i<j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//���ս���׼����λ   
	a[left] = a[i];//iλ�÷�temp��tempǰ���ݾͶ�����С��i�����ݸ�left��leftԭ�����ݾ���temp��
	a[i] = temp;
	quicksort(a,left, i - 1);//����������ߵģ�������һ���ݹ�Ĺ���   
	quicksort(a,i + 1, right);//���������ұߵ� ��������һ���ݹ�Ĺ���   
}






//
//int partion2(int array[], int left, int right)	//�ڿӷ�
//{
//	int key = array[right - 1];
//	int begin = left;
//	int end = right - 1;
//	while (begin < end)
//	{
//		while (begin < end && array[begin] <= key)//��������������//begin<end��ֹ�ڲ��ҵ�ʱ��beginԽ��
//			begin++;
//		if (begin < end)		//���
//			array[end] = array[begin];
//		while (begin < end && array[end] >= key)	//������������С��
//			end--;
//		if (begin < end)
//			array[begin] = array[end];
//	}
//	//begin, end��ͬһλ��
//	array[end] = key;	//�����һ����
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
//	//��ջ����ÿһ���������Ӵ�����βԪ���±꣬
//	//��һ��whileѭ��ʱȡ�������Χ������������н���partition����  
//	InitStack(&s);
//	PushStack(&s, left);		//����ջ
//	PushStack(&s, right);		//����ջ
//	while (!StackEmpty(&s))//ջ��Ϊ��
//	{
//		right = TopStack(&s);	//�ҳ�ջ
//		PopStack(&s);
//		left = TopStack(&s);	//���ջ
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

//int partion3(int array[], int left, int right)//˫ָ֧��ǰ�Ʒ�
//{
//	int key = array[right - 1];
//	int begin = left - 1;//�˴����ᷢ��Խ�����⣬��δ��������-1����Ԫ��
//	int end = left;
//
//	//��������ָ��һ��begin��end���������ұ�����end��ֵС�ڻ�׼ֵʱ��beginǰ��һ��λ��
//	//������Ƿ���endΪͬһλ�ã��������򽻻�λ���ϵ�ֵ��end���Ǽ�����������бȻ�׼ֵС��ֵ
//	//����begin������ǰŲ��ѭ������ʱ�轻��beginλ�õ�Ԫ�غͻ�׼ֵ
//	while (end < right)//endָ��ǰԪ�أ�ÿ��ѭ����Ҫ��ǰ�ߣ�ֱ������������
//	{
//		if (array[end] < key)
//		{
//			//end����Ԫ��С��key��beginǰ�ƣ����ж�
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
//	if (array[++begin] != key)			//��ʱbegin��ֵһ��С��key,begin����һ��Ԫ�ش��ڵ���key
//										//����begin+1 ������Ԫ��
//		QQSwap(&array[begin], &array[right - 1]);
//	return begin;
//}
