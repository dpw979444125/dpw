#include "lianbiao.h"

void Init(pNode *ppHead)
{
	assert(ppHead);
	*ppHead = NULL;
}

pNode BuyNewNode(Datatype data)
{
	pNode pNewNode = (pNode)malloc(sizeof(Node));
	assert(pNewNode);
	pNewNode->next = NULL;
	pNewNode->_data = data;
	return pNewNode;
}

void PushFront(pNode *ppHead, Datatype data)
{
	assert(ppHead);
	pNode pNewNode = BuyNewNode(data);
	if (NULL == *ppHead) {
		*ppHead = pNewNode;
		return;
	}
	pNewNode->next = *ppHead;
	*ppHead = pNewNode;
}

void  PushBack(pNode *ppHead, Datatype data)
{
	assert(ppHead);
	pNode pNewNode = BuyNewNode(data);
	if (NULL == *ppHead) {
		*ppHead = pNewNode;
		return;
	}
	pNode pTail = *ppHead;
	while (pTail->next)
	{
		pTail = pTail->next;
	}
	pTail->next = pNewNode;
}

void  PopFront(pNode *ppHead)
{
	assert(ppHead);
	if (NULL == ppHead)
		return;
	pNode pcur = *ppHead;
	pNode pSecond = *ppHead;
	pSecond = pSecond->next;
	free(pcur);
	pSecond = *ppHead;
	pcur = NULL;
}

void  PopBack(pNode *ppHead)
{
	assert(ppHead);
	if (NULL == ppHead)
		return;
	pNode pTail = *ppHead;
	pNode ppreTail = *ppHead;
	while (pTail->next)
	{
		ppreTail = pTail;
		pTail = pTail->next;
	}
	free(pTail);
	ppreTail->next = NULL;
	pTail = NULL;
}

void  Print(pNode ppHead)
{
	assert(ppHead);
	if (NULL == ppHead)
		return;
	pNode pcur = ppHead;
	while (pcur)
	{
		printf("%d-> ", pcur->_data);
		pcur = pcur->next;
	}
}

pNode FindData(pNode ppHead, Datatype data)
{
	assert(ppHead);
	if (NULL == ppHead)
		return NULL;
	pNode pcur = ppHead;
	while (pcur)
	{
		if (data == pcur->_data)
			return pcur;
		pcur = pcur->next;
	}
	return NULL;
}

size_t Size(pNode ppHead)
{
	assert(ppHead);
	size_t count = 0;
	if (NULL == ppHead)
		return 0;
	pNode pcur = ppHead;
	while (pcur)
	{
		count++;
		pcur = pcur->next;
	}
	return count;
}

size_t Empty(pNode ppHead)
{
	assert(ppHead);
	if (NULL == ppHead)
		return 1;
	else
		return 0;
}

void Destroy(pNode *ppHead)
{
	assert(ppHead);
	pNode pcur = *ppHead;
	pNode ppre = NULL;
	while (pcur)
	{
		ppre = pcur;
		pcur = pcur->next;
		free(ppre);
		ppre = NULL;
	}
}

void ReversePrint(pNode ppHead)
{
	if (NULL == ppHead)
	{
		return;
	}
	ReversePrint(ppHead->next);
	printf("%d-> ", ppHead->_data);
}

void PopNoHead(pNode pos)
{
	assert(pos);
	pNode posnext = pos->next;
	pNode posnnext = posnext->next;
	pos->_data = posnext->_data;
	pos->next = posnnext;
	free(posnext);
}

void PushNoHead(pNode pos, Datatype data)
{
	pNode pnew = BuyNewNode(data);
	pNode posnext = pos->next;
	pos->next = pnew;
	pnew->next = posnext;
	pnew->_data ^= pos->_data;
	pos->_data ^= pnew->_data;
	pnew->_data ^= pos->_data;
}

void JosephCircle(pNode *ppHead, Datatype k)
{
	assert(ppHead);
	int count = k;
	pNode pcur = *ppHead;
	pNode pnext = NULL;
	pNode pnnext = NULL;
	while (pcur->next != pcur)
	{
		while (--count)
		{
			pcur = pcur->next;
		}
		count = k;

		pnext = pcur->next;
		pnnext = pnext->next;
		pcur->_data = pnext->_data;
		pcur->next = pnnext;
		free(pnext);
		*ppHead = pcur;
	}
}

void ReverseList(pNode *ppHead) // 单链表的逆置--三个指针 
{
	assert(ppHead);
	pNode ppre = *ppHead;
	pNode pcur = ppre->next;
	pNode pnext = NULL;
	while (pcur)
	{
		pnext = pcur->next;
		pcur->next = ppre;
		ppre = pcur;
		pcur = pnext;
	}
	(*ppHead)->next = NULL;
	*ppHead = ppre;
}
void BubbleSort(pNode ppHead)  // 使用冒泡排序堆单链表进行排序 
{
	assert(ppHead);
	pNode pcur = ppHead;
	int size = Size(ppHead);
	int tmp = 0;
	int i = 0, j = 0;
	while (i < size) 
	{
		j = 0;
		pcur = ppHead;
		while (j < size-i-1)
		{
			if (pcur->_data < pcur->next->_data)
			{
				tmp = pcur->_data;
				pcur->_data = pcur->next->_data;
				pcur->next->_data = tmp;
			}
			pcur = pcur->next;
			j++;
		}
		i++;
	}
}

pNode FindMiddleNode(pNode ppHead)  // 查找单链表的中间结点，要求只能遍历一次链表
{
	assert(ppHead);
	pNode pfast = ppHead;
	pNode pslow = ppHead;
	while (NULL != pfast->next)
	{
		pslow = pslow->next;
		pfast = pfast->next->next;
	}
	return pslow;
}

pNode FindLastKNode(pNode ppHead, size_t K)   // 查找链表的倒数第K个结点
{
	//快指针先走k-1
	assert(ppHead);
	pNode pfast = ppHead;
	pNode pslow = ppHead;
	int q = K - 1;
	//快指针先走k-1
	while (q--)
	{
		pfast = pfast->next;
	}
	while (pfast->next)
	{
		pfast = pfast->next;
		pslow = pslow->next;
	}
	return pslow;
}

pNode MergeList(pNode ppHead1, pNode ppHead2)  // 合并两个已序链表，合并之后依然有序 
{
	if (ppHead1 == NULL || ppHead2 == NULL)
	{
		return ppHead1 ? ppHead1 : ppHead2;
	}
	pNode pcur1 = ppHead1;
	pNode pcur2 = ppHead2;
	pNode head = NULL;
	if (pcur1->_data < pcur2->_data)
	{
		head = pcur1;
		pcur1 = pcur1->next;
	}
	else if (pcur1->_data > pcur2->_data)
	{
		head = pcur2;
		pcur2 = pcur2->next;
	}
	else
	{
		head = pcur1;
		pcur1 = pcur1->next;
		pcur2 = pcur2->next;
	}
	pNode pcur = head;
	while (pcur1 != NULL && pcur2 != NULL)
	{
		if (pcur1->_data < pcur2->_data)
		{
			pcur->next = pcur1;
			pcur1 = pcur1->next;
		}
		else if (pcur1->_data > pcur2->_data)
		{
			pcur->next = pcur2;
			pcur2 = pcur2->next;
		}
		else
		{
			pcur->next = pcur1;
			pcur1 = pcur1->next;
			pcur2 = pcur2->next;
		}
		pcur = pcur->next;           //**
	}
	if (pcur1 == NULL)
	{
		pcur->next = pcur2;
	}
	if (pcur2 == NULL)
	{
		pcur->next = pcur1;
	}
	return head;
}

int HasCircle(pNode ppHead)	 // 判断单链表是否带环 
{
	if (ppHead == NULL)
		return 0;
	pNode pslow = ppHead;
	pNode pfast = ppHead;
	while (NULL != pfast->next)
	{
		pslow = pslow->next;
		pfast = pfast->next->next;
		if (pslow == pfast)
			return 1;
	}
	return 0;
}

// 求环的长度 
int GetCircleLen(pNode ppHead)
{
	int l = HasCircle(ppHead);
	if (l == 0)
		return 0;
	int count = 0;
	pNode pslow = ppHead;
	pNode pfast = ppHead;
	pslow = pslow->next;
	pfast = pfast->next->next;
	while (pfast != pslow)
	{
		pslow = pslow->next;
		pfast = pfast->next->next;
	}
	pslow = pslow->next;
	while (pslow != pfast)
	{
		pslow = pslow->next;
		count++;
	}
	return count + 1;
}

// 求环的入口点 
pNode GetEnterNode(pNode ppHead)
{
	/*相遇时，快指针走了慢指针的两倍
	l为起点到入口点,x为入口点到相遇点,r为环的长度
	2(l + x) = l + r + x
	l + x = r
	l = r - x
	一个从起点走，一个从相遇点走，再次相遇就是入口点
	*/
	//找到相遇点
	pNode pfast = ppHead;
	pNode pslow = ppHead;
	pslow = pslow->next;
	pfast = pfast->next->next;
	while (pslow != pfast)
	{
		pslow = pslow->next;
		pfast = pfast->next->next;
	}
	pNode pcur = ppHead;
	while (pcur != pslow)
	{
		pslow = pslow->next;
		pcur  = pcur->next;
	}
	return pcur;
}

// 判断两个不带环单链表是否相交
int IsCrossWithoutCircle(pNode ppHead1, pNode ppHead2)
{
	int count1 = 0;
	int count2 = 0;
	pNode pcur1 = ppHead1;
	pNode pcur2 = ppHead2;
	while (pcur1->next != NULL)
	{
		pcur1 = pcur1->next;
		count1++;
	}
	while (pcur2->next != NULL)
	{
		pcur2 = pcur2->next;
		count2++;
	}
	pNode cur1 = ppHead1;
	pNode cur2 = ppHead2;
	int x = count1 - count2;
	int y = count2 - count1;
	if (count1 > count2)
	{
		while (x--)
		{
			cur1 = cur1->next;
		}
	}
	if (count2 > count1)
	{
		while (y--)
		{
			cur2 = cur2->next;
		}
	}
	while (cur1->next != NULL)
	{
		if (cur1 == cur2)
			return 1;
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return 0;
}

//若相交求交点
pNode GetCorssNode(pNode ppHead1, pNode ppHead2)
{
	int count1 = 0;
	int count2 = 0;
	pNode pcur1 = ppHead1;
	pNode pcur2 = ppHead2;
	while (pcur1->next != NULL)
	{
		pcur1 = pcur1->next;
		count1++;
	}
	while (pcur2->next != NULL)
	{
		pcur2 = pcur2->next;
		count2++;
	}
	pNode cur1 = ppHead1;
	pNode cur2 = ppHead2;
	int x = count1 - count2;
	int y = count2 - count1;
	if (count1 > count2)
	{
		while (x--)
		{
			cur1 = cur1->next;
		}
	}
	if (count2 > count1)
	{
		while (y--)
		{
			cur2 = cur2->next;
		}
	}
	while (cur1->next != NULL)
	{
		if (cur1 == cur2)
			return cur1;
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return NULL;
}
