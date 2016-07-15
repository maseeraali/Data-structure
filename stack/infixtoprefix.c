/* Convert infix expression to prefix expression*/
#include<stdio.h>
#include<string.h>
#define MAX 20

char stack[MAX];
int top=-1;
void push (char item)
	{
	top++;
	stack[top]=item;
	return;	
}

char pop( )
	{
	char a;
	a=stack[top];
	top--;
	return a;
	}
int prcd(char symbol)
    {
	switch(symbol)
	{
	case '+':
	case '-':
	return 2;
	case '*':
	case '/':
	return 3;
	case '^':
	return 4;
	case '(':
	case ')':
	return 1;
	}
     return 0;
     }
int isoperator (char symbol)
      {
	switch (symbol)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '(':
	case ')':
	return 1;
	default:
	return 0;
	}
    }
void convertip(char infix[ ], char prefix [ ])
 {
	int i, symbol, j=0;
	stack[++top]=')';
	for(i=strlen(infix)-1;i>=0;i--)
		{
		symbol=infix[i];
		if(isoperator(symbol)==0)
			{
			prefix[j]=symbol;
			j++;
			}
		else
		   {
			if(symbol==')')
			  {
				push(symbol);
			   }
			else if(symbol=='(')
			{
				while (stack[top]!=')')
				{
				   prefix[j]=pop( );
				   j++;
				}
			pop ();
			}
			else
			{
				while(prcd(symbol)<=prcd(stack[top]))
					{
					prefix[j]=pop( );
					j++;
					}
				push(symbol);
			}
		  }
      }
  while(stack[top]!=')')
	{
	prefix[j]=pop( );
	j++;
	}
	prefix[j]='\0';
	for (i=0; i<strlen(prefix); i++)
	push (prefix[i]);
	for (i=0; i<strlen(prefix); i++)
	prefix[i]=pop ( );
	return;
}
int main ()
	{
	char infix[20], prefix[20];
	printf("\nEnter the valid infix string:\n");
	gets(infix);
	convertip(infix, prefix);
	printf("The corresponding prefix string is:\n");
	puts(prefix);
	return 0;
	}


