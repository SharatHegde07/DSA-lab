#include "6a.h"

static Node* create_Node(int data, Node* link) {
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data; 
	temp -> link = link;
	return temp;
}

void List_initialize(List* ptr_List) 
{
	ptr_List->head=NULL;
    ptr_List->number_of_Nodes=0;
    return ;	
}

void List_insert_front(List* ptr_List, int data) 
{
	Node new_node=(Node*)malloc(sizeof(Node));
     if(ptr_list->head==NULL)
     {
         ptr_List->head=new_node;
         ptr_List->number_of_Nodes++;
         return ;
     }
     new_node->link=ptr_List->head;
     ptr_List->head=new_node;
     ptr_List->number_of_Nodes++;	
}

const int Node_get_data(Node *Node_ptr) 
{
	return Node_ptr->data;
}

void List_delete_front(List* ptr_List)
{
	if(ptr_list->head==NULL)
    {
        return ;
    }
    Node *temp=ptr_list->head;
    ptr_list->head=temp->link;
    free(temp);
    ptr_list->number_of_Nodes--;
}

void List_destroy(List* ptr_List) 
{
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


void stack_initialize(Stack *ptr_stack) 
{
	 ptr_stack->ptr_list = (List *)malloc(sizeof(List));    
	list_initialize(ptr_stack->ptr_list);
}

void stack_push(Stack *ptr_stack, int key)
{
	list_insert_front(ptr_stack->ptr_list,key);
    return ;
}

void stack_pop(Stack *ptr_stack) 
{
	list_delete_front(ptr_stack->ptr_list);
    return ;
}

int stack_is_empty(Stack *ptr_stack) 
{
	if(ptr_stack->ptr_list->number_of_Nodes==0)
        return 1;
    return 0;
}

const int stack_peek(Stack *ptr_stack)
{
	return Node_get_data(ptr_stack->ptr_list->head);
}

void stack_destroy(Stack *ptr_stack) 
{
	list_destroy(ptr_stack->ptr_list);
}


int postfix_eval(const char* expression) 
{
    Stack ptr_stack;
   List plist;
   (&ptr_stack)->ptr_List=(&plist);
   stack_initialize(&ptr_stack);
   int i = 0; int op1 ,op2 ,res;
   while(expression[i] != '\0')
   {
   	if(isdigit(expression[i]))
   		stack_push(&ptr_stack, expression[i] - '0');
   	else
   	{
   		op1 = stack_peek(&ptr_stack);
   		stack_pop(&ptr_stack);
   		op2 = stack_peek(&ptr_stack);
   		stack_pop(&ptr_stack);
   		switch(expression[i])
   		{
   			case '+': res =  op1 + op2;
							break;
			case '-': res =  op1 - op2;
							break;
			case '*': res =  op1 * op2;
							break;
			case '/': res =  op1/op2;
							break;
   		}

   		stack_push(&ptr_stack, res);
   	}

   }

   return stack_peek(&ptr_stack);

}
