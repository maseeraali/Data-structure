/* Program to implement the depth first search in a graph. */
/* Code by Maseera Ali
   13BCS0032             */

#include<stdio.h>
#define MAX 20

int top=-1;
int stack [MAX], n;
int status[20];
int ajMat[20][20];

void display()
{
     int i,j;
     printf("Adjacency matrix of Graph : \n");
     for(i=0; i<n; i++)
	{
		for(j=0;j<n;j++)
	      		printf("%d\t",ajMat[i][j]);
		printf("\n");		
	}
}

int pop( )
{
	if (top ==-1)
	printf ("stack underflow \n");
	else
	return stack [top--];
}
void push(int item)
{
	if (top==MAX-1)
	printf ("Stack overflow\n");
	else
	stack[++top] = item;
	return;
}

int dfs(int i)
{
     int j;
     push(i);
     status[i]=2;
     while(top!=-1)
     {
	int temp=pop();
	status[temp]=3;
	printf("-%d-",temp);
	for(j=n-1;j>=0;j--)
	{
		if(ajMat[temp][j]!=0 && status[j]==1)
		{
			push(j);
			status[j]=2;
		}
	}
    }	
    printf("\n");			
}
int main()
{
    int i,j;
    printf("Enter the number of nodes in a graph");
    scanf("%d",&n);
    printf("Enter the value in adjancency matrix in from of '0' or '1'\n");
    for(i=0;i<n; i++)
    {
        for( j=0; j<n; j++)

        {
             scanf("%d",&ajMat[i][j]);
        }
    }
    for(i=0;i<n;i++)
    	status[i]=1;
    display();
    dfs(0);
}











