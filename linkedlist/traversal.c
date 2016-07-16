/* Program to traverse a linked list. */ 
/* Code by Maseera Ali
   13BCS0032             */

#include<stdio.h>
#include<stdlib.h>
 
struct node 
{
  int data;
  struct node *next;
};
 
int main()
{
  struct node* head = NULL;
  struct node* second = NULL;
  struct node* third = NULL;
  struct node* temp;   
  head  = (struct node*)malloc(sizeof(struct node)); 
  second = (struct node*)malloc(sizeof(struct node));
  third  = (struct node*)malloc(sizeof(struct node));
  
  head->data = 1; 
  head->next = second;   
  
  second->data = 2; 
  second->next = third;  
  
  third->data = 3; 
  third->next = NULL;
   
  temp=head;
  while (temp != NULL)
  {
     printf(" %d ", temp->data);
     temp = temp->next;
  }
  
  return 0;
}
