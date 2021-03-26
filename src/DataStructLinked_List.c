/*
 ============================================================================
 Name        : DataStructLinked_List.c
 Author      : Itachi
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define LLSIZE      5
#define DEV_NEWHEAD 0
#define DEV_RMHEAD 1

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/
typedef struct Mylist
{
    uint8_t value;
    struct Mylist *next; //check me if need prefix
}myLL;

/******************************************************************************
* Variables
*******************************************************************************/
myLL LLinstace[LLSIZE]=
{
    {0, &LLinstace[1]},
    {1, &LLinstace[2]},
    {2, NULL}
};
myLL *p_head=NULL; 	/* <-- cur Head */
myLL *p_tail=NULL;	/* <-- cur Tail */

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void PrintList();
void Init(void);

void LLPushFront(myLL *newNode)
{
	printf("Push in %d \n", newNode->value);
	newNode->next = p_head;
    p_head = newNode;
    if(p_tail == NULL) p_tail = p_head;
}

void LLPopFront(void)
{
	printf(" ======== Remove head =========>\n");
	if(p_head == NULL)
	{
		printf("Error: HeadPt Null ???\n");
	}
	else
	{
		p_head = p_head->next;
		if(p_head == NULL) p_tail = NULL;
	}
}

uint8_t LLGetFront()
{
	return p_head->value;
}

void LLPopBack(void)
{

	printf("======== Remove tail =========>\n");
	if(p_head == NULL)
		printf("There is nothing to pop \n");
	else if (p_head == p_tail)
	{
		p_head = NULL;
		p_tail = NULL;
	}
	else
	{
		myLL* p_temp=p_head;
		while(p_temp->next != p_tail)
		{
			p_temp = p_temp->next;
		}
		p_temp->next = NULL;
		p_tail = p_temp;
	}
}
void LLPushBack(myLL *newNode)
{
	printf("Push back to tail %d \n", newNode->value);
	if(p_head == NULL)
	{
		p_head = newNode;
		p_tail = p_head;
	}
	else
	{
		p_tail->next = newNode;
		p_tail = newNode;
	}
}


myLL node1={1, NULL}; 	myLL node2={2, NULL}; 	myLL node3={3, NULL};
/******************************************************************************
* Function Definitions
*******************************************************************************/
int main()
{
	setbuf(stdout, NULL);
	LLPushFront(&node1);
	LLPushBack(&node2);
	LLPushFront(&node3);
	PrintList();
	LLPopFront();
	PrintList();
	LLPopBack();
	PrintList();
	printf("Head value: %d \n",LLGetFront());

	#if 0
	myLL *p_cur;
	printf("Adding a node before node 1\n");
	/* Input: node 1, new node to add */
	myLL insert_me={7, NULL};
	for(p_cur = p_head; p_cur->next != NULL ; p_cur = p_cur->next)
	{
		// Find node before node 1, update it next, update new node next
		if(p_cur ->next == &LLinstace[1]) /* Node before node 1 */
		{
			insert_me.next = p_cur->next;
			p_cur->next = &insert_me;
			break;
		}
	}
	#endif  /* End of 0 */

	return 0;
}

void Init(void)
{
	myLL *p_cur;
	printf("Original linked list \n");
	printf("-------------------------------------------------------\n");
	for(uint8_t idx=0; ; idx++)
	{
		p_cur = &LLinstace[idx];
		printf(" LL[%d] has address %p with value is: %d ---- address of next list is: %p \n",idx, (void*)&LLinstace[idx], LLinstace[idx].value, LLinstace[idx].next);
		if (p_cur == p_tail) break;
	}
	printf("-------------------------------------------------------\n");
}

void PrintList()
{
	printf("\n");
	printf("HeadPt: %p \n", p_head);
	myLL* p_cur = p_head;
	printf("------------------------------------------------------- \n");
	while(1)
	{
		if(p_cur != NULL)
		{
			printf("Address %p --- Value: %3d --- Next: %p \n", p_cur, p_cur->value, p_cur->next);
			p_cur = p_cur->next;
		}
		else
		{
			break;
		}
	}
	printf("------------------------------------------------------- \n");
	printf("TailPt: %p \n",p_tail);
	printf("\n");
}

