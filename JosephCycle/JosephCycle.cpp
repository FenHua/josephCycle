// JosephCycle.cpp : 定义控制台应用程序的入口点。
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
	//约瑟夫环
	pLinkNode cur = phead;
	pLinkNode del = NULL;
	int m = 0;
	while (1)
	{
		m = k;
		if (cur->next == cur)
			break;//终止条件
		while (--m)
		{
			cur = cur->next;
		}
		printf("del: %d\n", cur->data);
		cur->data = cur->next->data;//覆盖当前位置
		del = cur->next;
		cur->next = del->next;
		cur->next = del->next; 
		free(del);
		del = NULL;
	}
	return cur;
}
void Init_LinkList(pLinkList plist)       //初始化  
{
	assert(plist);
	plist->phead = NULL;
}
pLinkNode Create_Node(DataType x)     //创建新结点  
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
void Push_back(pLinkList plist, DataType x)    //尾插  
{
	//1.是空链表 2.有结点  
	pLinkNode cur = NULL;
	pLinkNode newNode = NULL;
	assert(plist);
	cur = plist->phead;
	newNode = Create_Node(x);
	if (NULL == cur)           //是空链表  
	{
		plist->phead = newNode;
	}
	else                      //有结点  
	{
		while (cur->next != NULL)    //找到最后一个结点  
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}
pLinkNode Find_NUM(pLinkList plist, DataType x) //找结点  
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
	//构成环  
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