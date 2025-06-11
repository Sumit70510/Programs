#include<iostream>
using namespace std;
class node
{public:
 int n;
 node*next;
 node(int val)
  {n=val;
   next=NULL;}
};
void dletion(node* &head,int val)
 { if(head==NULL)
    {return;}
   if(head->next==NULL)
    {if(head->n!=val)
     {return;}
      node*temp=head;
      head=head->next;
      delete temp;
      return ;
    } 
   node*temp=head; 
   while (temp->next->n!=val&&temp!=NULL&&temp->n!=val)
    {
      temp=temp->next;
    }
    if(temp!=NULL&&temp->next!=NULL)
    {node* todelete=temp;
     temp->next=temp->next->next;
     delete todelete;
    } 
    else
     {cout<<"NOT Found\n";}
 }
void insert(node* &head,int val)
{ node* temp=new node(val);
  if(head==NULL)
   {head=temp;return;}
  node*traverse=head;
  while(traverse->next!=NULL)
   {traverse=traverse->next;}
  traverse->next=temp;
  traverse=temp;
} 
void display(node* head)
{ node*temp=head; 
 while(temp!=NULL)
 {cout<<temp->n<<"->";
  temp=temp->next;}
  cout<<"!!!"<<endl;
}
int main()
{  node *head=NULL;
   insert(head,3);   
   insert(head,6);   
   insert(head,9);   
   insert(head,13);   
   display(head);
   dletion(head,7);
   cout<<"#";
   display(head);
  return 0;  
}