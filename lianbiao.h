#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int Datatype;

typedef struct SListNode {
	Datatype _data;
	struct SListNode *next;
}Node, *pNode;

void  Init(pNode *ppHead); //初始化
pNode BuyNewNode(Datatype data);  //申请新节点
void  PushFront(pNode *ppHead, Datatype data); //头插
void  PushBack(pNode *ppHead, Datatype data); //尾插
void  PopFront(pNode *ppHead); //头删
void  PopBack(pNode *ppHead); //尾删 
void  Print(pNode ppHead); //打印
pNode FindData(pNode ppHead, Datatype data); //在链表中查找元素data，返回该结点在链表中的位置 
size_t Size(pNode ppHead);  //获取链表中节点个数
size_t Empty(pNode ppHead); //判断链表是否为空，若空，返回true
void Destroy(pNode *ppHead); //销毁单链表
void ReversePrint(pNode ppHead);//从尾到头打印单链表
void PopNoHead(pNode pos); //删除一个无头单链表的非尾结点
void PushNoHead(pNode pos, Datatype data); //在无头单链表的一个节点前插入一个节点
void JosephCircle(pNode *ppHead, Datatype k); //约瑟夫环										 
void ReverseList(pNode* pHead); // 单链表的逆置--三个指针 
void BubbleSort(pNode ppHead);  // 使用冒泡排序堆单链表进行排序 								
pNode FindMiddleNode(pNode ppHead);  // 查找单链表的中间结点，要求只能遍历一次链表 									
pNode FindLastKNode(pNode pHead, size_t K);   // 查找链表的倒数第K个结点 										  
pNode MergeList(pNode pHead1, pNode pHead2);  // 合并两个已序链表，合并之后依然有序 
int HasCircle(pNode pHead);						  // 判断单链表是否带环 
int GetCircleLen(pNode ppHead);				  // 求环的长度 
pNode GetEnterNode(pNode ppHead);		  // 求环的入口点 
int IsCrossWithoutCircle(pNode ppHead1, pNode ppHead2);			  // 判断两个不带环单链表是否相交？若干相交求交点 
pNode GetCorssNode(pNode ppHead1, pNode ppHead2);				  //若相交求交点

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////


