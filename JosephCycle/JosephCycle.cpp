// JosephCycle.cpp : �������̨Ӧ�ó������ڵ㡣
#include"iostream"
#include"assert.h"
using namespace std;
typedef int DataType;
typedef struct LinkNode
{
	DataType data;
	struct LinkNode*next;
}LinkNode, *pLinkNode;
typedef struct LinkList
{
	LinkNode*phead;
}LinkList, *pLinkList;
pLinkNode JosephCycle(pLinkNode phead, int k)
{
	//Լɪ��
	pLinkNode cur = phead;
	pLinkNode del = NULL;
	int m = 0;
	while (1)
	{
		m = k;
		if (cur->next == cur)
			break;//��ֹ����
		while (--m)
		{
			cur = cur->next;
		}
		printf("del: %d\n", cur->data);
		cur->data = cur->next->data;//���ǵ�ǰλ��
		del = cur->next;
		cur->next = del->next;
		cur->next = del->next; 
		free(del);
		del = NULL;
	}
	return cur;
}
void Init_LinkList(pLinkList plist)       //��ʼ��  
{
	assert(plist);
	plist->phead = NULL;
}
pLinkNode Create_Node(DataType x)     //�����½��  
{
	pLinkNode newNode = (pLinkNode)malloc(sizeof(LinkNode));
	if (NULL == newNode)
	{
		printf("out of memory\n");
		exit(EXIT_FAILURE);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void Push_back(pLinkList plist, DataType x)    //β��  
{
	//1.�ǿ����� 2.�н��  
	pLinkNode cur = NULL;
	pLinkNode newNode = NULL;
	assert(plist);
	cur = plist->phead;
	newNode = Create_Node(x);
	if (NULL == cur)           //�ǿ�����  
	{
		plist->phead = newNode;
	}
	else                      //�н��  
	{
		while (cur->next != NULL)    //�ҵ����һ�����  
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}
pLinkNode Find_NUM(pLinkList plist, DataType x) //�ҽ��  
{
	pLinkNode cur = plist->phead;
	assert(plist);
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void test()
{
	int i = 0;
	LinkList plist;
	pLinkNode ret = NULL;
	Init_LinkList(&plist);  
	for (i = 0; i<41; i++)
	{
		Push_back(&plist, i + 1);
	}
	//���ɻ�  
	ret = Find_NUM(&plist, i);
	ret->next = plist.phead;

	ret = JosephCycle(plist.phead, 3);
	printf("last:%d\n", ret->data);
	free(ret);
}
int main()
{
	test();
	system("pause");
	return 0;
}