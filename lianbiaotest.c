#include "lianbiao.h"

void test1()
{
	pNode ppHead;
	Init(&ppHead);

	PushFront(&ppHead, 1);
	PushBack(&ppHead, 2);
	PushFront(&ppHead, 1);
	PushBack(&ppHead, 2);
	PushFront(&ppHead, 1);
	PushBack(&ppHead, 2);
	PopBack(&ppHead);
	size_t x = Size(ppHead);
	Print(ppHead);
	printf("\n");
	printf("%d ", x);
	printf("\n");
	ReversePrint(ppHead);
}

void test2()
{
	pNode ppHead;
	Init(&ppHead);
	PushFront(&ppHead, 1);
	PushBack(&ppHead, 2);
	PushFront(&ppHead, 3);
	PushBack(&ppHead, 6);
	PushFront(&ppHead, 7);
	PushBack(&ppHead, 8);
	PushBack(&ppHead, 4);
	PushBack(&ppHead, 5);
	pNode pos = FindData(ppHead, 7);
	PopNoHead(pos);
	Print(ppHead);
}

void test3()
{
	pNode ppHead;
	Init(&ppHead);
	//PushFront(&ppHead, 1);
	PushBack(&ppHead, 2);
	PushBack(&ppHead, 6);
	PushBack(&ppHead, 8);
	PushBack(&ppHead, 4);
	PushBack(&ppHead, 5);
	pNode pos = FindData(ppHead, 4);
	PushNoHead(pos, 10);
	Print(ppHead);
}

void test4()          //Լɪ��
{
	pNode ppHead;
	Init(&ppHead);
	PushBack(&ppHead, 1);
	PushBack(&ppHead, 2);
	PushBack(&ppHead, 3);
	PushBack(&ppHead, 4);
	PushBack(&ppHead, 5);
	PushBack(&ppHead, 6);
	pNode pTail = FindData(ppHead, 6);
	pTail->next = ppHead;
	JosephCircle(&ppHead, 3);
}

void test5()   //���õ�����
{
	pNode ppHead;
	Init(&ppHead);

	PushBack(&ppHead, 2);
	PushBack(&ppHead, 6);
	PushBack(&ppHead, 8);
	PushBack(&ppHead, 4);
	PushBack(&ppHead, 5);
	Print(ppHead);
	printf("\n");
	ReverseList(&ppHead);
	Print(ppHead);
}

void test6() //ð������
{
	pNode ppHead;
	Init(&ppHead);

	PushBack(&ppHead, 2);
	PushBack(&ppHead, 6);
	PushBack(&ppHead, 8);
	PushBack(&ppHead, 4);
	PushBack(&ppHead, 5);
	Print(ppHead);
	printf("\n");
	BubbleSort(ppHead);
	Print(ppHead);
}

void test7()//�����м�ڵ�
{
	pNode ppHead;
	Init(&ppHead);
	PushBack(&ppHead, 2);
	PushBack(&ppHead, 6);
	PushBack(&ppHead, 8);
	PushBack(&ppHead, 4);
	PushBack(&ppHead, 5);
	pNode pin = FindMiddleNode(ppHead);
	printf("%d ", pin->_data);
}

void test8()//���ҵ�����K���ڵ�
{
	pNode ppHead;
	Init(&ppHead);
	PushBack(&ppHead, 2);
	PushBack(&ppHead, 6);
	PushBack(&ppHead, 8);
	PushBack(&ppHead, 4);
	PushBack(&ppHead, 5);
	pNode pin = FindLastKNode(ppHead, 2);
	printf("%d ", pin->_data);
}

void test9() //�ϲ�������������
{
	pNode ppHead1;
	pNode ppHead2;
	pNode ppHead3;
	Init(&ppHead1);
	Init(&ppHead2);
	Init(&ppHead3);
	PushBack(&ppHead1, 2);
	PushBack(&ppHead1, 4);
	PushBack(&ppHead2, 5);
	PushBack(&ppHead2, 6);
	PushBack(&ppHead2, 8);
	ppHead3 = MergeList(ppHead1, ppHead2);
	Print(ppHead3);
}

void test10()   //����������ĳ���
{
	pNode ppHead;
	Init(&ppHead);
	PushBack(&ppHead, 2);
	PushBack(&ppHead, 6);
	PushBack(&ppHead, 8);
	PushBack(&ppHead, 4);
	PushBack(&ppHead, 5);
	PushBack(&ppHead, 7);
	PushBack(&ppHead, 1);
	pNode pos = FindData(ppHead, 4);
	pNode pTail = FindData(ppHead, 1);
	pTail->next = pos;
	int x = GetCircleLen(ppHead);
	printf("%d", x);
}

//�󻷵���ڵ�
void test11()   //����������ĳ���
{
	pNode ppHead;
	Init(&ppHead);
	PushBack(&ppHead, 2);
	PushBack(&ppHead, 6);
	PushBack(&ppHead, 8);
	PushBack(&ppHead, 4);
	PushBack(&ppHead, 5);
	PushBack(&ppHead, 7);
	PushBack(&ppHead, 1);
	pNode pos = FindData(ppHead, 4);
	pNode pTail = FindData(ppHead, 1);
	pTail->next = pos;
	pNode pmeet = GetEnterNode(ppHead);
	printf("%d ", pmeet->_data);
}

void test22()
{
	pNode ppHead;
	Init(&ppHead);
	PushFront(&ppHead, 1);
	PushBack(&ppHead, 6);
	PushBack(&ppHead, 8);
	PushFront(&ppHead, 1);
	PushFront(&ppHead, 1);
	PushFront(&ppHead, 1);
	PushFront(&ppHead, 1);
	Print(ppHead);
}
void main()
{
	test22();
	system("pause");
}