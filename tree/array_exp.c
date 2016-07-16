/* Program to represent a postfix expression as a tree */
/* Code by Maseera Ali
   13BCS0032             */

#include<stdio.h>
#include<string.h>
#include<math.h>

char tree[30],s[30];

void print()
{
    int i=1,k=0,j,l,row=(strlen(tree)-1)/2;
	while(tree[i]!='\0')
	{
  		for(j=1;j<=row;j++) 
  			printf("  ");
		 for(l=1;l<=(pow(2,k));l++)
		 {
 			printf("%c  ",tree[i]);
 			i++;
 		}			
 		printf("\n");
 		k++;
 		row--;
	}
	i=1;
	printf("Array representation of tree\n\n");
  	while(tree[i]!='\0')
  	{
   	     printf("%c\t",tree[i]);
	   	 i++;
  	}
 
return;
}

int main()
{
 int i,j=1,flag=0,sum=0;
 
 tree[0]='0';
 printf("Enter the Postfix Expression\n");
 gets(s);
 i=strlen(s);
 i--;
 
 while(i>=0)
{  
  	flag=0;
  	if(i==(strlen(s)-1))
 	{
   		tree[j]=s[i];
    	i--;
  
 	 }
 	else
 	{
  		if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
   		{
    		if(tree[j*2+1]=='\0')
    		{
				j=j*2+1;
        		tree[j]=s[i];
				i--;
    		}
   			else if(tree[j*2]=='\0')
    		{
				j=j*2;
				tree[j]=s[i];
				i--;    
   			 }
  	 	}
   		else
   		{
     		if(tree[j*2+1]=='\0')
			{
        		tree[j*2+1]=s[i];
				i--;
			}
     		else if(tree[j*2]=='\0')
			{
			    tree[j*2]=s[i];
				i--;
				j=j/2;
			}
   		}
   	}
}
print();
return 0;
}
