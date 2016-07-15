/* Program to reverse a doubly linked list */

#include<stdio.h>
#include<stdlib.h>
struct link_list
{
	int info;
	struct link_list *right,*left;
}*start=NULL,*end=NULL,*NEW,*temp;
int enter()
{
	NEW=(struct link_list *)malloc(sizeof(struct link_list));
	printf("Enter the info");
	scanf("%d",&(NEW->info));
	if(start==NULL)
	{
		start=NEW;
		end=NEW;
		NEW->right=NULL;
		NEW->left=NULL;
	}
	else
	{
		end->right=NEW;
		NEW->left=end;
		end=NEW;
		NEW->right=NULL;
	}
display();
return 0;
}
int display()
{       if(start==NULL)
	printf("No nodes to display");
	else
       {	temp=start;
		while(temp!=NULL)
		{
			printf("%d\t",temp->info);
			temp=temp->right;
		}
       }
}

int reverse()
{
	struct link_list *value;
	temp=start;
	while(temp!=NULL)
	{
		value=temp->left;
		temp->left=temp->right;
		temp->right=value;
		temp=temp->left;
	}
	value=start;
	start=end;
	end=value;
	display();
}

int main()
{	int n;
	while(1)
	{
		printf("\nWhat do you want to do\n1.enter\n2.display\n3.reverse\n4.exit\n");
		fflush(stdin);
		scanf("%d",&n);

		switch(n)
		{
			case 1:enter();
				break;
			case 2:display();
				break;
			case 3:reverse();
				break;
			case 4:exit(0);
		}
	}
return 0;
}
