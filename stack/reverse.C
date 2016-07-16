/* Program to reverse a string using stack */
/* Code by Maseera Ali
   13BCS0032             */

#include <stdio.h>

int top=-1;
char stack [MAX];
char pop( )
{
	if (top ==-1)
	printf ("stack underflow \n");
	else
	return stack [top--];
}
void push(char item)
{
	if (top==MAX-1)
	printf ("Stack overflow\n");
	else
	stack[++top] = item;
	return;
}

int main ( )
{
	char str[20];
	int i;
	printf ("\nEnter the string :\n");
	gets (str);
	for (i=0; i<strlen(str); i++)
	push (str[i]);
	for (i=0; i<strlen(str); i++)
	str[i]=pop ( );
	printf ("\nReversed string is :\n");
	puts (str);
}


