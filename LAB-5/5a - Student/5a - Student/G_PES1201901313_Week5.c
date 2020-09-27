#include "5a.h"

void list_initialize(List* ptr_list) 
{
//TODO - initialize structure members to default values
    ptr_list->head=NULL;
    ptr_list->number_of_Nodes=0;
    return ;
}


void list_insert_front(List* ptr_list, int data) 
{
//TODO - perform linked list implementation of push operation.
     Node new_node=(Node)malloc(sizeof(Node));
     if(ptr_list->head==NULL)
     {
         ptr_list->head=new_node;
         ptr_list->number_of_Nodes++;
         return ;
     }
     new_node->link=ptr_list->head;
     ptr_list->head=new_node;
     ptr_list->number_of_Nodes++;
}


const int Node_get_data(Node *Node_ptr) 
{
//TODO - return the top most element
    return Node_ptr->data;
}
void list_delete_front(List* ptr_list) 
{
//TODO - perform linked list implementation of pop operation.
    if(ptr_list->head==NULL)
    {
        return ;
    }
    Node *temp=ptr_list->head;
    ptr_list->head=temp->link;
    free(temp);
    ptr_list->number_of_Nodes--;
}
void list_destroy(List* ptr_list) 
{
//TODO - free the allocated space
    Node *temp=ptr_list->head;
    Node *t1=NULL;
    while(temp!=NULL)
    {
        t1=temp;
        temp=temp->link;
        free(t1);
    }
    free(ptr_list);
}

void Stack_initialize(Stack *ptr_Stack) 
{
//TODO - get the memory allocation for stack, and intern call list initialize
    ptr_Stack->ptr_list = (List *)malloc(sizeof(List));    
	list_initialize(ptr_Stack->ptr_list);
}

void Stack_push(Stack *ptr_Stack, int key) 
{
//TODO	 - call the function list_insert_front
   list_insert_front(ptr_Stack->ptr_list,key);
   return ;
}

void Stack_pop(Stack *ptr_Stack) 
{
//TODO- call the function list_delete_front
   list_delete_front(ptr_Stack->ptr_list);
   return ;
}

int Stack_is_empty(Stack *ptr_Stack) 
{
//TODO	- return 0 if stack is not empty
    if(ptr_Stack->ptr_list->number_of_Nodes==0)
        return 1;
    return 0;
}

const int Stack_peek(Stack *ptr_Stack) 
{
//TODO	- return the top most element of the stack
    return Node_get_data(ptr_Stack->ptr_list->head);
}

void Stack_destroy(Stack *ptr_Stack)
 {
//TODO	- deallocate
   list_destroy(ptr_Stack->ptr_list);
}
int match_parenthesis(const char* string)
{
//TODO - implement the code to match paranthesis in a string which is passed as a parameter.
   Stack ptr_stack;
   List plist;
   (&ptr_stack)->ptr_list=(&plist);
   Stack_initialize(&ptr_stack);
   for(int i=0;string[i];i++)
   {
       if(string[i]=='('|| string[i]=='{' || string[i]=='[')
       {
           Stack_push(&ptr_stack,string[i]);
           continue;
       }
       else if(string[i]==')' || string[i]=='}' || string[i]==']')
       {
          if(Stack_is_empty(&ptr_stack))
             return 0;
          else if((Stack_peek(&ptr_stack)=='(' && string[i]==')') || (Stack_peek(&ptr_stack)=='{' && string[i]=='}') || (Stack_peek(&ptr_stack)=='[' && string[i]==']'))
             Stack_pop(&ptr_stack);        
          else 
            return 0;
         
       }
   }
   if(Stack_is_empty(&ptr_stack))
        return 1;
    else
      return 0;
    Stack_destroy(&ptr_stack);
}