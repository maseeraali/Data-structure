//Program to implement preorder, postorder and inorder traversal of a binary search tree
/* Code by Maseera Ali
   13BCS0032             */

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int value;
    struct node *l;
    struct node *r;
}*root = NULL, *temp = NULL;
 
void inorder(struct node *t);
void preorder(struct node *t);
void postorder(struct node *t);
void search(struct node *t)
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
		
    temp = (struct node *)malloc(sizeof(struct node));
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
int main()
{
	
    insert();
    int ch;
 
   printf("1 for Inorder Traversal\n");
   printf("2 for Preorder Traversal\n");
   printf("3 for Postorder Traversal\n");
   printf("4 for Exit\n");   
    while(1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
		case 1:    
		inorder(root);
		break;
		case 2:    
		preorder(root);
		break;
		case 3:    
		 postorder(root);
		break;
		case 4:
		exit(0);
                }
    }
    return 0;
}
  
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->l);
    printf("%d\t ", root->value);
    inorder(root->r);
}
 

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d\t ", root->value);
    preorder(root->l);
    preorder(root->r);
}
 
void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->l);
    postorder(root->r);
    printf("%d\t", root->value);
}

