/*
 * 此题比较简单，建立链表后，使用递归或栈来反向输出，栈的鲁棒性更好
 * 链表的创建、插入节点、删除节点等操作都只需要20行左右的代码能实现，其代码量比较适合面试，
 * 链表是一种动态的数据结构（无需知道链表的长度），其操作需要对指针进行操作，需要写出完整的操作链表的代码
 * 而像哈希表、有向图等复杂的数据结构，实现它们的一个操作需要的代码量都较大，很难再几十分钟的面试中完成
 */
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
struct Node
{
	int value;
	Node *next;
	Node (int _value) : value(_value), next(NULL){}
};
/*
//使用递归的方式
void displayNode(Node *head)
{
	if (head -> next != NULL)
		displayNode(head -> next);
	printf("%d\n", head -> value);
}
*/
//使用栈，鲁棒性会更好
void PrintListReversingly_Iteratively(Node *pHead)
{
	stack<Node *> st;
	while (pHead != NULL)
	{
		st.push(pHead);
		pHead = pHead -> next;
	}
	while (!st.empty())
	{
		printf("%d\n", st.top() -> value);
		st.pop();
	}
}
int main(void)
{
	int value;
	Node *head = new Node(-1);
	Node *father = head, *son;
	while (scanf("%d", &value) != EOF && value != -1)
	{
		son = new Node(value);
		father -> next = son;
		father = son;
	}
	//displayNode(head -> next);]
	PrintListReversingly_Iteratively(head -> next);
	return 0;
}

/* 剑指offer答案 
void AddToTail(Node **phead, int value)
{
	Node *pNew = new Node(value);
	if (*phead == NULL)
	{
		*phead = pNew;
	}
	else
	{
		Node *pNode = *phead;
		while (pNode -> next != NULL)
			pNode = pNode -> next;
		pNode -> next = pNew;
	}
}
void RemoveNode(Node **phead, int value)
{
	if (pHead == NULL || *pHead == NULL)
		return;
	Node *pToDeleted = NULL;
	if ((*pHead) -> value == value)
	{
		pToDeleted = *pHead;
		*pHead = (*pHead) -> next;
	}
	else
	{
		Node *pNode = *pHead;
		while (pNode -> next != NULL && pNode -> next -> value != value)
			pNode = pNode -> next;
		if (pNode -> next != NULL && pNode -> next -> value == value)
		{
			pToDeleted = pNode -> next;
			pNode -> next = pNode -> next -> next;
		}
		if (pToDeleted != NULL)
		{
			delete pToDeleted;
			pToDeleted = NULL;
		}

	}
}*/
