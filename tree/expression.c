// Program to evaluate the expression tree
/* Code by Maseera Ali
   13BCS0032             */

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
struct tree
{
	char data;
	struct tree *left,*right;
};
int top=-1;
struct tree *stack[20];
struct tree *node;
void push(struct tree *node)
{
	stack[++top]=node;
}
struct tree *pop()
{
	return(stack[top--]);
}
int check(char c)
{
	if(c=='+'||c=='-'||c=='/'||c=='*')
	return 2;
	else
	return 1;
}
int cal(struct tree *node)
{
	int ch;
	ch=check(node->data);
	if(ch==1)
	return(node->data-48);
	else if(ch==2)
	{
		if(node->data=='+')
		return(cal(node->left)+cal(node->right));
		else if(node->data=='-')
		return(cal(node->right)-cal(node->left));
		else if(node->data=='*')
		return(cal(node->left)*cal(node->right));
		else if(node->data=='/')
		return(cal(node->right)/cal(node->left));
	}
}
void operands(char b)
{
	node=(struct tree*)malloc(sizeof(struct tree));
	node->data=b;
	node->left=NULL;
	node->right=NULL;
	push(node);
}
void operators(char a)
{
	node=(struct tree*)malloc(sizeof(struct tree));
	node->data=a;
	node->left=pop();
	node->right=pop();
	push(node);
}
void traverse(struct tree *node)
{
	if(node!=NULL)
	{
		traverse(node->right);
		printf("%c",node->data);
		traverse(node->left);
	}
}
int main()
{
	int i,p,ans;
	char s[20];
	printf("Enter the expression tree in postfix form: ");
	fflush(stdin);
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		p=check(s[i]);
		if(p==1)
		operands(s[i]);
		else if(p==2)
		operators(s[i]);
	}
	ans=cal(stack[top]);
	printf("\nThe value of the postfix expression = %d\n",ans);
	printf("The actual traversal will be : ");
	traverse(stack[top]);
	printf("\n");
	return 0;
}

