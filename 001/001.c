#include<stdio.h>
#include<stdlib.h>
#define LIST_INT_SIZE 100
#define MAXSIZE 128;
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


void un()

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

void sqlist_init(sqlist *L)
{
		(*L).data=(int*)malloc(LIST_INT_SIZE*sizeof(int));
		
}
int main(void)
{
		node La;
		int data;
Linkedlist_init(&La,10);

list_insert(La,5,13);
Getdata_linked(La,5,&data);

	printf("%d",data);
 list_del(La,5);




	

	return 0;



}
