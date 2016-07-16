/* Program to swap two nodes of a single linked list. */
/* Code by Maseera Ali
   13BCS0032             */

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


int swap(){
	int a,b,n,flag=0,flag1=0;
	struct link_list *ptr1,*ptr2,*n1,*n2;
	if(start==NULL)
	{
		printf("Empty link_list\n");
		return 0;
	}
	ptr1=start;
	ptr2=start;
	printf("Enter the info you want to swap");
	scanf("%d %d",&a,&b);
	while(ptr1!=NULL)
	{
		if(start->info==a||start->info==b)
			flag1=1;
		if(ptr1->link->info==a||ptr1->link->info==b||flag1==1)
		{
			ptr2=ptr1;
			if(flag1==1)
				n=ptr1->info;
			else
				n=ptr1->link->info;
			while(ptr2!=NULL)
			{
				if((ptr2->link->info==a||ptr2->link->info==b)&&ptr2->link->info!=n)
				{
					flag=1;
					break;
				}
				ptr2=ptr2->link;
			}
			break;
		}
		ptr1=ptr1->link;
	}
	if(flag==0)
		printf("\nPlease make sure that the infos are present in the link list.\n");
	if(flag1==1)
	{
		start=ptr2->link;
		ptr2->link=ptr1;
		temp=start->link;
		start->link=ptr1->link;
		ptr1->link=temp;
	}
	else
	{
		n1=ptr1->link;
		n2=ptr2->link;
		temp=n2->link;
		ptr1->link=n2;
		n2->link=n1->link;
		ptr2->link=n1;
		n1->link=temp;
	}
	display();

	return 0;
}
int main()
{	int n;
	while(1)
	{
		printf("\nWhat do you want to do\n1.enter at beginning\n2.enter at mid\n3.enter at last\n4.display\n5.Swap\n6.exit\n");
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
			case 5:swap();
				break;
			default :exit(0);
		}
	}
return 0;
}
