/* Operations performed on the stack */
/* Code by Maseera Ali
   13BCS0032             */

#include <stdio.h>
#include <stdlib.h>
#define maxsize 30
int stack [maxsize],top=-1;

void display ()
{
	int i;
	printf("\nElements in stack are:\n");
	for(i=0;i<=top;i++)
	{
		printf("%d\t",stack[i]);
	}
}

void push (int no)
{
	if (top==maxsize-1)
	{
		printf ("\n stack overflow");
		return;
	}
	top++;
	stack[top]=no;
	display();
}

int pop ()
{
	int no;
	if (top==-1)
	{
		printf ("\n stack underflow");
		return -1;
	}
	no=stack[top];
	top--;	
	display();
	return no;
}

void main ( )
{
	int n,no;
	while(n)
	{
		printf ("\nEnter your choice\n1.Push\n2.Pop\n3.Exit\n");
		fflush(stdin);
		scanf ("%d", &n);
		switch(n)
		{
			case 1: printf ("Enter number: \n");
					scanf ("%d", &no);
					push (no);
				break;
			case 2: no=pop ();
				break;
			default:exit (0);
		}
    }
}

