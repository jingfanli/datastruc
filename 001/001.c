#include<stdio.h>
#include<stdlib.h>

#define LIST_INT_SIZE 100
#define MAXSIZE 128;

#define init_stack_size   100
#define incresement_size 10


#ifndef     SElemType
#define SElemType   unsigned int
#endif
int c=0;
typedef enum
{
	function_ok=0,
	function_fail
}progstatus;
typedef struct Linkedlist{
	int  data;
	struct Linkedlist *next;
}Linkedlist, *node;
typedef struct
{
	int data;
	int cur;
}component,SLinkList[128];
typedef struct 
{
	int data[10];
	int lenth;
	int listsize;
}sqlist;


typedef struct
{
	SElemType     *base;
	SElemType     *top;
	int stacksize;
}sqstack;

int statck_init(sqstack *S )
{
	S->base=(SElemType*)malloc(init_stack_size*sizeof(SElemType));
	S->top=S->base;
	S->stacksize=init_stack_size;
	return function_ok;
}

int get_top(sqstack S,SElemType *e)
{
	if(S.top==S.base)
		return function_fail;
	e=(S.top-1);
	return function_ok;
}

int Push(sqstack *s,SElemType e)
{
	if(s->top-s->base>init_stack_size)
		{
			s->base=(SElemType*)realloc(s->base,(init_stack_size+incresement_size)*sizeof(SElemType));
			if(!s->base)
				return function_fail;
			s->top=(s->base+init_stack_size);
			s->stacksize=init_stack_size+incresement_size;
		}
	*(s->top++)=e;
	
}
void move(char x,int n,char y)
{
	printf("%d.put %d dishes from %c to %c\n" ,++c,n,x,y);
}
void digui(int n,char x,char y, char z)
{
	int i=0;
	if(n==1)
		move(x,1,z);
	else
		{

			digui(n-1, x,z,y);
			move(x,n,z);

			digui(n-1,y, x,z);
		}
		
}
int Pop(sqstack *s,SElemType *e)
{
	if(s->top==s->base)
		return function_fail;
	*e=*(--s->top);
		return function_ok;
}



int locateEm_SL(SLinkList S,int e)
{
		int i;
		i=S[0].cur;
		while(i&&S[i].data!=e)
		{
			i=S[i].cur;
		}
		return i;
}


void inint_SL(SLinkList *S)
{
	int i;
	for(i=0;i<127;i++)
	{
		(*S[i]).cur=i+1;
	}
	(*S[127]).cur=0;
}

int list_insert(node L,int i,int dat)
{
		node q;

		node p;
		int j;
		j=0;
		q=L; 
		while(q&&j<i-1)
		{
			q=q->next;
			++j;
		}
		if(!q||j>i)
			return 0;
		p=(node)malloc(sizeof(Linkedlist));
		p->data=dat;
		p->next=q->next;
		q->next=p;
		return 1;
		
		 
} 
int list_del(node L,int n)
{
		node q;

		node p;
		int j;
		j=0;
		q=L; 
		while(q&&j<n-1)
		{
			q=q->next;
			++j;
		}
	if(!q||j>n)
	{
		return 0;
	}
	p=q->next;
	q->next=p->next;
	free(p);
	return 1;
}
void Linkedlist_init(node* L,int n)
{
	int i;

	node p;
	(*L)=(node)malloc(sizeof(node));
	(*L)->next=NULL;
	for(i=0;i<n;++i)
	{
		p=(node)malloc(sizeof(node));
		printf("please input the number:");
		scanf("%d",&p->data);
		
		p->next=(*L)->next;
		(*L)->next=p;
	}
	for(i=0;i<n;++i)
	{
		
		printf("%d",(p->data));
		printf("\n");
		 p=p->next;
	
	}

		
}
int Getdata_linked(node L,int n ,int *e)
{	
		int j;
		node q;
		q=(node)malloc(sizeof(node));
		q=L->next;
		
		j=1;
		while(j<n&&q)
		{
			q=q->next;
			j++;
		}
		if(!j||j>n)
			return 0;
		else
		*e=(q->data);
		return 1;
}

/*void sqlist_init(sqlist *L)
{
		L->data=(int*)malloc(LIST_INT_SIZE*sizeof(int));
		
}*/
int main(void)
{
		node La;
		int data;
		char a,b,c;
		a='a';
		b='b';
		c='c';
//Linkedlist_init(&La,10);

//list_insert(La,5,13);
//Getdata_linked(La,5,&data);

//	printf("%d",data);
// list_del(La,5);

digui(3,a,b,c);


	

	return 0;



}
