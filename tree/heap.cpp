//Program to implement heap tree.

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
    int i=1,k=0,j,l,row=n/2;
	while(i<=n)
	{
  		for(j=1;j<=row;j++) 
  			printf("  ");
		 for(l=1;l<=(pow(2,k))&&i<=n;l++)
		 {
 			printf("%d  ",tree[i]);
 			i++;
 		}			
 		printf("\n");
 		k++;
 		row--;
	}
	i=1;
	printf("Array representation of tree\n\n");
  	while(i<=n)
  	{
   	     printf("%d\t",tree[i]);
	   	 i++;
  	}
 	printf("\n");
return;
} 
void delete_heap()
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
			return;
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
	tree[ptr]=last;
	return;
	
}

void del()
{
	int ch=1;
	while(ch==1){
    delete_heap();
    printf("%d is deleted successfully!\n",data);
    print();
   printf("To continue press 1 else 0");
   scanf("%d",&ch);
   }
}

int main()
{
	char ch; 
    insert();
	print();
	printf("If you want to delete - (y/n)");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y')
	del();
	return 0;
}
