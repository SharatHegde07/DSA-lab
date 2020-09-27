#include "cll.h"
void position_insert(List* cll, int data, int pos)
{
//TODO
	struct Node *temp;
	temp=(struct Node *)(malloc(sizeof(struct Node)));
	temp=create_node(data);
	if(cll->head==NULL && pos==0)
	{
		temp->next=temp;
		cll->head=temp;
		cll->tail=temp;
		cll->length=1;
	}
	else
	{
		if(pos==0)
		{
			temp->next=cll->head;
			cll->head=temp;
			cll->tail->next=temp;
			(cll->length)++;
		}
		else if(pos==cll->length)
		{
			temp->next=cll->head;
			cll->tail->next=temp;
			cll->tail=temp;
			(cll->length)++;
		}
		else if(pos>0 && pos<(cll->length))
		{
			struct Node *temp= cll->head;
			int count=0;
			while(count!=pos)
			{
				temp=temp->next;
				count++;
			}
			temp->next=temp->next;
			temp->next=temp;
			(cll->length)++;
		}
	}
}

void position_delete(List* cll, int pos)
{
//TODO
	struct Node *del,*temp;
	int count=0;
	temp=cll->head;
	del=cll->head;
	if(cll->head==NULL);
	else
	{
		if(pos==0)
		{
			cll->head=del->next;
			cll->tail->next=cll->head;
			free(del);
			(cll->length)--;
		}
		else if(pos==(cll->length)-1)
		{
			while(del->next!=cll->head)
			{
				temp=del;
				del=del->next;
			}
			temp->next=cll->head;
			cll->tail=temp;
			free(del);
			(cll->length--);
		}
		else if(pos>0 && pos<(cll->length)-1)
		{
			while(count!=pos)
			{
				temp=del;
				del=del->next;
				count++;
			}
			temp->next=del->next;
			free(del);
			(cll->length--);
		}
	}
}

int josephus(List* cll, int k)
{
//TODO
	struct Node *prev,*temp,*del;
	prev=(struct Node *)(malloc(sizeof(struct Node)));
	temp=(struct Node *)(malloc(sizeof(struct Node)));
	del=(struct Node *)(malloc(sizeof(struct Node)));
	int i,count,find=0;
	count=cll->length;
	temp=cll->head;
	while(find!=k)
	{
		temp=temp->next;
		find++;
	}
	for(i=0;i<count-1;i++)
	{
		prev=temp;
		temp=temp->next;
		del=temp;
		temp=del->next;
		prev->next=temp;
		free(del);
		(cll->length--);
	}
	cll->head=temp;
	cll->tail=temp;
	return cll->head->data;
}


