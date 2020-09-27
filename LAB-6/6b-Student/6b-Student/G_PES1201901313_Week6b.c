#include "6b.h"

	stack* stack_initialize(int size)
	{

		stack * ptr_stack=(stack *)malloc(sizeof(stack));
		ptr_stack->top=-1;
		ptr_stack->arr=(int *)malloc(size*sizeof(int));
		return ptr_stack;
	}

	void stack_push(stack *ptr_stack, int key) 
	{

		ptr_stack->arr[++ptr_stack->top]=key;
	}

	void stack_pop(stack *ptr_stack)
	{
		if(stack_is_empty(ptr_stack))
		{
			ptr_stack->arr[ptr_stack->top--];
		}
	}

	int stack_is_empty(stack *ptr_stack)
	{
		if(ptr_stack->top==-1)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	int stack_peek(stack *ptr_stack) 
	{
		return ptr_stack->arr[ptr_stack->top];
	}

	void stack_destroy(stack *ptr_stack) 
	{
		free(ptr_stack->arr);
		free(ptr_stack);
	}

	void convert_infix_to_postfix(const char *source_infix,char *target_postfix)
	{

		int i=0,j=0;
		int len(const char *s)
		{
			int n=0;
			while(s[n]!='\0')
			{
				n+=1;
			}
			return n;
		}
		stack * ptr_stack=stack_initialize(len(source_infix));
		void brac(char c)
		{
			if(c=='(')
			{
				stack_push(ptr_stack,c);
				i+=1;
				while(source_infix[i]!=')')
				{
					c=source_infix[i];
					if(c=='(' || c=='[' || c=='{')
					{
						brac(c);
					}
					else if((c=='+') || (c=='-') || (c=='*') || (c=='/'))
					{
						stack_push(ptr_stack,c);
						i+=1;
					}
					else
					{
						target_postfix[j]=c;
						j+=1;
						i+=1;
					}
				}
				i+=1;
				while(ptr_stack->arr[ptr_stack->top]!='(')
				{
					int y=stack_peek(ptr_stack);
					stack_pop(ptr_stack);
					target_postfix[j]=y;
					j+=1;
				}
				stack_pop(ptr_stack);
			}
			else if(c=='{')
			{
				stack_push(ptr_stack,c);
				i+=1;
				while(source_infix[i]!='}')
				{
					c=source_infix[i];
					if(c=='(' || c=='[' || c=='{')
					{
						brac(c);
					}
					else if((c=='+') || (c=='-') || (c=='*') || (c=='/'))
					{
						stack_push(ptr_stack,c);
						i+=1;
					}
					else
					{
						target_postfix[j]=c;
						j+=1;
						i+=1;
					}
				}
				i+=1;
				while(ptr_stack->arr[ptr_stack->top]!='{')
				{
					int y=stack_peek(ptr_stack);
					stack_pop(ptr_stack);
					target_postfix[j]=y;
					j+=1;
				}
				stack_pop(ptr_stack);
			}
			else if(c=='[')
			{
				stack_push(ptr_stack,c);
				i+=1;
				while(source_infix[i]!=']')
				{
					c=source_infix[i];
					if(c=='(' || c=='[' || c=='{')
					{
						brac(c);
					}
					else if((c=='+') || (c=='-') || (c=='*') || (c=='/'))
					{
						stack_push(ptr_stack,c);
						i+=1;
					}
					else
					{
						target_postfix[j]=c;
						j+=1;
						i+=1;
					}
				}
				i+=1;
				while(ptr_stack->arr[ptr_stack->top]!='[')
				{
					int y=stack_peek(ptr_stack);
					stack_pop(ptr_stack);
					target_postfix[j]=y;
					j+=1;
				}
				stack_pop(ptr_stack);
			}
		}
						
		while(source_infix[i]!='\0')
		{
		char chr=source_infix[i];
		if(chr=='(' || chr=='[' || chr=='{')
		{
			brac(chr);
		}
		else if((chr=='+') || (chr=='-') || (chr=='*') || (chr=='/'))
		{
			if(ptr_stack->top!=-1)
			{
				int c=ptr_stack->arr[ptr_stack->top];
				if(chr=='*')
				{
					if(c=='/')
					{
					int y=stack_peek(ptr_stack);
					stack_pop(ptr_stack);
					target_postfix[j]=y;
					j+=1;
					}
					else
					{
						stack_push(ptr_stack,chr);
						i+=1;
					}
				}
				else if(chr=='/')
				{
					if(c=='*')
					{
					int y=stack_peek(ptr_stack);
					stack_pop(ptr_stack);
					target_postfix[j]=y;
					j+=1;
					}
					else
					{
						stack_push(ptr_stack,chr);
						i+=1;
					}
				}
				else if(chr=='+')
				{
					if(c=='*' || c=='/' || c=='-')
					{
						int y=stack_peek(ptr_stack);
						stack_pop(ptr_stack);
						target_postfix[j]=y;
						j+=1;
					}
					else
					{
						stack_push(ptr_stack,chr);
						i+=1;
					}
				}
				else
				{
					if(c=='*' || c=='/' || c=='+')
					{
						int y=stack_peek(ptr_stack);
						stack_pop(ptr_stack);
						target_postfix[j]=y;
						j+=1;
					}
					else
					{
						stack_push(ptr_stack,chr);
						i+=1;
					}
				}
			}
			else
			{
				stack_push(ptr_stack,chr);
				i+=1;
			}
		}			
		else
		{
			target_postfix[j]=chr;
			j+=1;
			i+=1;
		}
		}
		while(ptr_stack->top!=-1)
		{
			int y=stack_peek(ptr_stack);
			stack_pop(ptr_stack);
			target_postfix[j]=y;
			j+=1;
		}
	}
