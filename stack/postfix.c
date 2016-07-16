/* Program to Evaluate Postfix Notation */
/* Code by Maseera Ali
   13BCS0032             */

#include<stdio.h>
#include<string.h>
#include<math.h>
int stack [30];
int top = -1;
void push (int num)
{
	if (top == 29)
	{
		printf ("\n stack is overflow");
		return;
	}
	top++;
	stack[top]=num;
}

int pop ( )
{
	int i;
	if (top ==-1)
	{
		printf ("\n stack is empty");
		return(0);
	}
	i=stack [top];
	top--;
	return (i);
}
void main( )
{
	char S[80];
	int i, n, x=0, y=0;
	printf ("\n Enter the valid postfix notation :");
	gets(S);
	n = strlen(S);
	printf ("The value of the postfix notation is :");
	for (i=0;i<n; i++)
	{
		switch (S[i])
		{
			case '+' :y=pop();
				x=pop();
				x=x+y;
				push(x);
				break;
		        case '-' :y=pop();
				x=pop();
				x=x-y;
				push(x);
				break;
			case '*' :y=pop();
				x=pop();
				x=x*y;
				push(x);
				break;
			case '/' :y=pop();
				x=pop();
				x=x/y;
				push(x);
				break;
			case '^' :y=pop();
				x=pop();
				x=pow(x,y);
				push(x);
				break;
			
			default :if (S[i]>=48 && S[i]<=57)
				push(S[i]-48);
	
		}
	}
	printf("%d\n", pop());
}
