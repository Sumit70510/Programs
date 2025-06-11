#include<stdio.h>
#include<stdlib.h>
struct node
 {
   int data;
   struct node *next;    
 };

 void traverse(struct node *ptr)
  { 
     
     while(ptr!=NULL)
      {
        printf("\nElement : %d",ptr->data);
        ptr=ptr->next; 
      }
  }

 void insert(struct node *ptr ,int *dat,int n) 
  { 
    struct node *temp;
    for(int i=0;i<n;i++)
     {  
        temp=(struct node *)malloc(sizeof(struct node*));
        temp->data=dat[i];
        temp->next=NULL;
        ptr->next=temp;          
        ptr=temp;
     }
  }
 int main()
  {
   struct node *head;
   head=(struct node *)malloc(sizeof(struct node *));
   int n; 
   printf("ENTER THE NO. OF ELEMENTS : ");
   scanf("%d",&n);
   int *arr;
   arr=(int*)malloc(sizeof(int)*n);
   for(int i=0;i<n;i++)
    {  int t;
       scanf("%d",&t); 
       arr[i]=t; 
    } 
   insert(head,arr,n);
   traverse(head->next); 
   free(arr);
   free(head);
   return 0; 
  }