/*Program to implement binary search tree using array */

#include <stdio.h>
#include <stdlib.h>
 
char tree[100],data; 
int n=1;
 
 
void search(int i)
{
    if ((data > tree[i]) && (tree[2*i+1] != NULL))    
    search(2*i+1);
    else if ((data > tree[i]) && (tree[2*i+1] == NULL))
    tree[2*i+1] = data;
    else if ((data < tree[i]) && (tree[2*i] != NULL))   
    search(2*i);
    else if ((data < tree[i]) && (tree[2*i] == NULL))
    tree[2*i] = data;
}
void insert()
{
    
    int ch=1;
	while(ch==1){
    printf("Enter data: ");
    fflush(stdin);
	scanf("%c", &data);

    if (n == 1) 
    tree[1] = data;
    else    
    search(1); 
    n++;
   printf("To continue press 1 else 0");
   scanf("%d",&ch);
   
	} 
}

int inorder(int t)
{
    if (tree[t] == NULL)
        return 0;    
    inorder(2*t);
    printf("%c\t", tree[t]);    
    inorder(2*t+1);
}

int main()
{
	insert();
	inorder(1);
		
	return 0;
}
