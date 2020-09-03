#include "poly.h"
#include<math.h>
void insert_at_end(List *list, int data) 
{
    Node *temp_node;
    temp_node=(Node*)malloc(sizeof(Node));
    temp_node->data=data;
    temp_node->link=NULL;
    if(list->head==NULL){
        list->head=temp_node;
    }
    else{
        Node *p;
        p=(Node*)malloc(sizeof(Node));
        p->link=list->head;
        while(p->link != NULL){
            p=p->link;
        }
        p->link=temp_node;
    }
    list->number_of_nodes++;
}

long long int evaluate(List *list, int x)
{
    if(list->head==NULL)
        return 0;
    else
	{
    long long int sum=0;
    Node *p=(Node*)malloc(sizeof(Node));
    p=list->head;
    int i=0;
    while (p != NULL)
	{
        sum=sum+p->data*pow(x,i);
        i++;
        p=p->link;
    }
    return sum;
    }
}	
