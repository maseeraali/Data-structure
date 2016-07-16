/* Convert Infix Expression into Postfix Expression */
/* Code by Maseera Ali
   13BCS0032             */

#include<stdio.h>
#include<string.h>

char stack [30];
int top = -1;

void push (char sym)
{
	if (top == 29)
	{
		printf ("\n stack is overflow");
		return;
	}
	top++;
	stack[top]=sym;
}

char pop ( )
{
	char i;
	if (top ==-1)
	{
		printf ("\n stack is empty");
		return(0);
	}
	i=stack [top];
	top--;
	return (i);
}

int prec (char ch)
{
	if (ch=='^')
		return (5);
	if (ch=='*' || ch=='/')
		return (4);	
	if (ch=='+' || ch=='-')
		return (3);
	else
		return (2);
}

void infix_to_postfix (char infix [ ])
{
	int length;
        int index = 0, pos= 0;
	char symbol, temp;
	char postfix [50];
	length = strlen(infix);
	infix[length]=')';
	push('(');
	while (index <= length)
	{
		symbol = infix[index];
		switch (symbol)
		{
			case '(' : push (symbol);
				break;
			case ')' : temp = pop ( );
				   while (temp != '(')
				   {
					postfix [pos]=temp;
					pos++;
					temp=pop ();
				   }
				break;
			case '+' :
			case '-' :
			case '*' :
			case '/' :
			case '^' :
				while (prec (stack[top]) >= prec (symbol))
				{
					temp = pop();
					postfix [pos]= temp;
					pos++;
				}
				push (symbol);
				break;
			default:postfix [pos++] = symbol;
				break;
		}
		index++;
	}
	postfix [pos++] = '\0';
	printf("\nEquivalent postfix expression is:\n");
	puts (postfix);
	return;
}					
void main ( )
{
	char infix [30];
	printf ("\n Enter the infix expression:\n");
	gets (infix);
	infix_to_postfix (infix);
}

