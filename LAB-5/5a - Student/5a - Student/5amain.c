#include "5a.h"

static Node* create_Node(int data, Node* link)
 {
// TODO - create and allocate dynamic space
 	static Node* new;
	new=(struct Node *)(malloc(sizeof(struct Node)));
	new->data=data;
	new->link=link;
	return new;
}


void list_initialize(List* ptr_list)
{
//TODO - initialize structure members to default values
	ptr_list->head=NULL;
	ptr_list->number_of_Nodes=0;
}


void list_insert_front(List* ptr_list, int data)
{
//TODO - perform linked list implementation of push operation.
	struct Node* new;
	new=create_Node(data,ptr_list->head);
	ptr_list->head=new;
	(ptr_list->number_of_Nodes)++;
}


const int Node_get_data(Node *Node_ptr)
{
//TODO - return the top most element
	int top;
	top= Node_ptr->data;
	return top;
}


void list_delete_front(List* ptr_list)
{
//TODO - perform linked list implementation of pop operation.
	struct Node *temp=(struct Node *)(malloc(sizeof(struct Node)));
	temp=ptr_list->head;
	ptr_list->head=temp->link;
	free(temp);
	(ptr_list->number_of_Nodes)--;
}


void list_destroy(List* ptr_list)
{
//TODO - free the allocated space
	Node* trav = (Node*)malloc(sizeof(Node));
    Node* temp = (Node*)malloc(sizeof(Node));
    trav = ptr_list->head;
    temp = NULL;
    for(int i = 0; i < ptr_list->number_of_Nodes; i++)
    {
        temp = trav;
        trav = trav->link;
        free(temp);
    }
    free(ptr_list);
}

void Stack_initialize(Stack *ptr_Stack)
{
//TODO - get the memory allocation for stack, and intern call list initialize
	ptr_Stack -> ptr_list = malloc(sizeof(struct List));
	list_initialize(ptr_Stack->ptr_list);
}

void Stack_push(Stack *ptr_Stack, int key)
{
//TODO	 - call the function list_insert_front
	list_insert_front(ptr_Stack->ptr_list,key);
}

void Stack_pop(Stack *ptr_Stack)
{
//TODO- call the function list_delete_front
	list_delete_front(ptr_Stack->ptr_list);
}

int Stack_is_empty(Stack *ptr_Stack)
{
//TODO	- return 0 if stack is not empty
	if(ptr_Stack->ptr_list->number_of_Nodes == 0)
	{
        return 1;
    }
    else
    	return 0;
}

const int Stack_peek(Stack *ptr_Stack)
{
//TODO	- return the top most element of the stack
	int top;
	top=Node_get_data(ptr_Stack->ptr_list->head);
	return top;
}

void Stack_destroy(Stack *ptr_Stack)
 {
//TODO	- deallocate
 	list_destroy(ptr_Stack->ptr_list);
 	free(ptr_Stack);
}

int match_parenthesis(const char* string)
{
//TODO - implement the code to match paranthesis in a string which is passed as a parameter.
	Stack new_stack;
    Stack_initialize(&new_stack);

    while((*string) != '\0')
    {
        switch (*string)
        {
        
        case '{':
            Stack_push(&new_stack, 1);
            break;

        case '(':
            Stack_push(&new_stack, 2);
            break;

        case '[':
            Stack_push(&new_stack, 3);
            break;

        case '}':
            if(Stack_is_empty(&new_stack))
            	return 0;
            if(Stack_peek(&new_stack) == 1)
            	Stack_pop(&new_stack);
            break;

        case ')':
            if(Stack_is_empty(&new_stack))
            	return 0;
            if(Stack_peek(&new_stack) == 2)
            	Stack_pop(&new_stack);
            break;

        case ']':
            if(Stack_is_empty(&new_stack))
            	return 0;
            if(Stack_peek(&new_stack) == 3)
            	Stack_pop(&new_stack);
            break;
        }
        string++;
    }
    if(Stack_is_empty(&new_stack)) 
    	return 1;
    else
    	return 0;

    Stack_destroy(&new_stack);
}





