/* Program to implement Prims algorithm */
/* Code by Maseera Ali
   13BCS0032             */

#include<stdio.h>
#include<stdlib.h>
#define infinity 9999
int u,v,n,i,j,count=1;
int mstSet[10]={0},min,mincost=0,cost[10][10];
void prims()
{
     mstSet[1]=1;
	while(count < n)
	{
		for(i=1,min=infinity;i<=n;i++)
		for(j=1;j<=n;j++)
		if(cost[i][j]< min && mstSet[i]!=0){
			min=cost[i][j];
			u=i;
			v=j;
		}
		if( mstSet[v]==0)
				{
                        char c1=char(u+64);
                        char c2=char(v+64);
  			printf("\n\n  %c --> %c | Cost:%d",c1,c2,min);
			count++;
			mincost+=min;
			mstSet[v]=1;
		}
		cost[u][v]=cost[v][u]=infinity;
	}
	printf("\n\nMinimum cost of the spanning tree = %d \n\n",mincost);
}
int main()
{
	printf("\nEnter the number of nodes:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
			cost[i][j]=infinity;
		}
	}
	prims();
	return 1;
}
	
