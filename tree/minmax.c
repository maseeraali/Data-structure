// Program to find kth maximum and minimum data in a binary search tree
/* Code by Maseera Ali
   13BCS0032             */

#include <stdio.h>
#include <stdlib.h>
 
struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
}*root = NULL, *temp = NULL;
int count = 0;
int smallest(struct btnode *t);
int largest(struct btnode *t);
void search(struct btnode *t)
{
    if ((temp->value > t->value) && (t->r != NULL))    
    search(t->r);
    else if ((temp->value > t->value) && (t->r == NULL))
    t->r = temp;
    else if ((temp->value < t->value) && (t->l != NULL))   
    search(t->l);
    else if ((temp->value < t->value) && (t->l == NULL))
    t->l = temp;
}
void insert()
{
    
    int data,ch=1;
	while(ch==1){
    printf("Enter data: ");
    scanf("%d", &data);
    temp = (struct btnode *)malloc(sizeof(struct btnode));
    temp->value = data;
    temp->l = temp->r = NULL;
    if (root == NULL) 
    root = temp;
    else    
    search(root); 
 
    printf("To continue press 1 else 0");
    scanf("%d",&ch);
  
	} 
}
int smallest(struct btnode *t)
{
    if (t->l != NULL)
        return(smallest(t->l));
    else    
        return (t->value);
}

int largest(struct btnode *t)
{
    if (t->r != NULL)
        return(largest(t->r));
    else    
        return(t->value);
}

int kmin(struct btnode *t,int k)
{
	if (t == NULL)
		return;
	kmin(t->l,k);
	count++;
	if(count == k)
		printf("%d",t->value);
	kmin(t->r,k);		
}

int kmax(struct btnode *t,int k)
{
	if (t == NULL)
		return;
	kmax(t->r,k);
	count++;
	if(count == k)
		printf("%d",t->value);
	kmax(t->l,k);		
}

int main()
{
	insert();
	int ch,k,temp;
 
 	printf("1 for Maximum No\n");
   	printf("2 for Minimum no\n");
    printf("3 for kth min\n");  
	printf("4 for kth max\n");
	printf("5 for Exit\n");   
    while(1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
			case 1:		k=largest(root);
						printf("The maximum no in the binary search tree= %d",k);
						break;
			case 2:		k=smallest(root);
						printf("The minimum no in the binary search tree= %d",k);	
						break;
			case 3:		printf("Enter the value of k");
						scanf("%d",&k);
						count=0;
						printf("The %dth minimum no in the binary search tree= ",k);	
						kmin(root,k);
						break;
			case 4:		printf("Enter the value of k");
						scanf("%d",&k);
						count=0;
						printf("The %dth maximum no in the binary search tree= ",k);	
						kmax(root,k);
						break;
		
			case 5:		exit(0);
        }
    }
    return 0;
}
