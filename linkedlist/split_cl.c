/* Program to split a circular linked list into two small circular linked list. */

#include<stdio.h>
#include<stdlib.h>
struct link_list
{
	int info;
	struct link_list *link;
}*start=NULL,*NEW,*temp;
int enter()
{
	NEW=(struct link_list *)malloc(sizeof(struct link_list));
	printf("Enter the info");
	scanf("%d",&(NEW->info));
	if(start==NULL)
	{
		start=NEW;
		NEW->link=NEW;
	}
	else
	{
		temp=start;
		while(temp->link!=start)
			temp=temp->link;
		NEW->link=start;
		temp->link=NEW;
	}
display(start);
return 0;
}

int display(struct link_list *start)
{       if(start==NULL)
	printf("No nodes to display");
	else
       {	temp=start;
		do
		{
			printf("%d\t",temp->info);
			temp=temp->link;
		}
		while(temp!=start);
       }
       printf("\n");
       return 0;
}

int split()
{
	if(start==NULL)
		return 0;
	if(start->link==start)
	{
		printf("Only 1 node in linked list\n");
		return 0;
	}
	struct link_list *slowptr,*fastptr,*start2;
	fastptr=start;
	slowptr=start;
	while(fastptr->link!=start && fastptr->link->link!=start)
	{
		fastptr=fastptr->link->link;
		slowptr=slowptr->link;
	}
	if(slowptr==fastptr)
	{
		start2=fastptr->link;
		start->link=start;
		start2->link=start2;
	}
	else
	{
		start2=slowptr->link;
		slowptr->link=start;
		if(fastptr->link==start)
			fastptr->link=start2;
		else
			fastptr->link->link=start2;
	}	
	printf("First -\n");
	display(start);
	printf("Second -\n");
	display(start2);
	return 0;	
}

int main()
{	int n;
	while(1)
	{
		printf("\nWhat do you want to do\n1.enter\n2.split\n3.exit\n");
		fflush(stdin);
		scanf("%d",&n);

		switch(n)
		{
			case 1:enter();
				break;
			case 2:split();
				break;
			case 3:exit(0);
		}
	}
return 0;
}
