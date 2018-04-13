#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int Datatype;

typedef struct SListNode {
	Datatype _data;
	struct SListNode *next;
}Node, *pNode;

void  Init(pNode *ppHead); //��ʼ��
pNode BuyNewNode(Datatype data);  //�����½ڵ�
void  PushFront(pNode *ppHead, Datatype data); //ͷ��
void  PushBack(pNode *ppHead, Datatype data); //β��
void  PopFront(pNode *ppHead); //ͷɾ
void  PopBack(pNode *ppHead); //βɾ 
void  Print(pNode ppHead); //��ӡ
pNode FindData(pNode ppHead, Datatype data); //�������в���Ԫ��data�����ظý���������е�λ�� 
size_t Size(pNode ppHead);  //��ȡ�����нڵ����
size_t Empty(pNode ppHead); //�ж������Ƿ�Ϊ�գ����գ�����true
void Destroy(pNode *ppHead); //���ٵ�����
void ReversePrint(pNode ppHead);//��β��ͷ��ӡ������
void PopNoHead(pNode pos); //ɾ��һ����ͷ������ķ�β���
void PushNoHead(pNode pos, Datatype data); //����ͷ�������һ���ڵ�ǰ����һ���ڵ�
void JosephCircle(pNode *ppHead, Datatype k); //Լɪ��										 
void ReverseList(pNode* pHead); // �����������--����ָ�� 
void BubbleSort(pNode ppHead);  // ʹ��ð������ѵ������������ 								
pNode FindMiddleNode(pNode ppHead);  // ���ҵ�������м��㣬Ҫ��ֻ�ܱ���һ������ 									
pNode FindLastKNode(pNode pHead, size_t K);   // ��������ĵ�����K����� 										  
pNode MergeList(pNode pHead1, pNode pHead2);  // �ϲ��������������ϲ�֮����Ȼ���� 
int HasCircle(pNode pHead);						  // �жϵ������Ƿ���� 
int GetCircleLen(pNode ppHead);				  // �󻷵ĳ��� 
pNode GetEnterNode(pNode ppHead);		  // �󻷵���ڵ� 
int IsCrossWithoutCircle(pNode ppHead1, pNode ppHead2);			  // �ж������������������Ƿ��ཻ�������ཻ�󽻵� 
pNode GetCorssNode(pNode ppHead1, pNode ppHead2);				  //���ཻ�󽻵�

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////


