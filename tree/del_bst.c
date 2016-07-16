// Program to delete a node in a binary search tree 
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
struct btnode * minValueNode(struct btnode* node)
{
    struct btnode* current = node;
    while (current->l != NULL)
        current = current->l;

    return current;
}

struct btnode* deleteNode(struct btnode* root, int key)
{
   
    if (root == NULL) return root;

    if (key < root->value)
        root->l = deleteNode(root->l, key);

    else if (key > root->value)
        root->r= deleteNode(root->r, key);

    else
    {
    	
	        if (root->l == NULL)
	        {
	            temp = root->r;
	            free(root);
	            return temp;
	        }
	        else if (root->r == NULL)
	        {
	            temp = root->l;
	            free(root);
	            return temp;
	        }
		
	        temp = minValueNode(root->r);
	
	        root->value = temp->value;
	
	        root->r = deleteNode(root->r, temp->value);
	}
    return root;
}

int main()
{
	insert();
    int data;
    if (root == NULL)
    {
        printf("No elements in a tree to delete");
        return;
    }
    printf("\nInorder traversal is\n");
    inorder(root);
	
	printf("\nEnter the data to be deleted : ");
    scanf("%d", &data);
	deleteNode(root, data);
	printf("Node deleted successfully!\n Inorder Traversal is-\n");
    inorder(root);
		
	return 0;
}
int inorder(struct btnode *t)
{
    if (t == NULL)
        return;    
    inorder(t->l);
    printf("%d\t", t->value);    
    inorder(t->r);
}
