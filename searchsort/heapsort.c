/* Program to implement heap sort. */

#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
#include<math.h>
int tree[100],data; 
int n=0;
 
 void heap_insert()
 {
 	int par,ptr=n;
 	while(ptr>1)
 	{
 		par=ptr/2;
 		if(data<=tree[par])
 		{
 			tree[ptr]=data;
 			return;
 		}
 		tree[ptr]=tree[par];
 		ptr=par;
 	}
 	tree[1]=data;
 	return;
 }
 
 
 void insert()
{
    
    int ch=1;
    while(ch==1){
    printf("Enter data: ");
    fflush(stdin);
    scanf("%d", &data);
    n++;
    heap_insert(); 

    printf("To continue press 1 else 0");
    scanf("%d",&ch);
   } 
}

void print()
{
    int i=1;
	printf("heap tree:\n\n");
        while(i<=n)
  	{
   	     printf("%d\t",tree[i]);
	   	 i++;
  	}
 	printf("\n\n");
return;
}
int delete_heap()
{
	int last,ptr,left,right;
	data=tree[1];
	last=tree[n];
	n--;
	ptr=1,left=2,right=3;
	while(right<=n)
	{
		if(last >= tree[right]&& last >= tree[left])
		{
			tree[ptr]=last;
			return data;
		}
		 if(tree[right]<=tree[left])
		 {
		 	tree[ptr]=tree[left];
		 	ptr=left;
		 }
		 else
		 {
		 	tree[ptr]=tree[right];
		 	ptr=right;
		 }
		 left=2*ptr;
		 right=left+1;
	}
	if(left==n && last < tree[left])
	{
		tree[ptr]=tree[left];
		ptr=left;
	}
	if(n==1)
	ptr=1;
	tree[ptr]=last;
	return data;
	
}

void heapsort()
{
	int temp[100],i,n1=n;
	for(i=1;i<=n1;i++)
		temp[i]=delete_heap();
	for(i=1;i<=n1;i++)
	{
		tree[i]=temp[i];
		printf("%d\t",tree[i]);
	}
}

int main()
{
	insert();
	print();
	printf("Sorted Array is:\n");
	heapsort();
	return 0;
}
