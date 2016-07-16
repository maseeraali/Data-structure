/* Program to implement the breadth first search in a graph. */
/* Code by Maseera Ali
   13BCS0032             */

#include<stdio.h>
#define MAX 5

int cqueue[MAX];
int front=-1,rear=-1, n;
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

void insert(int item )
   {
   		if((front==0 && rear==MAX-1) || (front==rear+1))
   		{
   			printf("Queue is Overflow\n");
   			return;
   		}
   		if (front==-1)
   		{
   			front = 0;
   			rear = 0;
   		}
   		else
   		if (rear==MAX-1) 
   			rear = 0;
   		else
   			rear = rear + 1;
   			cqueue[rear] = item;
   }

  int del( )
   {
   		if (front == -1)
   		{
   			printf("Queue Underflow\n");
   			return;
   		}
   		int temp = cqueue[front];
   		if(front == rear)
   		{
   			front = -1;
   			rear = -1;
   		}
   		else
   		if(front==MAX-1)
   			front = 0;
   		else
   			front = front + 1;
		return temp;
   }

int bfs(int i)
{
     int j;
     insert(i);
     status[i]=2;
     while(front!=-1)
     {
	int temp=del();
	status[temp]=3;
	printf("-%d-",temp);
	for(j=0;j<n;j++)
	{
		if(ajMat[temp][j]!=0 && status[j]==1)
		{
			insert(j);
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
    bfs(0);
}











