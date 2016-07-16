/* Program to implement binary search on an array */ 
/* Code by Maseera Ali
   13BCS0032             */

#include<stdio.h>
int n,arr[20];
void binsearch()
{
	int data,start=0,end=n-1,mid;	
	printf("\nEnter the element to be searched:");
	scanf("%d",&data);
	mid=(start + end)/2;
	while(data!=arr[mid] && start <=end)
	{
	if(data > arr[mid])
	start=mid+1;
	else
	end=mid-1;
	mid=(start+end)/2;
	}
	if(data==arr[mid])
	printf("\n%d found at position %d\n",data,mid + 1);
	if(start>end)
	printf("\n%d not found in array\n",data);
}

void sort()
{
int i,j,tmp;
for(i=0;i<n;i++)
{
	for(j=0;j<n-1;j++)
	{
		if(arr[j]>arr[j+1])
		{
			tmp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=tmp;
		}
	}
}
}

int main()
{
	int i;
	printf("\nHow many elements you want to enter in the array:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("\nEnter element %d:",i+1);
	scanf("%d",&arr[i]);
	}
	sort();
	binsearch();
}
