/* Program to implement single linked list */

#include<stdio.h>
#include<stdlib.h>
struct link_list
{
	int info;
	struct link_list *link;
}*start=NULL,*end=NULL,*NEW,*temp;
int enter_beg()
{
	NEW=(struct link_list *)malloc(sizeof(struct link_list));
	printf("Enter the info");
	scanf("%d",&(NEW->info));
	if(start==NULL)
	{
		start=NEW;
		end=NEW;
		NEW->link=NULL;
	}
	else
	{
		NEW->link=start;
		start=NEW;
	}
return 0;
}
int enter_last()
{
	NEW=(struct link_list *)malloc(sizeof(struct link_list));
	printf("Enter the info");
	scanf("%d",&(NEW->info));
	if(start==NULL)
	{
		start=NEW;
		end=NEW;
		NEW->link=NULL;
	}
	else
	{
		end->link=NEW;
		end=NEW;
		NEW->link=NULL;
	}
return 0;
}
int enter_mid()
{	int n,c=1;
	temp=start;
	NEW=(struct link_list *)malloc(sizeof(struct link_list));
	printf("Enter the node number ");
	scanf("%d",&n);
	while(c!=n)
	{  c++;
	  temp=temp->link;
	}
	printf("Enter the info");
	scanf("%d",&(NEW->info));
	NEW->link=temp->link;
	temp->link=NEW;

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
			temp=temp->link;
		}
       }
}
int del()
{
	int n,flag;
	if(start==NULL)
	{
		printf("No nodes to delete\n");
		return 0;
	}
	printf("Enter the info you want to delete");
	scanf("%d",&n);
	temp=start;
	if(temp->info==n)    //beginning
	{
		start=temp->link;
		return 0;
	}
	while(temp->link->link!=NULL)  // middle
	{
		if(temp->link->info==n)
		{
			flag=1;
			break;
		}
		temp=temp->link;
	}
	if(flag==1)
	{
		temp->link=temp->link->link;
	}
	else
	{
		if(temp->link->info==n)         //last
		{
			temp->link=NULL;
			end=temp;
		}		
	
		else
			printf("No such node exists\n");
	}
}

int len(){
	int c=0;
	temp=start;
	while(temp!=NULL)
	{
		temp=temp->link;
		c++;
	}
	printf("No of nodes - %d\n",c );
	return 0;
}

int find(){
	int c=1,n;
	if(start==NULL)
	{
		printf("Empty link_list\n");
		return 0;
	}
	temp=start;
	printf("Enter the info");
	scanf("%d",&n);
	printf("Location of %d -\n",n);
	while(temp!=NULL)
	{
		if(temp->info==n)
		{
			printf("%d\t",c);
		}
		temp=temp->link;
		c++;
	}
	return 0;
}
int main()
{	int n;
	while(1)
	{
		printf("\nWhat do you want to do\n1.enter at beginning\n2.enter at mid\n3.enter at last\n4.display\n5.Delete\n6.length\n7.Find info\n8.exit\n");
		fflush(stdin);
		scanf("%d",&n);

		switch(n)
		{
			case 1:enter_beg();
				break;
			case 2:enter_mid();
				break;
			case 3:enter_last();
				break;
			case 4:display();
				break;
			case 5:del();
				break;
			case 6: len();
				break;
			case 7: find();
				break;
			case 8:exit(0);
		}
	}
return 0;
}
