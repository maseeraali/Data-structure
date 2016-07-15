/* Program to implement selection sort. */ 

#include<stdio.h>
#define MAXSIZE 50

void selection(int x[], int n)
{
int i, j, min,pos;
for (i = 0; i<n; i++){
	min = x[i];
	pos = i;
	for (j =i+1; j<=n; j++)
	{
		 if (x[j] < min){
			   min = x[j];
			   pos = j;
		 }
	}
	x[pos] = x[i];
	x[i] = min;
	}
} /*end of selection sort*/

void main()
{
       int x[MAXSIZE],n, i;
	printf("\n Enter number of elements ");
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{	printf("\n Enter element %d ",i+1);
		scanf("%d",&x[i]);
	}
	selection(x, n);
	printf("\n Sorted list is:\n\n");

	for (i = 0; i < n; i++)
		printf("%d ", x[i]);
	printf("\n");
}
