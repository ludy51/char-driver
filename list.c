#include "stdio.h"
#include "string.h"

//linklist note
//next is code section

#define length_default 100

typedef struct Node_S
{
	int data;
	Node *next;
	
}Node , *Linklist;

//Linklist 相当于Node *

//Node  *Pri_Linklist;
Linklist Pri_Linklist; //(Node *Pri_Linklist)定义一个链表对象（链表指针），Pri_Linklist->next
//定义链表对象（链表指针）方法二：
//Linklist *Pri_Linklist (Node **Pri_Linklist) //指针的指针，可以直接取出头结点地址的值：*Pri_Linklist为头结点的地址。


int pri_data[length_default] = {0};

void init_linklist_data()
{
	int i = 0;
	for(i=0; i<length_default; i++)
	{
		pri_data[i] = i;
	}
}

void create_linklist_init(Linklist L, int length)
//void create_linklist_init(Linklist L, int length)
{
	int i = 0;
	Node *p;
	p = L;
	
	for(i = 0; i < length; i++)
	{
		q = (Node*)malloc(sizeof(Node));  //申请一个节点内存
		q->data = pri_data[i];
		p->next = q;
		p=q;
	
	}
	
	p->next = NULL;

	
}
int Get_Node_Elem(Linklist L, int pos, Node *pos_node)
{
	int i = 0;
	Node *p;
	
	p = L->next; 
	while(p && pos--)
	{		
		p = p->next;
	}
	
	if((pos != 0) && !p)
	{
		return ERROR;
	}
	
	pos_node = p;
	return OK;
}

int Insert_Node_Elem(Linklist L, int pos, Node *pos_node)
{
	Node *p, *q;
	p = L->next;
	while(p && pos--)
	{		
		p = p->next;	
	}
	if((pos != 0) && !p)  //
	{
		return ERROR;
	}

	q = p->next;
	pos_node->next = q;
	p->next = pos_node;
	return OK;
	
}

int Delete_Node_Elem(Linklist L, int pos)
{
	Node *p, *q;
	p = L->next;
	while(p && pos--)
	{		
	 q = p;
		p = p->next;	
	}
	if((pos != 0) && !p)
	{
		return ERROR;
	}

	q->next = p->next;
	
	free(p);
	
	
	return OK;
	
}

int main()
{
	Node  *Pri_Node;
	Node  *New_Node;
	int i = 0;
	
	init_linklist_data();
	create_linklist(Pri_Linklist,length_default);
	
	for(i = 0; i<length_default; i++)
	{
		Get_Node_Elem(Pri_Linklist, i, Pri_Node);
		print("%d", Pri_Node->data)
	}
	
	
	New_Node = (Node*)malloc(sizeof(Node));
	New_Node->data = 101;
	Insert_Node_Elem(Pri_Linklist, 10, New_Node);
	
	Delete_Node_Elem(Pri_Linklist, 19)
	
	for(i = 0; i<length_default; i++)
	{
		Get_Node_Elem(Pri_Linklist, i, Pri_Node);
		print("%d", Pri_Node->data)
	}
	

}
