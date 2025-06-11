#include<iostream>
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

    ~Node()
     { int val=this->data;
       if(this->next!=NULL)
        {
           delete next;
           this->next=NULL; 
        }
       cout<<"\nMemory address Relaesed for "<<val<<endl;
         
     }
 };

void print(Node* &head)
 {  Node *ptr=head;
    while(ptr!=NULL)
     {
       cout<<ptr->data<<"->";
       ptr=ptr->next;  
     }
     cout<<"NULL"<<endl; 
 }

void deletion(int pos,Node*&head,Node*&tail)
  {
    Node*curr=head;
    if(pos==1)
     { if(head==tail)
         {tail=NULL;}
        head=head->next;
     }
    else 
     {
       int cnt=1;
       Node *prev;
       while(cnt<pos&&curr->next!=NULL)
        {
           prev=curr;
           curr=curr->next;
           cnt++;  
        }
        if(tail==curr)
         {tail=prev;}
        prev->next=curr->next;
     } 
    curr->next=NULL; 
    delete curr; 
  }
void insertAttail(Node*&head,Node* &tail,int dat)
 { 
   Node *temp=new Node(dat); 
   if(tail==NULL)
    {
      head=temp;
      tail=temp;
    }
   else
    { 
      tail->next=temp;
      tail=tail->next;
    } 
 }


int main()
{
 int val,n=10;
//  cout<<"ENTER THE NO. OF ELEMENTS : ";
 //cin>>n;  
 Node *head,*tail;
 head=tail=NULL;
 for(int i=1;i<=n;i++)
  { 
    insertAttail(head,tail,i);    
  } 
//  cout<<"First Linked List : ";
//  print(head1);
//  cout<<"Head : "<<head1->data<<endl;
//  cout<<"Tail : "<<tail1->data<<endl;
// //  cout<<"NOW DELETED iTEM : ";
//  deletion(1,head1,tail1);
//  print(head1);
//  cout<<"Head : "<<head1->data<<endl;
//  cout<<"Tail : "<<tail1->data<<endl;
// //  cout<<"NOW DELETED iTEM : ";
//  deletion(n-3,head1,tail1);
//  print(head1);
//  cout<<"Head : "<<head1->data<<endl;
//  cout<<"Tail : "<<tail1->data<<endl;
print(head);
for(int i=1;i<=n;i++)
 {
  deletion(1,head,tail);
  print(head);
  if(head!=NULL)
  {cout<<"Head : "<<head->data<<endl;
   cout<<"Tail : "<<tail->data<<endl;
  }
 }
 return 0;
}