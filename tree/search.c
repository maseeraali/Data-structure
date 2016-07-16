//Program to search a data in a binary search tree
/* Code by Maseera Ali
   13BCS0032             */ 

#include <stdio.h>
#include <stdlib.h>
int n; 
struct btnode
{
    int value;
    struct btnode *l;
    struct btnode *r;
}*root = NULL, *temp = NULL, *t2, *t1;
 
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
void searchElement(struct btnode *t)
{
  if(t->value==n)
printf("Element Found\n");
 else if(n>t->value && t->r!=NULL)
  searchElement(t->r);
 else if(n>t->value && t->r==NULL)
 printf("Element Not Found\n");
 else if(n<t->value && t->l!=NULL)
 searchElement(t->l);
 else if(n<t->value && t->l==NULL)
  printf("ElementNot Found\n");
}
 
int main()
{
		
	insert();
	printf("Enter the element to be searched");
	scanf("%d",&n);
	searchElement(root);

return 0;
}
