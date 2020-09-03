#include"dll.h"
int count_nodes(List* dl)
{
	int a;
	a=0;
	Node *temp;
	temp=dl->head;
	if(dl->head==NULL) 
		return 0;
	else
	{
		
		while(temp!=NULL)
		{
			a=a+1;
			temp=temp->next;
		}
	}
	return (a);
	
}

void insert_front(List* dl, int data)
{
    Node* node= create_node (data);
	if((dl->head) == NULL) dl->head=node;
	else
	{
	    node->next = dl->head;
		(dl->head)->prev = node;
		dl->head=node;
	}
	dl->number_of_nodes++;
}

void enddel(List *dl)
{   
	Node* new;
	Node* temp;
	if(dl==NULL)printf("EMPTY");
	else if((dl->head)->next==NULL)
	{
		temp=dl->head;
		dl->head=NULL;
		free(temp);
	}
	else
	{
		temp=dl->head;
		while(temp->next!=NULL)
			temp=temp->next;
		(temp->prev)->next=NULL;
		free(temp);
	}
	
  
}







void dllist_delete_beginning(List* list)
{
    Node *temp;
  	if(list->head == NULL) printf("EMPTY");
	else {
		   temp=list->head;
		   if((list->head)->next==NULL)
		   { list->head=NULL;
	         free(temp);
	       }
		   else {
			  list->head=(list->head)->next;
		      (list->head)->prev=NULL;
		      free(temp);
		   }
		   list->number_of_nodes--;
	     }
		
}


void position_delete(List* dl, int pos)
{
    Node *temp;
    int i,length;
	length=count_nodes(dl);
    if(pos == 0)
    {
        dllist_delete_beginning(dl);
    }
    else if(pos==length-1)
    {
        enddel(dl);
		dl->number_of_nodes--;
    }
    else if(pos>0 || pos<length-1)
    {
        temp=dl->head;
		int c1=0;
		while(temp!=NULL)
		{
			if(c1==pos)
			{
				(temp->prev)->next=temp->next;
				(temp->next)->prev=temp->prev;
				free(temp);
				break;
			}
			else
			{
				temp=temp->next;
				c1=c1+1;
			}
		}
		dl->number_of_nodes--;
	}
    
    else
    {
        
    }
	
}

int search_list(List* dl,int key)
{
     Node *temp;
	 temp=dl->head;
	 int c,i,flag;
	 c=0;
	 if(dl->head==NULL)
		 return -1;
	 else  
    {    
        while (temp!=NULL)  
        {  
            if(temp->data == key)  
            {  
                return i; 
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            temp = temp -> next;  
        }  
        if(flag==1)  
        {  
            return -1;  
        }  
    } 
}    
void reverse_list(List* dl)
{
      Node *temp = NULL;   
      Node *current = dl->head; 
       
     
       
     while (current !=  NULL) 
     { 
       temp = current->prev; 
       current->prev = current->next; 
       current->next = temp;               
       current = current->prev; 
     }       
       
     
        
     if(temp != NULL ) 
        dl->head = temp->prev; 
}


