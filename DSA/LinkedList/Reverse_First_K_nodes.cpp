#include<bits/stdc++.h>
using namespace std;

class Node 
{
   public :
   int data;
   Node *next;
   Node(int data)
    {
     this->data=data;
     this->next=NULL;
    } 
};
    
void print(Node*&head)
 {
    Node *temp=head;
    while(temp!=NULL)
     {
       cout<<temp->data<<"->";
       temp=temp->next; 
     }
     cout<<"NULL"<<endl;
 }

 Node* reverse_k(Node*head,int k)
  {
    if(head==NULL||head->next==NULL)
      {
          return head;
      }
     else 
      {int count=0;
        Node*prev=NULL,*curr=head;
        Node *pos=head;
        while(curr!=NULL&&count<k)
         { 
           curr=head->next; 
           head->next=prev;
           prev=head;
           head=curr; 
           count++;
         } 
        pos->next=reverse_k(curr,k); 
        return prev;
      }
  }

 Node* recursive(Node*&head)
  {
    if(head==NULL||head->next==NULL)
     {
        return head;
     }
    else 
     {
        Node *temphead=recursive(head->next);
        head->next->next=head;
        head->next=NULL;
        return temphead; 
     } 
  }

 void RevRecursive(Node*&head,Node*&curr,Node*&prev)
  {
      if(curr==NULL)
       {head=prev;}
      else
      {
         RevRecursive(head,curr->next,curr);
         curr->next=prev;
      }
     
  }

void reverse(Node*&head,Node*&tail)
 { 
   Node*curr=head,*prev=NULL;
   
 }


void insertion(Node*&head,Node*&tail,int dat)
 {
   Node *temp=new Node(dat); 
   if(head==NULL)
    {
       head=tail=temp; 
    }
   else 
    {
       tail->next=temp;
       tail=temp; 
    } 
 }

int main()
 {
   Node *head=NULL,*tail=NULL;
   for(int i=1;i<=5;i++)
    {
      insertion(head,tail,i);  
    }
    int k;
    print(head);
    // Node*curr=head,*prev=NULL;
    //  k=5;
    // head=reverse_k(head,k);
    // print(head);
    //  k=5;
    // head=reverse_k(head,k);
    // print(head);
    //  k=7;
    // head=reverse_k(head,k);
    // print(head);
    //  k=7;
    // head=reverse_k(head,k);
    // print(head);
     k=3;
    head=reverse_k(head,k);
    print(head);
    //  k=3;
    // head=reverse_k(head,k);
    // print(head);
    return 0; 
 } 