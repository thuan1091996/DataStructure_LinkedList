/*
 ============================================================================
 Name        : DataStructLinked_List.c
 Author      : Itachi
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define LLSIZE      5
#define DEV_NEWHEAD 0
#define DEV_RMHEAD 1

typedef struct Mylist
{
    uint8_t value;
    struct Mylist *p_next; //check me if need prefix
}myLL;


myLL LLinstace[LLSIZE]=
{
    {0, &LLinstace[1]},
    {1, &LLinstace[2]},
    {2, NULL}
};

myLL *p_head=&LLinstace[0], *p_tail=&LLinstace[2];


#if DEV_NEWHEAD
void my_sethead(myLL *p_newhead)
{
    if(p_head != NULL)
    {
        p_newhead->p_next = p_head;
    }
    p_head = p_newhead;
}
#endif // DEV_NEWHEAD

int main()
{
	setbuf(stdout, NULL);
	while(1)
	{
		myLL *p_cur;
		printf("Original linked list \n");
		printf("-------------------------------------------------------\n");

		for(uint8_t idx=0; ; idx++)
		{
			p_cur = &LLinstace[idx];
			printf(" LL[%d] has address %p with value is: %d ---- address of next list is: %p \n",idx, (void*)&LLinstace[idx], LLinstace[idx].value, LLinstace[idx].p_next);
			if (p_cur == p_tail) break;
		}
		printf("-------------------------------------------------------\n");

		#if DEV_NEWHEAD
		// Insert 26 to head of the list
		myLL list26={26, NULL};
		my_sethead(&list26);
		p_cur=p_head; //p_cur has new head
		printf("New linked list \n");
		printf("-------------------------------------------------------\n");
		do
		{
			printf("Address %p --- Value: %d --- Next: %p \n", p_cur, p_cur->value, p_cur->p_next);
			p_cur = p_cur->p_next;

		}
		while(p_cur != NULL) ;
		printf("-------------------------------------------------------\n");
		#endif

		// Remove head
		p_cur = p_head->p_next;
		p_head = p_cur;
		p_cur=p_head; //p_cur has new head
		printf("New linked list \n");
		printf("-------------------------------------------------------\n");
		do
		{
			printf("Address %p --- Value: %d --- Next: %p \n", p_cur, p_cur->value, p_cur->p_next);
			p_cur = p_cur->p_next;

		}
		while(p_cur != NULL) ;
		printf("-------------------------------------------------------\n");
	}
		return 0;
}

