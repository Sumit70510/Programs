#include<bits/stdc++.h>
using namespace std;

class Node
 {
   public :
    int data;
    Node *prev,*next;
   Node(int data)
    {
      this->data=data;
      this->prev=NULL;
      this->next=NULL;  
    } 
    ~Node()
     { 
       cout<<"DELETING THE ELEMENT "<<this->data<<endl;
     } 
 };
 
void print(Node*&head)
 {
    Node*temp=head;
    while(temp!=NULL)
     {
       cout<<temp->data<<"->";
       temp=temp->next; 
     }
     cout<<"NULL"<<endl;
 }

 void insertathead(Node*&head,Node*&tail,int dat)
  {

     Node*temp= new Node(dat);
     if(head==NULL)
      {
        head=temp;
        tail=temp;
      }
     else
      { 
        temp->next=head;
        head->prev=temp;
        head=temp;
      } 
  }
 
void insertattail(Node*&head,Node*&tail,int dat)
 {
    Node *temp=new Node(dat);
    if(tail==NULL)
     {
      tail=temp;
      head=temp; 
     }
    else
     { 
      tail->next=temp;
      temp->prev=tail;
      tail=temp;
     } 
 }

void insertatpos(Node*&head,Node*&tail,int dat,int pos)
 { 
   cout<<"INSERTING "<<dat<<" At POSITION "<<pos<<".\n";
   if(pos==1)
    {
      insertathead(head,tail,dat);  
    }
   else
    {
      int ct=1;
      Node *temp=head;
      while(ct<pos&&temp->next!=NULL)
       {
         ct++;
         temp=temp->next;
       }
       if(temp->next==NULL)
        {insertattail(head,tail,dat);}
       else 
        {
          Node *node1=new Node(dat);
          node1->prev=temp->prev;
          node1->next=temp;
          temp->prev->next=node1;
          temp->prev=node1;
        }  
    } 
 }

 int getlength(Node*&head)
  {
    Node *temp=head;
    int l=0;
    while(temp!=NULL)
     {l++;temp=temp->next;}
    return l; 
  }

void deletion(int pos,Node*&head,Node*&tail)
 { 
   Node*temp=head;
   if(pos==1)
    {
      head=head->next;
      head->prev=NULL;
      temp->next=NULL;
    }
   else
    {
      int ct=1;
       while(ct<pos&&temp->next!=NULL) 
        {
          ct++;
          temp=temp->next;
        }
       if(temp->next==NULL)
        { 
          tail=tail->prev;
          tail->next=NULL;
          temp->prev=NULL;
        } 
       else
        {
          temp->next->prev=temp->prev;
          temp->prev->next=temp->next;
          temp->prev=NULL;
          temp->next=NULL;
        } 
    } 
    delete temp;
 }

 int main()
  { 
    int n=5;
    Node *head,*tail;
    head=NULL;
    tail=NULL;
    for(int i=1;i<=n;i++)
     {
       insertathead(head,tail,i); 
     }
    for(int i=n+1;i<=2*n;i++)
     {
       insertattail(head,tail,i);
     }
    print(head);
    cout<<"Length : "<<getlength(head)<<endl;
    insertatpos(head,tail,17,7);
    print(head);
    insertatpos(head,tail,18,3);
    print(head);
    insertatpos(head,tail,19,5);
    print(head);
    deletion(1,head,tail);
    print(head);
    deletion(10,head,tail);
    print(head);
    deletion(11,head,tail);
    print(head);
    cout<<"tail : "<<tail->data<<endl; 
    return 0;
  }