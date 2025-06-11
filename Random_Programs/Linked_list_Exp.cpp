#include<bits/stdc++.h>
using namespace std;

class node
{
private:
 int n;
 node *next;
public:
node()
{ next=NULL;}
 void insert(node* *Head,int item)    
 {  
    while(item--) 
    { node* temp,*input;
      temp= new node;
      input= new node;
      if(Head==NULL)            ]
      {  
         cin>>Head->n;
         Head->next=NULL;
       }
      temp=Head;
      while(temp->next!=NULL)
      {temp=temp->next;}
      
      while(item--)
      {
        cin>>input->n;
        input->next=NULL;
        temp->next=input;
      }   
      
    }

 }  
 void display(node* *Head)
 {
     node *temp;
     while(temp->next!=NULL)
     {
        cout<<"N -> "<<temp->n<<endl;
        temp=temp->next; 
     }
 } 
};



int main()
{
  cout<<"Enter the No. Of Nodes : ";
  int item;
  cin>>item;
  node *head;
  head=new node;
  head->display(head,item);
  head->display(head); 
}