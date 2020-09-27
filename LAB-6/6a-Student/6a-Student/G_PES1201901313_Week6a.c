#include "6a.h"


static Node* create_Node(int data, Node* link)
{
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data; 
	temp -> link = link;
	return temp;
}

void List_initialize(List* ptr_List) 
{
//TODO
    ptr_List->head=NULL;
    ptr_List->number_of_Nodes=0;
    return;
}

void List_insert_front(List* ptr_List, int data) 
{
//TODO
    
     Node *temp=create_Node(data,ptr_List->head);
    if(ptr_List->head==NULL)
    {
    ptr_List->head=temp;
    ptr_List->number_of_Nodes++;
        return;
    }
    temp->link=ptr_List->head;
    ptr_List->head=temp;
    ptr_List->number_of_Nodes++;
    return ;
}

const int Node_get_data(Node *Node_ptr) 
{
	//TODO
    if(Node_ptr==NULL)
        return 0;
    
    return Node_ptr->data;
    
}

void List_delete_front(List* ptr_List)
{
	//TODO
    Node *temp;
     if(ptr_List==NULL)
         return ;
    
     temp=ptr_List->head;
     ptr_List->head=temp->link;
    
     free(temp);
     ptr_List->number_of_Nodes--;
     return ;
}

void List_destroy(List* ptr_List) 
{
	//TODO
    Node *temp, *u=NULL;
    temp=ptr_List->head;
    while (temp != NULL){
        u=temp;
        temp=temp->link;
        free(u);
    }
    free(ptr_List);
}


void stack_initialize(Stack *ptr_stack) 
{
	// TODO
    ptr_stack->ptr_List=(List*)malloc(sizeof(List));
    List_initialize(ptr_stack->ptr_List);
}

void stack_push(Stack *ptr_stack, int key)
{
	// TODO
    List_insert_front(ptr_stack->ptr_List,key);
           return;
}

void stack_pop(Stack *ptr_stack) 
{
	// TODO
    List_delete_front(ptr_stack->ptr_List);
    return;
}

int stack_is_empty(Stack *ptr_stack) 
{
	// TODO
    if(ptr_stack->ptr_List->number_of_Nodes==0)//if the number of nodes=0 the stack is empty
        return 1;
    else
        return 0;
}

const int stack_peek(Stack *ptr_stack)
{
	// TODO
    return ptr_stack->ptr_List->head->data;
}

void stack_destroy(Stack *ptr_stack) 
{
	// TODO
    List_destroy(ptr_stack->ptr_List);
}

int postfix_eval(const char* expression)
{
    // TODO
    Stack ptr_stack;
    List list;
        (&ptr_stack)->ptr_List = (&list);//the entire list adress is being stored
        stack_initialize(&ptr_stack);
    
   int i, res, op1, op2;
  


       for (i = 0; expression[i] ; i++) {

        
     if(expression[i]>='0' && expression[i]<='9')
        {
            stack_push(&ptr_stack,expression[i]-'0');
        }
         
       else  if (expression[i] == '+' || expression[i] == '-' || expression[i]== '*' || expression[i]== '/') {
           { if(stack_is_empty(&ptr_stack))
                   return 0;}
  
        op1 = stack_peek(&ptr_stack);
               stack_pop(&ptr_stack);
        op2 =stack_peek(&ptr_stack);
               stack_pop(&ptr_stack);

               switch (expression[i]) /* ch is an operator */
               {
               case '*':
                     res =  op1 * op2;
                   stack_push(&ptr_stack,res);
                   break;

               case '/':
                     res= op2/op1;
                  stack_push(&ptr_stack, res);
                   break;
                case '+':
                    res = op1 + op2;
                    stack_push(&ptr_stack, res);
                    break;

                case '-':
                   res = op2 - op1;
                    stack_push(&ptr_stack, res);
                    break;
                default:
                	break;
                }


                               }
                           }
    return stack_peek(&ptr_stack);
                       
}
