/* Decimal to binary conversion using stack */
#include <stdio.h>
int main ( )
{
	int stack[30], dec, rem, top=0;
	printf ("\nEnter decimal number:\n");
	scanf("%d", &dec);
	while (dec!=0)
	{
		rem=dec%2;
		top++;
		stack[top]=rem;
		dec=dec/2;
	}
	printf ("\nThe equivalent binary number is\n");
	for (; top>0; top--)
	{
		printf ("%d", stack[top]);
	}
	printf("\n");
}
